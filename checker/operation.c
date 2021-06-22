/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/04/18 15:26:59 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void help_swap(t_list **l)
{
    t_list *tmp;
    int temp;
    
    tmp = (*l);
    if (tmp != NULL && tmp->next != NULL)
    {
        temp = tmp->value;
        tmp->value = tmp->next->value;
        tmp->next->value = temp;
    }
}

void swap(t_all *x, char c)
{
    if (c == 'a')
        help_swap(&x->a);
    else if (c == 'b')
        help_swap(&x->b);
    else
    {
        help_swap(&x->a);
        help_swap(&x->b);
    }
}

void push(t_all *x, char c)
{
    t_list *tmp_a, *tmp_b;

    tmp_a = x->a;
    tmp_b = x->b;
    if (c == 'a' && tmp_b != NULL)
    {
        ft_lstadd_val(&x->a, tmp_b->value);
        ft_delete_node(&x->b);
    }
    else if (c == 'b' && tmp_a != NULL)
    {
        ft_lstadd_val(&x->b, tmp_a->value);
        ft_delete_node(&x->a);
    }
}

int exec_op(char *inst, t_all *x)
{
	if (inst[0] == 's')
		swap(x, inst[1]);
	else if (inst[0] == 'r' && inst[2] == '\0')
		rot(x, inst[1]);
	else if (inst[0] == 'r' && inst[2] != '\0')
		reverse_rot(x, inst[2]);
	else
		push(x, inst[1]);
	return 0;
}
