/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:49:05 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/04 19:48:20 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	overflow(long n, int *dup)
{
	if (n > INT32_MAX || n < INT32_MIN)
	{
		write(2, "Error\n", 6);
		free(dup);
		system("leaks push_swap");
		exit(1);
	}
	return ((int)n);
}

long	ft_atoi(char *s)
{
	int		signe;
	long	x;

	signe = 1;
	x = 0;
	if (*s == '-' || *s == '+')
	{
		if (ft_strlen(s) == 1)
			return (2147483648);
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
		return (2147483648);
	return (x * signe);
}

int	check_dup(int *dup, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - 1)
		{
			if (dup[i] == dup[j] && i != j)
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
	}
	return (1);
}

int	check_double_overloaded(char **argv, int i, int *dup)
{
	if (ft_strlen(argv[i + 1]) > 11)
	{
		write(2, "Error\n", 6);
		free(dup);
		return (1);
	}
	return (0);
}

int	valid_nbr(int argc, char **argv, t_all *x)
{
	int	i;
	int	n;
	int	*dup;

	dup = malloc(sizeof(int) * (argc - 1));
	i = -1;
	while (argc - 1 > ++i)
	{
		if (check_double_overloaded(argv, i, dup))
			return (1);
		n = overflow(ft_atoi(argv[i + 1]), dup);
		dup[i] = n;
	}
	if (!check_dup(dup, argc))
	{
		free(dup);
		return (1);
	}
	x->size_a = argc - 1;
	fill_list(dup, x);
	free(dup);
	return (0);
}
