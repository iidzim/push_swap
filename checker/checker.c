/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/16 19:15:05 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int valid_nbr(int argc, char **argv)
{
	int     i;
	int     n;
	int     *dup;

	dup = malloc(sizeof(int) * (argc - 1));
	memset(dup, 'x', (argc - 1) * 4);
	i = 0;
	while (argc > ++i)
	{
		n = overflow(ft_atoi(argv[i]));
		if (is_dup(dup, n, i))
			print_err();
		dup[i-1] = n;
	}
	i = -1;
	while (++i < argc - 1)
		printf("%d | ", dup[i]);
	printf("\n");
	
	fill_list(argc - 1, dup);
	// free(dup);
	return (0);
}

t_list *fill_list(int n, int *dup)
{
	t_list *l;
	t_list *new;
	size_t size_list;

	size_list = n - 1;
	if (!(l = malloc(sizeof(t_list))))
		return (NULL);
	while(size_list >= 0)
	{
		if (!l)
			ft_lstnew(dup[size_list]);
		else
		{
			new = ft_lstnew(dup[size_list]);
			ft_lstadd_front(&l, new);
		}
		size_list--;
	}
	return (l);
}

// random number of either positive or negative numbers without any duplicates
int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		valid_nbr(argc, argv);
		// if (valid_nbr(argc, argv))
		// 	print_err();
		// fill_list(argc, argv);
		//instructions
		// if (valid_instruction(argc, argv))
		//     print_err("msg");
	}
	else
		print_err();
	return (0);
}

// int fill_list(int n, int *dup)
// {
// 	int i;
// 	int *l;

// 	if (!(l = malloc(sizeof(int) * n)))
// 		return (-1);
// 	i = -1;
// 	while(++i < n)
// 		l[i] = dup[n - i];
// 	printf("done");
// 	i = -1;
// 	while(++i < n)
// 		printf("%d\n", l[i]);
// 	return (0);
// }