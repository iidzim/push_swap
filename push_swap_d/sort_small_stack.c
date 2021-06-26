/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:14:59 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 16:48:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			rot(x, c, 1);
	}
	else
	{
		while ((--cpt) - x->size_a / 2 > 0)
			reverse_rot(x, c, 1);
	}
	push(x, 'b', 1);
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
	return (x->moves);
}

int	sort_3num(t_all *x)
{
	int	top;
	int	middle;
	int	max;

	top = x->a->value;
	middle = x->a->next->value;
	max = find_max_min(x->a, 1);
	return (operations_3num(x, max, top, middle));
}

int	sort_5num(t_all *x)
{
	int	min1;
	int	min2;

	print_list(x->a);
	// printf("STACK_B\n");print_list(x->b);
	if (x->size_a == 5)
	{
		min1 = find_max_min(x->a, 2);
		push_min_to_stack(x, min1, 'a');
	}
	min2 = find_max_min(x->a, 2);
	push_min_to_stack(x, min2, 'a');

	x->moves +=  sort_3num(x);
	push(x, 'a', 1);
	push(x, 'a', 1);
	// printf("print moves = %d\n", x->moves);
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
		x->moves = sort_3num(x);
	else
		x->moves = sort_5num(x);
}
