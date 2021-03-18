/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/19 00:49:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void help_swap(t_list **l)
{
    t_list *temp;

    if (list_size(*l) > 1)
    {
        temp = *l;
        *l = (*l)->next;
        (*l)->next = temp;
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
    // pa : take the first element at the top of b and put it at the top of a
    if (c == 'a' && x->b)
        ft_lstadd_front(x->a, x->b);
    else if (c == 'b' && x->a)
        ft_lstadd_front(x->b, x->a);
}

// ra : rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one
// void rot(t_all *x, char c)
// {
    
// }

// void reverse_rot(t_all *x, char c)
// {
    
// }
