/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/22 10:40:28 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int print_err(void)
{
	write(2, "Error\n", 6);
	//!free
	exit(1);
}

int ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long ft_atoi(char *s)
{
	int		signe;
	long	x;

	signe = 1;
	x = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s != '\0' && ft_isdigit(*s))
	{
		x = (x * 10) + ((char)*s - '0');
		s++;
	}
	if (!ft_isdigit(*s) && *s != '\0')
		print_err();
	return (x * signe);
}

int overflow(long n)
{
	if (n > INT32_MAX || n < INT32_MIN)
		print_err();
	return ((int)n);
}

char    is_dup(int *dup, int n, int i)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (dup[j] == n)
			return (1);
	}
	return (0);
}
