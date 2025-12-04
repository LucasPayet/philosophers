/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/04 15:22:28 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long t)
{
	if (t - philo->last_eat > philo->param->time_die)
	{
		//pthread_mutex_lock(&philo->param->stop_lock);
		philo->param->stop++;
		printf("\033[31m%lld %d died\033[0m\n", t, philo->id);
		//pthread_mutex_unlock(&philo->param->stop_lock);
		return (1);
	}
	return (0);
}

int	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
	{
		pthread_mutex_unlock(&philo->param->stop_lock);
		return (1);
	}
	pthread_mutex_lock(fork);
	printf("%lld %d has taken a fork\n", ft_gettime(), philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	return (0);
}

int	lose_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	eat(t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
	{
		pthread_mutex_unlock(&philo->param->stop_lock);
		return (1);
	} 
	//pthread_mutex_unlock(&philo->param->stop_lock);
	if (is_dead(philo, t))
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	printf("%lld %d is eating\n", t, philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	philo->meals++;
	if (philo->meals == philo->param->max_meals)
	{
		philo->param->philo_full++;
		if (philo->param->philo_full >= philo->param->nb_philo)
			return (1);
	}
	usleep(philo->param->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
	{
		pthread_mutex_unlock(&philo->param->stop_lock);
		return (1);
	}
	printf("%lld %d is sleeping\n", t, philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	usleep(philo->param->time_sleep);
	return (0);
}
