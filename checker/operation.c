/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/20 18:47:55 by iidzim           ###   ########.fr       */
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

// + free the first node of stack a or b
void push(t_all *x, char c)
{
    t_list *tmp_a, *tmp_b;

    tmp_a = x->a;
    tmp_b = x->b;
    if (c == 'a')
    {
        ft_lstadd_front(&tmp_a, tmp_b);
        ft_delete_node(&tmp_b);
    }
    else if (c == 'b')
    {
        printf("a : ");print_list(x->a);
        printf("b : ");print_list(x->b);
        ft_lstadd_front(&x->b, tmp_a);
        printf(">>>>>>>>>\n");
        printf("a : ");print_list(x->a);
        printf("b : ");print_list(x->b);
        ft_delete_node(&tmp_a);
    }
}

// ra : rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one
// void rot(t_all *x, char c)
// {
    
// }

// void reverse_rot(t_all *x, char c)
// {
    
// }
