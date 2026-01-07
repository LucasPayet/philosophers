/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:47:30 by lupayet           #+#    #+#             */
/*   Updated: 2026/01/07 23:34:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//my_wait(philo->param->start);
	if (philo->param->nb_philo == 1)
		return(solo_philo(philo), NULL);
	if (!(philo->id % 2))
		my_wait(ft_gettime() + philo->param->time_eat / 2);
	//if (philo->param->nb_philo % 2 && philo->id == philo->param->nb_philo)
	//	my_wait(ft_gettime() + philo->param->time_eat / 2);
	while (1)
	{
		if (eat(philo))
			return (NULL);
		if (philo_sleep(philo))
			return (NULL);
		if (think(philo))
			return (NULL);
		//usleep(500);
	}
	return (NULL);
}

void	*administer(void *arg)
{
	t_param		*p;
	int			i;
	t_philo		*philo;

	p = (t_param *)arg;
	//my_wait(p->start);
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&p->stop_lock);
		//printf("START %d\n", ft_diff(p->start, ft_gettime()));
		while (i < p->nb_philo)
		{
			if (p->stop)
				return (pthread_mutex_unlock(&p->stop_lock), NULL);
			philo = &p->philos[i];
			if (is_dead(philo, ft_gettime()))
				return (pthread_mutex_unlock(&p->stop_lock), NULL);
			if (p->philo_full == p->nb_philo)
				p->stop = 1;
			i++;
		}
		//printf("END %d\n", ft_diff(p->start, ft_gettime()));
		pthread_mutex_unlock(&p->stop_lock);
		usleep(100);
		//my_wait(ft_gettime() + 100);
	}
	return (NULL);
}

int	start_threads(t_param *p)
{
	int	i;

	i = 0;
	//p->start = ft_gettime();
	while (i < p->nb_philo)
	{
		if (pthread_create(&p->threads[i], NULL, philosophize, &p->philos[i]))
		{
			perror("Fail create thread");
			return (1);
		}
		i++;
	}
	if (pthread_create(&p->admin, NULL, administer, p))
	{
		perror("Fail create thread");
		return (1);
	}
	return (0);
}

void	wait_threads(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->nb_philo)
	{
		pthread_join(p->threads[i], NULL);
		i++;
	}
	pthread_join(p->admin, NULL);
}

void	simulation(t_param *p)
{
	start_threads(p);
	wait_threads(p);
}
