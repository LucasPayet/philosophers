/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:36:49 by lupayet           #+#    #+#             */
/*   Updated: 2025/12/30 17:39:27 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(char *s)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nb = nb * 10 + *s - 48;
		s++;
	}
	return (nb * sign);
}

int	safe_atoi(char *s)
{
	long	nb;

	if (ft_strlen(s) > 11)
	{
		return (-1);
	}
	nb = ft_atol(s);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	else
		return ((int)nb);
}
