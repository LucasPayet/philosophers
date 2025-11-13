/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:43:12 by lupayet           #+#    #+#             */
/*   Updated: 2025/11/13 17:21:02 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_param(t_param *p)
{
	if (p->threads)
		free(p->threads);
	if (p->philos)
		free(p->philos);
	if (p->forks)
		free(p->forks);
}
