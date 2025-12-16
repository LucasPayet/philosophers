/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/16 15:55:45 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long t)
{
	if (t - philo->last_eat > philo->param->time_die)
	{
		philo->param->stop = 1;
		printf("\033[31m%lld %d died\033[0m\n", t, philo->id);
		return (1);
	}
	return (0);
}

int	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
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
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	printf("%lld %d is eating\n", t, philo->id);
	philo->last_eat = t;
	philo->meals++;
	if (philo->meals == philo->param->max_meals)
		philo->param->philo_full++;
	pthread_mutex_unlock(&philo->param->stop_lock);
	my_wait(t + philo->param->time_eat);
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
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	printf("%lld %d is sleeping\n", t, philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	my_wait(t + philo->param->time_sleep);
	return (0);
}

int	think(t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	printf("%lld %d is thinking\n", t, philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	return (0);
}
