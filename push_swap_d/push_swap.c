/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 13:28:56 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		valid_nbr(argc, argv, &x);
		if (sorted(x.a))
			printf("OK\n");
		else
		{
			if (x.size_a <= 5)
				sort_small_stack(&x);
			else
				sort_big_stack(&x);
			printf(">>>moves = %d\n", x.moves);
		}
		ft_freelst(x.a);
		ft_freelst(x.b);
		return (0);
	}
	else
		print_err();
	return (0);
}
