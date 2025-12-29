/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:47:30 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/29 11:34:24 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_delay(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		my_wait(ft_gettime() + philo->param->time_eat / 5, NULL);
	}
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	smart_delay(philo);
	while (!philo->param->stop && !is_dead(philo, ft_gettime()))
	{
		if (eat(philo))
			return (lose_fork(philo), NULL);
		if (philo_sleep(philo))
			return (lose_fork(philo), NULL);
		if (think(philo))
			return (NULL);
	}
	return (NULL);
}

void	*administer(void *arg)
{
	t_param		*p;
	int			i;
	long long	t;
	t_philo		*philo;

	p = (t_param*)arg;
	i = 0;
	while (1)
	{
		philo = &p->philos[i];
		pthread_mutex_lock(&p->stop_lock);
		t = ft_gettime();
		if (is_dead(philo, t))
			return (pthread_mutex_unlock(&p->stop_lock), NULL);
		if (p->philo_full == p->nb_philo)
			p->stop = 1;
		pthread_mutex_unlock(&p->stop_lock);
		if (i == p->nb_philo - 1)
			i = 0;
		else
			i++;
		usleep(100);
	}
	return (NULL);
}

int	start_threads(t_param *p)
{
	int	i;

	i = 0;
	p->start = ft_gettime();
	while (i < p->nb_philo)
	{
		if (pthread_create(&p->threads[i], NULL, philosophize, &p->philos[i]))
			{
				perror("Fail create thread");
				return 1;
			}
		i++;
	}
	/*if (pthread_create(&p->admin, NULL, administer, p))
	{
		perror("Fail create thread");
		return 1;
	}*/
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
	//pthread_join(p->admin, NULL);
}

void	simulation(t_param *p)
{
	start_threads(p);
	wait_threads(p);
}
