/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/27 16:26:18 by iidzim           ###   ########.fr       */
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

/*
** ra : rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one
*/

void help_rot(t_list **l)
{
    t_list *first;
    t_list *last;

    if ((*l) != NULL && (*l)->next != NULL)
    {
        first = *l;
        last = *l;
        while(last->next != NULL)
            last = last->next;
        *l = first->next;
        first->next = NULL;
        last->next = first;
    }
    else
        return ;
}

void rot(t_all *x, char c)
{
    if (c == 'a')
        help_rot(&x->a);
    else if (c == 'b')
        help_rot(&x->b);
    else
    {
        help_rot(&x->a);
        help_rot(&x->b);
    }
}

/*
** rra : rotate a - shift up all elements of stack a by 1.
**  The last element becomes the first one.
*/

void help_rrot(t_list **l)
{
    t_list *first;
    t_list *last;
    t_list *latest;

    if ((*l) != NULL && (*l)->next != NULL)
    {
        first = *l;
        last = *l;
        while(last->next->next != NULL)
            last = last->next;
        latest = last->next;
        latest->next = first;
        *l = latest;
        last->next = NULL;
    }
}

void reverse_rot(t_all *x, char c)
{
    if (c == 'a')
    {
        printf("a>>>>>>>>\n");
        print_list(x->a);
        help_rrot(&x->a);
        print_list(x->a);
    }
    else if (c == 'b')
    {
        printf("b>>>>>>>>\n");
        print_list(x->b);
        help_rrot(&x->b);
        print_list(x->b);
    }
    else
    {
        printf("a&b>>>>>>>>\n");
        help_rrot(&x->a);
        help_rrot(&x->b);
        print_list(x->a);
        print_list(x->b);
    }
}
