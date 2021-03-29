/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/29 14:12:52 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void quick_sort(t_all *x)
{
	int first, last;
	int len_list;

	len_list = list_size(x->a);
	
	
	
}

int main(int argc, char **argv)
{
	t_all x;
	
	if (argc >= 2)
	{
		valid_nbr(argc, argv, &x);
		quick_sort(&x);
		if (sorted(x.a))
			printf("OK\n");
		else
			printf("KO\n");
		ft_freelst(x.a);
		ft_freelst(x.b);
		return (0);
	}
	else
		print_err();
	return (0);
}

//ToDo
//choose a pivot
//