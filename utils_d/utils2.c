/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:49:05 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 12:09:01 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	overflow(long n, int *dup)
{
	if (n > INT32_MAX || n < INT32_MIN)
	{
		write(2, "Error\n", 6);
		free(dup);
		exit(1);
	}
	return ((int)n);
}

char	is_dup(int *dup, int n, int i)
{
	int	j;

	// if (i == 1)
	// 	return (0);
	j = -1;
	while (++j < i)
	{
		if (dup[j] == n)
			return (1);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
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

// int	valid_nbr(int argc, char **argv, t_all *x)
// {
// 	int	i;
// 	int	n;
// 	int	*dup;
// 	dup = malloc(sizeof(int) * (argc));
// 	// i =-1;
// 	// while(++i < argc)
// 	// 	printf("dup[%d]= %d\n", i, dup[i]);
// 	i = 0;
// 	while (argc > ++i)
// 	{
// 		n = overflow(ft_atoi(argv[i]), dup);
// 		if (is_dup(dup, n, i))
// 		{
// 			write(2, "Error\n", 6);
// 			free(dup);
// 			return (1);
// 		}
// 		dup[i - 1] = n;
// 	}
// 	dup[i - 1] = '\0';
// 	x->size_a = argc - 1;
// 	fill_list(dup, x);
// 	free(dup);
// 	return (0);
// }

// int    check_dup(char **argv, char *s, int index)
// {
//     int i;
//     i = 0;
//     while (argv[++i])
//     {
//     	if (strcmp(argv[i], s) && i < index)
//     	// if (!strcmp(argv[i], s) && i < index)
// 		{
// 			printf("duplicate\n");
//             return (0);
// 		}
//     }
//     return (1);
// }

int    check_dup(int *dup, int argc)
{
    int i;
	int j;

    i = -1;
    while (++i < argc - 1)
    {
		j = -1;
		while (++j < argc - 1)
		{
    		if (dup[i] == dup[j] && i != j)
			{
				// printf("i = %d - j = %d\n", i, j);
				// printf("dup[i] = %d\n", dup[i]);
				printf("duplicate\n");
        	    return (0);
			}
		}
    }
    return (1);
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
		if (ft_strlen(argv[i + 1]) > 11)
		{
			write(2, "Error\n", 6);
			free(dup);
			return (1);
		}
		n = overflow(ft_atoi(argv[i + 1]), dup);
		dup[i] = n;
	}
	if (!check_dup(dup, argc))
	{
		write(2, "Error\n", 6);
		free(dup);
		return (1);
	}
	x->size_a = argc - 1;
	fill_list(dup, x);
	free(dup);
	return (0);
}
