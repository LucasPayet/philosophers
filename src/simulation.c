/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:47:30 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/01 03:20:10 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*foo(void *n)
{
	(void)n;
	printf("start\n");
	usleep(5000000);
	printf("end\n");
	return (NULL);
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = *(t_philo*)arg;
	if (philo->param->death)
		return ;
	think(philo);
	eat(philo);
	sleep(philo);
}

int	start_threads(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->nb_philo)
	{
		if (pthread_create(&p->threads[i], NULL, foo, NULL))
			{
				perror("Fail create thread");
				return 1;
			}
		i++;
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
}

void	simulation(t_param *p)
{
	start_threads(p);
	wait_threads(p);
}
