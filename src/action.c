/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/29 18:14:59 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, size_t t)
{
//	printf("\033[0;31m%5lu %lu %d\n\033[0m", t - philo->param->start, philo->last_eat - philo->param->start, philo->id);
	if (t - philo->last_eat > (size_t)philo->param->time_die)
	{
		philo->param->stop = 1;
	//	message("died", philo, t);
		printf("\033[31m%5d %d died\033[0m\n", ft_diff(philo->param->start, t),
			philo->id);
		return (1);
	}
	return (0);
}

int	take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		if (message("has taken a fork", philo, ft_gettime()))
			return (pthread_mutex_unlock(philo->right_fork), 1);
		pthread_mutex_lock(philo->left_fork);
		if (message("has taken a fork", philo, ft_gettime()))
			return (pthread_mutex_unlock(philo->left_fork), 1);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (message("has taken a fork", philo, ft_gettime()))
			return (pthread_mutex_unlock(philo->left_fork), 1);
		pthread_mutex_lock(philo->right_fork);
		if (message("has taken a fork", philo, ft_gettime()))
			return (pthread_mutex_unlock(philo->right_fork), 1);
	}
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
	size_t	t;
	if (take_fork(philo))
		return (1);
	t = ft_gettime();
	if (message("is eating", philo, t))
		return (lose_fork(philo), 1);
	philo->last_eat = t;
	philo->meals++;
/*	if (philo->meals == philo->param->max_meals)
	{
		philo->param->philo_full++;
		if (philo->param->philo_full == philo->param->nb_philo)
		{
			philo->param->stop = 1;
			return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
		}
	}*/
	my_wait(t + philo->param->time_eat);
	//printf("\033[0;31m%lu %d\n\033[0m", ft_gettime() - philo->param->start, philo->id);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	size_t	t;

	t = ft_gettime();
	if (message("is sleeping", philo, t))
		return (1);
	my_wait(t + philo->param->time_sleep);
	return (0);
}

int	think(t_philo *philo)
{
	size_t	t;

//	pthread_mutex_lock(&philo->param->stop_lock);
//	if (philo->param->stop)
//		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	t = ft_gettime();
	if (message("is thinking", philo, t))
		return (1);
//	pthread_mutex_unlock(&philo->param->stop_lock);
	return (0);
}
