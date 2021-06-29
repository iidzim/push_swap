/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 19:24:09 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	while (temp)
	{
		printf("%d - %d\n", temp->value, temp->index);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
		{
			print_list(x.a);
			if (sorted(&x))
				return (0);
			else
			{
				if (x.size_a <= 5)
					sort_small_stack(&x);
				else
					sort_big_stack(&x);
			}
			print_list(x.a);
			ft_freelst(x.a);
			ft_freelst(x.b);
		}
	}
	else if (argc == 1)
		return (0);
	else
		write(2, "Error\n", 6);
	return (0);
}
