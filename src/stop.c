/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:29:48 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/04 14:37:06 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop(t_param *p)
{
	pthread_mutex_lock(&p->stop_lock);
	if (p->stop)
	{
		pthread_mutex_unlock(&p->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(&p->stop_lock);
	return (0);
}
