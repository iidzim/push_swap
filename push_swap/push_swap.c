/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/23 14:54:26 by iidzim           ###   ########.fr       */
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

int operations_3num(t_all *x, int max)
{
	int top;
	int middle;
	int moves;

	moves = 0;
	top = x->a->value;
	middle = x->a->next->value;
	if (max == top)
	{
		rot(x, 'a');
		moves += 1;
	}
	if (max == middle)
	{
		swap(x, 'a');
		rot(x, 'a');
		moves += 2;
	}
	if (top > middle)
	{
		swap(x, 'a');
		moves += 1;
	}
	return (0);
}

int	sort_3num(t_all *x)
{
	int top;
	int middle;
	int bottom;
	int max;
	int	mov;

	top = x->a->value;
	middle = x->a->next->value;
	bottom = x->a->next->next->value;
	max = find_max_min(x->a, 1);
	mov = operations_3num(x, max);
	return (mov);
}

int	push_min_to_stack(t_all *x, int min, char c)
{
	t_list	*temp;
	int		cpt;
	int		moves;

	cpt = 0;
	moves = 0;
	temp = x->a;
	while (temp)
	{
		if (temp->value == min)
			break ;
		cpt += 1;
		temp = temp->next;
	}
	if (cpt < (x->size_a / 2))
	{
		while (cpt-- > 0)
		{
			rot(x, 'a'); // + print
			moves += 1;
		}
	}
	else //?if ((x->size_a - cpt) < (x->size_a / 2))
	{
		while (x->size_a - cpt >= 0)
		{
			reverse_rot(x, 'a');
			moves += 1;
		}
	}
	push(x, c);
	moves += 1;
	return (moves);	
}

int	sort_5num(t_all *x)
{
	int min1, min2;
	int moves;

	min1 = find_max_min(x->a, 2);
	moves = push_min_to_stack(x, min1, 'b');
	min2 = find_max_min(x->a, 2);
	moves += push_min_to_stack(x, min2, 'b');
	moves += sort_3num(x);
	if (min2 < min1)
	{
		swap(x, 'b');
		moves += 1;
	}
	push(x, 'a');
	push(x, 'a');
	moves += 2;
	return (moves);
}

void	sort_stack(t_all *x)
{
	if (x->size_a == 3)
		sort_3num(x);
	else //if (x->size_a == 5)
	{
		printf(">>>5\n");
		sort_5num(x);
		printf("sorted\n");
	}
	print_list(x->a);
	// else
	// 	sort_100(x);
}

int main(int argc, char **argv)
{
	t_all x;

	printf("agrc == %d\n", argc);
	if (argc >= 2)
	{
		valid_nbr(argc, argv, &x);
		if (sorted(x.a))
			printf("OK\n");
		else
			sort_stack(&x);
		ft_freelst(x.a);
		ft_freelst(x.b);
		return (0);
	}
	else
		print_err();
	return (0);
}

//hint : don't use quick sort for most sorted list
//The time complexity of quicksort is dependent upon the partition and how sorted the list already is.
//check if the list is already sorted
