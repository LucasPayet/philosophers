/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:57 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/28 16:47:06 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_philo
{
	int				id;
	int				last_eat;
	int				ts;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct	s_parameter
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_param;

/* INIT */
void	init_param(t_param *p, char **av);

/* SIMULATION */
void	simulation(t_param *p);

/* UTILS */
int	ft_atoi(char *s);

void	print_s(t_param *s);
void	free_param(t_param *p);
