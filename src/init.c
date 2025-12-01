/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:41:12 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/01 23:22:06 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_param *p)
{
	int	i;

	p->threads = malloc(sizeof(pthread_t) * p->nb_philo);
	if (!p->threads)
		printf("malloc err\n");
	p->philos = malloc(sizeof(t_philo) * p->nb_philo);
	if (!p->philos)
		printf("malloc err\n");
	i = 0;
	while (i < p->nb_philo)
	{
		p->philos[i].id = i + 1;
		p->philo[i].param = p;
		p->philo[i].meals = 0;
		i++;
	}
}

void	init_forks(t_param *p)
{
	int	i;

	i = 0;
	p->forks = malloc(sizeof(pthread_mutex_t) * p->nb_philo);
	while (i < p->nb_philo)
		pthread_mutex_init(&p->forks[i++], NULL);
	i = 0;
	while (i < p->nb_philo - 1)
	{
		p->philos[i].left_fork = &p->forks[i];
		p->philos[i].right_fork = &p->forks[i + 1];
		i++;
	}
	p->philos[i].right_fork = &p->forks[0];
}

void	init_table(t_param *p)
{
	init_philo(p);
} 

void	init_param(t_param *p, char **av)
{
	p->nb_philo = ft_atoi(av[1]);
	p->time_die = ft_atoi(av[2]) * 1e3;
	p->time_eat = ft_atoi(av[3] * 1e3);
	p->time_sleep = ft_atoi(av[4] * 1e3);
	if (av[5])
		p->max_meals = ft_atoi(av[5]);
	else
		p->max_meals = -1;
	p->death = 0;
	p->threads = NULL;
	p->philos = NULL;
	p->forks = NULL;
	init_philo(p);
}
