/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/04 16:22:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_list(int *dup, t_all *x)
{
	int	index;

	index = x->size_a;
	while (index > 0)
	{
		if (!x->a)
			x->a = ft_lstnew(dup[index - 1]);
		else
			ft_lstadd_front(&x->a, ft_lstnew(dup[index - 1]));
		index--;
	}
}

int	sorted(t_all *x)
{
	t_list	*temp;

	if (x->b)
		return (0);
	temp = x->a;
	if (temp != NULL && temp->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->value > temp->next->value)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	if (temp != NULL && temp->next == NULL)
		return (1);
	return (0);
}

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

int	*sort_tab(int *tab, t_all *x)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < x->size_a)
	{
		j = i;
		while (++j < x->size_a)
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

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
