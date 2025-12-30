/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:39:08 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 17:17:20 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printparam(t_param *p)
{
	printf("%d\n%d\n%d\n%d\n%d\n", p->nb_philo, p->time_die, p->time_eat,
		p->time_sleep, p->max_meals);
}

int	main(int ac, char **av)
{
	t_param	param;

	if (ac < 5 || ac > 6)
		return (1);
	if (!init_param(&param, av))
		return (1);
	print_s(&param);
	simulation(&param);
	destroy_mutex(&param);
	free_param(&param);
	return (0);
}
