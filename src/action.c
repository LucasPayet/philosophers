/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/01 23:31:21 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long t)
{
	if (t - philo->last_eat > philo->param->time_die)
	{	
		printf("%lld %d died\n", t, philo->id);
		philo->param->death++;
		return (1);
	}
	return (0);
}

void	take_fork(pthread_mutex_t *fork, int id)
{
	pthread_mutex_lock(fork);
	printf("%lld %d has taken a for\nk", ft_gettime(), id);
}

int	eat(t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	if (is_dead(philo, t))
		return (1);
	printf("%lld %d is eating\n", t, philo->id);
	philo->meals++;
	if (philo->meals == philo->param->max_meals)
	{
		philo->param->philo_full++;
		if (philo->param->philo_full == philo->param->nb_philo)
			return (1);
	}
	usleep(philo->param->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	sleep(t_philo *philo)
{
	long long	t;

	t = ft_gettime();
	printf("%lld %d is sleeping\n", t, philo->id);
	usleep(philo->param->time_sleep);
	return (0);
}
