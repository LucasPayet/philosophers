/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:57 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/01 04:37:24 by lupayet          ###   ########.fr       */
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
	t_param			*param;
}	t_philo;

typedef struct	s_parameter
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				death;
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_param;

/* INIT */
void	init_param(t_param *p, char **av);

/* SIMULATION */
void	simulation(t_param *p);
void	think(t_philo);
void	eat(t_philo);
void	spleep(t_philo);

/* UTILS */
int	ft_atoi(char *s);

void	print_s(t_param *s);
void	free_param(t_param *p);
long long	ft_gettime(void);
