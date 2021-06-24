/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/24 21:57:59 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_min(t_list *a, int i)
{
	t_list	*temp;
	int		value;

	temp = a;
	value = temp->value;
	while (temp)
	{
		if ((value < temp->value && i == 1) || (value > temp->value && i == 2))
			value = temp->value;
		temp = temp->next;
	}
	return (value);
}

int	operations_3num(t_all *x, int max, int top, int middle)
{
	if (max == top)
		rot(x, 'a', 1);
	if (max == middle)
		reverse_rot(x, 'a', 1);
	top = x->a->value;
	middle = x->a->next->value;
	if (top > middle)
		swap(x, 'a', 1);
	return (0);
}

int	sort_3num(t_all *x)
{
	int	top;
	int	middle;
	int	bottom;
	int	max;

	top = x->a->value;
	middle = x->a->next->value;
	bottom = x->a->next->next->value;
	max = find_max_min(x->a, 1);
	operations_3num(x, max, top, middle);
	return (x->moves);
}

void	push_min_to_stack(t_all *x, int min, char c)
{
	t_list	*temp;
	int		cpt;

	cpt = 0;
	temp = x->a;
	while (temp)
	{
		if (temp->value == min)
			break ;
		cpt += 1;
		temp = temp->next;
	}
	if (cpt <= (x->size_a / 2))
	{
		while (cpt-- > 0)
			rot(x, 'a', 1);
	}
	else
	{
		while ((--cpt) - x->size_a / 2> 0)
			reverse_rot(x, 'a', 1);
	}
	push(x, c, 1);
}

int	sort_5num(t_all *x)
{
	int	min1;
	int	min2;

	if (x->size_a == 5)
	{
		min1 = find_max_min(x->a, 2);
		push_min_to_stack(x, min1, 'b');
	}
	min2 = find_max_min(x->a, 2);;
	push_min_to_stack(x, min2, 'b');
	sort_3num(x);
	push(x, 'a', 1);
	push(x, 'a', 1);
	return (x->moves);
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

t_list	*sort_linked_list(t_list *l)
{
	t_list	*index;
	t_list	*current;
	int		temp;

	current = l;
	index = NULL;
	if (!current)
		return (NULL);
	else
	{
		while (current)
		{
			index = current->next;
			while (index)
			{
				if (current->value > index->value)
				{
					temp = current->value;
					current->value = index->value;
					index->value = temp;
					printf("current>>>>%d\n", current->value);
					printf("index>>>>%d\n", index->value);
				}
				index = index->next;
			}
			current = current->next;
		}
	}
	if (!current)
		printf("empty linkedd list\n");
	// print_list(current);
	return (current);
}

t_list *index_stack(t_list *l, int *dup)
{
	t_list	*temp;
	int	value;
	int pos;
	int	i;

	if (!l)
		return (NULL);
	i = -1;
	while(dup[++i])
	{
		pos = 0;
		temp = l;
		value = temp->value;
		while(temp)
		{
			if (value != dup[i])
			{
				pos++;
				temp = temp->next;
			}
			temp->value = pos;
		}
	}
	return (temp);
}



int	sort_big_stack(t_all *x)
{
	int *dup_stack_a;
	t_list *temp;
	int	i;

	// dup stacck a 
	dup_stack_a = malloc(sizeof(int) * (x->size_a + 1));
	if (!dup_stack_a)
		return (0);
	temp = x->a;
	i = 0;
	while (temp)
	{
		dup_stack_a[i++] = temp->value;
		temp = temp->next;
	}
	dup_stack_a[i] = '\0';
	
	//sort stack a
	x->a = sort_linked_list(x->a);
	print_list(x->a);
	
	//indexation
	x->a = index_stack(x->a, dup_stack_a);
	print_list(x->a);

	//radix sort
	
	
	return (0);
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
			printf("sorted\n");
			print_list(x.a);
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
