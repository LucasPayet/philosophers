/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:29:48 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 15:05:31 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, size_t t)
{
	if (t - philo->last_eat > (size_t)philo->param->time_die)
	{
		philo->param->stop = 1;
		printf("\033[31m%5d %d died\033[0m\n", ft_diff(philo->param->start, t),
			philo->id);
		return (1);
	}
	return (0);
}
