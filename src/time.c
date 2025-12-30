/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:32 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 16:28:11 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_wait(size_t t)
{
	while (ft_gettime() < t)
		usleep(100);
}

size_t	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
/*
void my_wait(size_t t)
{
	size_t now;
	size_t remaining;

	while ((now = ft_gettime()) < t)
	{
		remaining = t - now;
		if (remaining > 1000)
			usleep(remaining / 2);
		else
			usleep(100);
	}
}*/
