/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:01:08 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/18 15:54:19 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_s(t_param *p)
{
//	int	i;
	printf("PARAM :\n");
    printf("%-15s | %d\n", "philo", p->nb_philo);
    printf("%-15s | %d\n", "time to die", p->time_die);
    printf("%-15s | %d\n", "time to eat", p->time_eat);
    printf("%-15s | %d\n", "time to sleep", p->time_sleep);
    printf("%-15s | %d\n", "max meals", p->max_meals);
	/*i = 0;
	while (p->philo[i])
	{
		printf("id");
	}*/
}
