/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:49:05 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/24 21:51:56 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void ft_freelst(t_list *inst)
{
	t_list *temp;

	while(inst != NULL)
	{
		temp = inst;
		inst = inst->next;
		free(temp);
	}
	// print_err();
}

void fill_list(int *dup, t_all *x)
{
	int index;

	index = x->size_a;
	while(index > 0)
	{
		if (!x->a)
			x->a = ft_lstnew(dup[index - 1]);
		else
			ft_lstadd_front(&x->a, ft_lstnew(dup[index - 1]));
		index--;
	}
}

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	
	printf("\n*****list******\n");
	while(temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("**********\n\n");
}
