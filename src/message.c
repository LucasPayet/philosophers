/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:22:22 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/29 18:13:48 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message(char *msg, t_philo *philo, size_t t)
{
	pthread_mutex_lock(&philo->param->stop_lock);
	if (philo->param->stop)
		return (pthread_mutex_unlock(&philo->param->stop_lock), 1);
	printf("%5d %d %s\n", ft_diff(philo->param->start, t), philo->id, msg);
	pthread_mutex_unlock(&philo->param->stop_lock);
	return (0);
}
