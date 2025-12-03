/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:47:30 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/03 16:15:39 by lupayet          ###   ########.fr       */
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

void	smart_delay(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		if (philo->param->nb_philo % 2)
			usleep(philo->param->time_eat / 2);
	}
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	smart_delay(philo);
	while (!philo->param->death)
	{
		if (philo->param->death | take_fork(philo->left_fork, philo->id))
			return (lose_fork(philo), NULL);
		if (philo->param->death | take_fork(philo->right_fork, philo->id))
			return (lose_fork(philo), NULL);
		if (philo->param->death | eat(philo))
			return (lose_fork(philo), NULL);
		if (philo->param->death |  philo_sleep(philo))
			return (lose_fork(philo), NULL);
		if (philo->param->death)
			printf("\033[34m%lld %d is thinking\n\033[0m", ft_gettime(), philo->id);
	}
	return (NULL);
}

int	start_threads(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->nb_philo)
	{
		if (pthread_create(&p->threads[i], NULL, philosophize, &p->philos[i]))
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
