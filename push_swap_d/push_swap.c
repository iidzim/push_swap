/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 17:31:12 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_all	x;

	x.b = NULL;
	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
		{	
			if (sorted(x.a))
				printf("OK\n");
			else
			{
				if (x.size_a <= 5)
					sort_small_stack(&x);
				else
					sort_big_stack(&x);
			}
			if (sorted(x.a))
				printf("OK\n");
			ft_freelst(x.a);
			ft_freelst(x.b);
		}
	}
	else
		write(2, "Error\n", 6);
	system("leaks push_swap");
	return (0);
}
