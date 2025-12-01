/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:22:03 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/01 04:43:09 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	printf("%lld %d is eating", ft_gettime(), philo->id);
	usleep(philo->param->time_eat);
}

void	sleep(t_philo *philo)
{
	printf("%lld %d is sleeping", ft_gettime(), philo->id);
	usleep(philo->param->time_sleep);
}
