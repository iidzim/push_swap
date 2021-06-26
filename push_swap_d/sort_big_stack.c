/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:27:57 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 16:54:46 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*duplicate_sort_stack_a(t_all *x, int size)
{
	int		*dup_stack_a;
	t_list	*temp;
	int		i;

	dup_stack_a = malloc(sizeof(int) * (size + 1));
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
	return (sort_tab(dup_stack_a, x));
}

t_list	*index_stack(t_list *l, int *tab)
{
	t_list	*temp;
	int		pos;
	int		value;

	if (!l)
		return (NULL);
	temp = l;
	while (temp)
	{
		pos = -1;
		value = temp->value;
		while (tab[++pos])
		{
			if (value == tab[pos])
			{
				temp->index = pos + 1;
				break ;
			}
		}
		temp = temp->next;
	}
	return (l);
}

void	get_maxbits(t_all *x, int i)
{
	int		num;
	t_list	*temp;

	temp = x->a;
	num = 0;
	while (temp->next)
	{
		if (temp->value == i)
		{
			num = temp->index;
			break ;
		}
		temp = temp->next;
	}
	x->maxbits = 1;
	while (num >> (x->maxbits) != 0)
		x->maxbits++;
}

t_all	*radix_sort(t_all *x)
{
	t_list	*temp_a;
	int		index;
	int		shift;
	int		i;

	i = 0;
	shift = 0;
	while (shift < x->maxbits)
	{
		temp_a = x->a;
		i = 0;
		while (temp_a && i < x->size_a)
		{
			i += 1;
			index = temp_a->index;
			if (((index >> shift) & 1) != 1)
				push(x, 'b', 1);
			else
				rot(x, 'a', 1);
			temp_a = x->a;
		}
		push_b_to_a(x);
		shift += 1;
	}
	return (x);
}

void	sort_big_stack(t_all *x)
{
	int	*dup_stack_a;

	dup_stack_a = duplicate_sort_stack_a(x, x->size_a);
	x->a = index_stack(x->a, dup_stack_a);
	free(dup_stack_a);
	get_maxbits(x, x->max_num);
	x = radix_sort(x);
}
