/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/25 21:18:41 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// t_all	*radix_sort(t_all *x)
// {
// 	t_list	*temp;
// 	int		index;
// 	int		shift;

// 	shift = 0;
// 	temp = x->a;
// 	int i , j;
// 	i = j = 0;
	
	
	// ! x->maxbits = 0;
	// ! while((dup_stack_a[x->size_a - 1] >> x->maxbits) != 0)
	// ! {
	// ! 	printf("maxbits -> %d\n", x->maxbits);
	// ! 	x->maxbits++;
	// ! }
	// ! printf("max_bits >> %d\n", x->maxbits);
	// while ()
	// {
// 		while (temp)
// 		{
// 			// printf("hh\n");
// 			index = temp->index;
// 			if (((index>>shift)&1) == 0)
// 			{
// 				i++;
// 				// printf("index >> %d\n", index>>shift);
// 				push(x, 'b', 1);
// 			}
// 			else //? (index>>shift)&1 == 1
// 			{
// 				j++;
// 				// printf("index >> %d\n", index>>shift);
// 				rot(x, 'a', 1);
// 			}
// 			printf("----> index = %d\n",temp->index);
// 			// printf("re\n");
// 			temp = x->a;
// 			temp = temp->next;
// 		}
// 	// 	shift += 1;
// 	// }
// 	printf("moves >>> %d\n", x->moves);
// 	printf("i >> %d - j >> %d\n", i, j);
// 	write(1, "hola\n", 5);
// 	printf("list a\n");
// 	print_list(x->a);
// 	printf("list b\n");
// 	print_list(x->b);
// 	return (x);
// }


t_all	*radix_sort(t_all *x)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		index;
	int		shift;
	int i = 0;

	shift = 0;
	temp_a = x->a;
	while (shift < x->maxbits)
	{	
		while (temp_a && i <= x->size_a)// && shift <= x->maxbits)
		{
			i += 1;
			index = temp_a->index;
			if (((index>>shift) & 1) != 1)
				push(x, 'b', 1);
			else //* ((index>>shift) & 1) == 1
				rot(x, 'a', 1);
			temp_a = x->a;
			temp_a = temp_a->next;
			printf("list num %d  -  shift = %d\n", i, shift);
			print_list(x->a);
		}
		printf("STACK B\n");
		print_list(x->b);
		temp_b = x->b;
		while (temp_b)
		{
			push(x, 'a', 1);
			temp_b = x->b;
			temp_b = temp_b->next;
		}
		push(x, 'a', 1);
		shift += 1;
	}
	printf("STACK A>>>\n");print_list(x->a);
	printf("STACK B>>>\n");print_list(x->b);
	printf("out\n");
	return (x);
}

void	get_maxbits(t_all *x, int i)
{
	int num;
	t_list *temp;

	temp = x->a;
	num = 0;
	while (temp->next)
	{
		if (temp->value == i)
		{
			num = temp->index;
			break;
		}
		temp = temp->next;
	}
	x->maxbits = 0;
	while ((num>>(x->maxbits))&1)
	{
		
	}
}

int	sort_big_stack(t_all *x)
{
	int *dup_stack_a;

	dup_stack_a = duplicate_sort_stack_a(x, x->size_a);
	//indexation
	x->a = index_stack(x->a, dup_stack_a);
	print_list(x->a);
	get_maxbits(x->a, x->max_num);
	//radix sort
	x = radix_sort(x);
	// print_list(x->a);
	// print_list(x->b);
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

	// int num = 87;
	// int shift = 2;
	// int maxbits = 0;
	// while((num >> (maxbits - 1)) != 0)
	// 	maxbits++;
	// // if (((num>>maxbits)&1) == 1)
	// 	// printf("1\n");
	// // printf("max_bits = %d\n", maxbits);
	// printf("num = %d\n", num>>shift);
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
			/// if the (i + 1)-th bit is 1, leave in stack a
			else pb();
			/// otherwise push to stack b
		}
		/// put into boxes done
		while (!b.empty()) pa(); // while stack b is not empty, do pa
	
		/// connect numbers done
	}
}
*/


//ToDo 
// duplicate stack a -> temp 
// sort stack a 
// indexation -> stack a
// radix sort
