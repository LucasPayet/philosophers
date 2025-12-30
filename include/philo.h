/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:57 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 17:44:25 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stddef.h>

typedef struct s_parameter	t_param;

typedef struct s_philo
{
	int					id;
	size_t				last_eat;
	int					meals;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_parameter	*param;
}	t_philo;

struct	s_parameter
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	size_t			start;
	int				max_meals;
	int				philo_full;
	pthread_mutex_t	stop_lock;
	int				stop;
	pthread_t		*threads;
	pthread_t		admin;
	t_philo			*philos;
	pthread_mutex_t	*forks;
};

/* INIT */
int		init_param(t_param *p, char **av);

/* SIMULATION */
void	simulation(t_param *p);
int		check_stop(t_param *p);
int		is_dead(t_philo *philo, size_t t);
void	set_stop(t_param *p);
int		think(t_philo *philo);
int		lose_fork(t_philo *philo);
int		eat(t_philo *philo);
int		philo_sleep(t_philo *philo);

void	my_wait(size_t t);

/* UTILS */
long	ft_atol(char *s);
int		safe_atoi(char *s);
void	print_s(t_param *s);
void	free_param(t_param *p);
void	destroy_mutex(t_param *p);
size_t	ft_gettime(void);
int		ft_diff(size_t min, size_t max);

/* MESSAGE */
int		message(char *msg, t_philo *philo, size_t t);

#endif
