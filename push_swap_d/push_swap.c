/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/25 16:40:02 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_big_stack(t_all *x)
{
	int *dup_stack_a;

	dup_stack_a = duplicate_sort_stack_a(x->a, x->size_a);
	//indexation
	x->a = index_stack(x->a, dup_stack_a);
	print_list(x->a);

	//radix sort
	
	return (0);
}

void	sort_small_stack(t_all *x)
{
	if (x->size_a == 2)
	{
		if (x->a->value > x->a->next->value)
			swap(x, 'a', 1);
	}
	else if (x->size_a == 3)
		sort_3num(x);
	else
		x->moves = sort_5num(x);
	printf("moves >>>>>>%d\n", x->moves);
}

int	main(int argc, char **argv)
{
	t_all	x;

	// int num = 3;
	// int maxbits = 0;
	// while((num >> (maxbits - 1)) != 0)
	// 	maxbits++;
	// if (((num>>maxbits)&1) == 1)
	// 	printf("1\n");
	// printf("max_bits = %d\n", maxbits);
	// // printf("num = %d\n", num>>3);
	// return (0);

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
			// printf("sorted\n");
			// print_list(x.a);
		}
		ft_freelst(x.a);
		ft_freelst(x.b);
		return (0);
	}
	else
		print_err();
	return (0);
}

//hint : don't use quick sort for most sorted list
//The time complexity of quicksort is dependent upon the partition and
//how sorted the list already is.
//check if the list is already sorted


/*
{
	int size = a.size();
	int max_num = size - 1; // the biggest number in a is stack_size - 1
	int max_bits = 0; // how many bits for max_num 
	while ((max_num >> max_bits) != 0) ++max_bits;
	for (int i = 0 ; i < max_bits ; ++i) // repeat for max_bits times
	{
		for(int j = 0 ; j < size ; ++j)
		{
			int num = a.top(); // top number of A
			if ((num >> i)&1 == 1) ra(); 
			///? if the (i + 1)-th bit is 1, leave in stack a
			else pb();
			///? otherwise push to stack b
		}
		///? put into boxes done
		while (!b.empty()) pa(); // while stack b is not empty, do pa
	
		///? connect numbers done
	}
}
*/


//ToDo 
// duplicate stack a -> temp 
// sort stack a 
// indexation -> stack a
// radix sort
