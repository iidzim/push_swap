/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:14:59 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/25 16:22:46 by iidzim           ###   ########.fr       */
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
		while ((--cpt) - x->size_a / 2 > 0)
			reverse_rot(x, 'a', 1);
	}
	push(x, c, 1);
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

int	sort_5num(t_all *x)
{
	int	min1;
	int	min2;

	if (x->size_a == 5)
	{
		min1 = find_max_min(x->a, 2);
		push_min_to_stack(x, min1, 'b');
	}
	min2 = find_max_min(x->a, 2);
	push_min_to_stack(x, min2, 'b');
	sort_3num(x);
	push(x, 'a', 1);
	push(x, 'a', 1);
	return (x->moves);
}
