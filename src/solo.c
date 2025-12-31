/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 13:54:52 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/31 16:02:37 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	solo_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	message("has taken a fork", philo, ft_gettime());
	pthread_mutex_unlock(philo->right_fork);
}
