/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:27:57 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/25 21:16:04 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sort_tab(int *tab, t_all *x)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}
	x->max_num = tab[x->size_a - 1];
	return (tab);
}

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
				break;
			}
		}
		temp = temp->next;
	}
	return (l);
}


