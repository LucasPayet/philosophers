/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:32 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/16 17:14:49 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	my_wait(long long t)
{
	while (ft_gettime() < t)
		usleep(100);
}
*/
void my_wait(long long t)
{
    long long now;

    while ((now = ft_gettime()) < t)
    {
        long long remaining = t - now;

        if (remaining > 1000)
            usleep(remaining / 2);
        else
            usleep(100);
    }
}

