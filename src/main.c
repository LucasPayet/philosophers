/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:39:08 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/13 17:20:35 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printparam(t_param *p)
{
	printf("%d\n%d\n%d\n%d\n%d\n", p->nb_philo, p->time_die, p->time_eat,
			p->time_sleep, p->max_eat);
}

int	main(int ac, char **av)
{
	t_param	param;

	if (ac < 5 || ac > 6)
		return (1);
	
	init_param(&param, av);
	print_s(&param);
	free_param(&param);
	return (0);
}
