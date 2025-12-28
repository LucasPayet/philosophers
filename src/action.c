/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/29 00:49:09 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long t)
{
	if (t - philo->last_eat > philo->param->time_die)
	{
		philo->param->stop = 1;
		printf("\033[31m%d %d died\033[0m\n", diff(philo->param->start, t),
			philo->id);
		return (1);
	}
	return (0);
}

void	take_fork(t_philo *philo, t_param *param)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%d %d has taken a fork\n", diff(param->start, ft_gettime()), philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("%d %d has taken a fork\n", diff(param->start, ft_gettime()), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%d %d has taken a fork\n", diff(param->start, ft_gettime()), philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%d %d has taken a fork\n", diff(param->start, ft_gettime()), philo->id);
	}
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
	take_fork(philo, philo->param);
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	t = ft_gettime();
	printf("%d %d is eating\n", diff(philo->param->start, t), philo->id);
	philo->last_eat = t;
	philo->meals++;
	if (philo->meals == philo->param->max_meals)
	{
		philo->param->philo_full++;
		if (philo->param->philo_full == philo->param->nb_philo)
		{
			philo->param->stop = 1;
			return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
		}
	}
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
	printf("%d %d is sleeping\n", diff(philo->param->start, t), philo->id);
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
	printf("%d %d is thinking\n", diff(philo->param->start, t), philo->id);
	pthread_mutex_unlock(&philo->param->stop_lock);
	return (0);
}
