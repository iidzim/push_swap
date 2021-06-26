/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:47:29 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 16:44:43 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == 0)
		return (NULL);
	head->value = value;
	head->index = 0;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}

void	ft_delete_node(t_list **l)
{
	t_list	*head;

	if (l && *l)
	{
		head = *l;
		*l = (*l)->next;
		free(head);
	}
}

void	ft_lstadd_val(t_list **l, int val, int index)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (l && node)
	{
		node->value = val;
		node->index = index;
		node->next = *l;
		*l = node;
		
	}
}

void	ft_freelst(t_list *inst)
{
	t_list	*temp;

	while (inst != NULL)
	{
		temp = inst;
		inst = inst->next;
		free(temp);
	}
}
