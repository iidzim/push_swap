/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:47:29 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/27 09:53:06 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew(int value)
{
	t_list	*head;

	head = (t_list*)malloc(sizeof(t_list));
	if (head == 0)
		return (NULL);
	head->value = value;
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

int list_size(t_list *l)
{
    int i;

    i = 0;
    while(l != NULL)
    {
        l = l->next++;
        i++;
    }
    return (i);
}

void	ft_freelst(t_list *instructions)
{
	t_list *temp;

	while(instructions != NULL)
	{
		temp = instructions;
		instructions = instructions->next;
		free(temp);
	}
	print_err();
}

void fill_list(int n, int *dup, t_all *x)
{
	int index;

	index = n - 1;
	while(index >= 0)
	{
		if (!x->a)
			x->a = ft_lstnew(dup[index]);
		else
			ft_lstadd_front(&x->a, ft_lstnew(dup[index]));
		index--;
	}
}

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	while(temp)
	{
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void ft_delete_node(t_list **l)
{
	t_list *head;

	if (l && *l)
	{
		head = *l;
		*l = (*l)->next;
		free(head);
	}
}

void ft_lstadd_val(t_list **l, int val)
{
    t_list *node;
    
    if (l && (node = malloc(sizeof(t_list))))
    {
		node->value = val;
		node->next = *l;
		*l = node;
	}
}
