/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/27 16:24:48 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_to_a(t_all *x)
{
	t_list	*temp_b;

	temp_b = x->b;
	while (temp_b)
	{
		push(x, 'a', 1);
		temp_b = x->b;
		temp_b = temp_b->next;
	}
	push(x, 'a', 1);
}

void	help_swap(t_list **l)
{
	t_list	*tmp;
	int		temp;
	int		index;

	tmp = (*l);
	if (tmp != NULL && tmp->next != NULL)
	{
		temp = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = temp;
		if (tmp->index != 0)
		{
			index = tmp->index;
			tmp->index = tmp->next->index;
			tmp->next->index = index;
		}
	}
}

void	swap(t_all *x, char c, int i)
{
	if (c == 'a')
	{
		help_swap(&x->a);
		if (i == 1)
			write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		help_swap(&x->b);
		if (i == 1)
			write(1, "sb\n", 3);
	}
	else
	{
		help_swap(&x->a);
		help_swap(&x->b);
		if (i == 1)
		{
			write(1, "ss\n", 3);
			x->moves += 1;
		}
	}
	x->moves += 1;
}

void	push(t_all *x, char c, int i)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = x->a;
	tmp_b = x->b;
	if (c == 'a' && tmp_b != NULL)
	{
		ft_lstadd_val(&x->a, tmp_b->value, tmp_b->index);
		ft_delete_node(&x->b);
		if (i == 1)
			write(1, "pa\n", 3);
	}
	else if (c == 'b' && tmp_a != NULL)
	{
		ft_lstadd_val(&x->b, x->a->value, x->a->index);
		ft_delete_node(&x->a);
		if (i == 1)
			write(1, "pb\n", 3);
	}
	x->moves += 1;
}

int	exec_op(char *inst, t_all *x, int i)
{
	if (inst[0] == 's')
		swap(x, inst[1], i);
	else if (inst[0] == 'r' && inst[2] == '\0')
		rot(x, inst[1], i);
	else if (inst[0] == 'r' && inst[2] != '\0')
		reverse_rot(x, inst[2], i);
	else
		push(x, inst[1], i);
	return (0);
}
