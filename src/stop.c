/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:29:48 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/31 15:18:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, size_t t)
{
	if (t - philo->last_eat > (size_t)philo->param->time_die)
	{
		philo->param->stop = 1;
		printf("%d %d died\n", ft_diff(philo->param->start, t),
			philo->id);
		return (1);
	}
	return (0);
}
