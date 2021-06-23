/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/23 17:13:08 by iidzim           ###   ########.fr       */
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

int operations_3num(t_all *x, int max, int top, int middle)
{
	if (max == top)
		rot(x, 'a', 1);
	if (max == middle)
	{
		swap(x, 'a', 1);
		rot(x, 'a', 1);
	}
	top = x->a->value;
	middle = x->a->next->value;
	if (top > middle)
		swap(x, 'a', 1);
	printf("moves >>> %d\n",x->moves);
	return (0);
}

int	sort_3num(t_all *x)
{
	int top;
	int middle;
	int bottom;
	int max;

	top = x->a->value;
	middle = x->a->next->value;
	bottom = x->a->next->next->value;
	if (top < middle && middle > bottom)
	{
		reverse_rot(x, 'a', 1);
		return (x->moves);
	}
	max = find_max_min(x->a, 1);
	operations_3num(x, max, top, middle);
	return (x->moves);
}

int	push_min_to_stack(t_all *x, int min, char c)
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
	if (cpt < (x->size_a / 2))
	{
		while (cpt-- > 0)
			rot(x, 'a', 1);
	}
	else //?if ((x->size_a - cpt) < (x->size_a / 2))
	{
		while (x->size_a - cpt >= 0)
			reverse_rot(x, 'a', 1);
	}
	push(x, c, 1);
	return (x->moves);	
}

int	sort_5num(t_all *x)
{
	int min1, min2;

	min1 = find_max_min(x->a, 2);
	push_min_to_stack(x, min1, 'b');
	min2 = find_max_min(x->a, 2);
	push_min_to_stack(x, min2, 'b');
	sort_3num(x);
	if (min2 < min1)
		swap(x, 'b', 1);
	push(x, 'a', 1);
	push(x, 'a', 1);
	return (x->moves);
}

void	sort_stack(t_all *x)
{
	printf("size_a -> [%d]\n", x->size_a);
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
