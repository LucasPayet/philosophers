/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:41:12 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/08 22:20:14 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_param(t_param *p, char **av)
{
	p->nb_philo = ft_atoi(av[1]);
	p->time_die = ft_atoi(av[2]);
	p->time_eat = ft_atoi(av[3]);
	p->time_sleep = ft_atoi(av[4]);
	if (av[5])
		p->max_eat = ft_atoi(av[5]);
	else
		p->max_eat = -1;
}
