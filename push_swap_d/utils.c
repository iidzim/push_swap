/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 17:30:28 by iidzim           ###   ########.fr       */
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

int	sorted(t_list *l)
{
	t_list	*temp;

	temp = l;
	if (l != NULL && l->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->value > temp->next->value)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
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

// void print_list(t_list *l)
// {
// 	t_list *temp;

// 	temp = l;

// 	printf("*****list******\n");
// 	while(temp)
// 	{
// 		printf("value = %d  -  index = %d\n", temp->value, temp->index);
// 		temp = temp->next;
// 	}
// 	printf("**********\n\n");
// }

//? t_list	*sort_linked_list(t_list *l)
//? {
//? 	t_list	*index;
//? 	t_list	*current;
//? 	int		temp;
//? 	int i = 0;
//?
//? 	current = l;
//? 	index = NULL;
//? 	if (!current)
//? 		return (NULL);
//? 	while (current && current->next)
//? 	{
//? 		i += 1;
//? 		index = current->next;
//? 		while (index)
//? 		{
//? 			if (current->value > index->value)
//? 			{
//? 				temp = current->value;
//? 				current->value = index->value;
//? 				index->value = temp;
//? 			}
//? 			index = index->next;
//? 		}
//? 		current = current->next;
//? 	}
//? 	printf("sorted stack\n");
//? 	print_list(l);
//? 	return (l);
//? }
