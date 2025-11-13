/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:41:12 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/13 15:13:26 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_param *p)
{
	int	i;

	p->threads = malloc(sizeof(pthread_t) * p->nb_philo);
	if (!p->threads)
		printf("malloc err\n");
	p->philo = malloc(sizeof(t_philo) * p->nb_philo + 1);
	if (!p->philo)
		printf("malloc err\n");
	p->philo[p->nb_philo] = NULL;
	i = 0;
	while (i < p->nb_philo)
	{
		p->philo[i]->id = i + 1;
		i++;
	}
}

void	init_table(t_param *p)
{
	p->forks = malloc(sizeof(pthread_mutex_t) * p->nb_philo);

} 

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
	init_pthreads()
}
