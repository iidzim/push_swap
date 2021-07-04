/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/04 19:57:44 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
		{
			if (sorted(&x))
				return (0);
			else
			{
				if (x.size_a <= 5)
					sort_small_stack(&x);
				else
					sort_big_stack(&x);
			}
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
