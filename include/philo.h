/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:57 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/03 16:10:11 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <stddef.h>

typedef struct	s_parameter t_param;

typedef struct	s_philo
{
	int				id;
	long long		last_eat;
	int				meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_parameter		*param;
}	t_philo;

struct	s_parameter
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				philo_full;
	pthread_mutex_t	death_lock;
	int				death;
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
};

/* INIT */
void	init_param(t_param *p, char **av);

/* SIMULATION */
void	simulation(t_param *p);
void	think(t_philo *philo);
int		take_fork(pthread_mutex_t *fork, int id);
int 	lose_fork(t_philo *philo);
int		eat(t_philo *philo);
int		philo_sleep(t_philo *philo);

/* UTILS */
int	ft_atoi(char *s);

void	print_s(t_param *s);
void	free_param(t_param *p);
long long	ft_gettime(void);
void	ft_bzero(void *s, size_t n);
