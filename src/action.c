/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 15:08:52 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (philo->meals == philo->param->max_meals)
	{
		pthread_mutex_lock(&philo->param->stop_lock);
		philo->param->philo_full++;
		if (philo->param->philo_full == philo->param->nb_philo)
		{
			philo->param->stop = 1;
			return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
		}
		pthread_mutex_unlock(&philo->param->stop_lock);
	}
	my_wait(t + philo->param->time_eat);
	lose_fork(philo);
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

	t = ft_gettime();
	if (message("is thinking", philo, t))
		return (1);
	return (0);
}
