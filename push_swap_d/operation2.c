/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:38:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 12:43:09 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** ra : rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one
*/

void	help_rot(t_list **l)
{
	t_list	*first;
	t_list	*last;

	if ((*l) != NULL && (*l)->next != NULL)
	{
		first = *l;
		last = *l;
		while (last->next != NULL)
			last = last->next;
		*l = first->next;
		first->next = NULL;
		last->next = first;
	}
	else
		return ;
}

void	rot(t_all *x, char c, int i)
{
	if (c == 'a')
	{
		help_rot(&x->a);
		if (i == 1)
			write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		help_rot(&x->b);
		if (i == 1)
			write(1, "rb\n", 3);
	}
	else
	{
		help_rot(&x->a);
		help_rot(&x->b);
		if (i == 1)
		{
			write(1, "rr\n", 3);
			x->moves += 1;
		}
	}
	x->moves += 1;
}

/*
** rra : rotate a - shift up all elements of stack a by 1.
**  The last element becomes the first one.
*/

void	help_rrot(t_list **l)
{
	t_list	*first;
	t_list	*last;
	t_list	*latest;

	if ((*l) != NULL && (*l)->next != NULL)
	{
		first = *l;
		last = *l;
		while (last->next->next != NULL)
			last = last->next;
		latest = last->next;
		latest->next = first;
		*l = latest;
		last->next = NULL;
	}
}

void	reverse_rot(t_all *x, char c, int i)
{
	if (c == 'a')
	{
		help_rrot(&x->a);
		if (i == 1)
			write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		help_rrot(&x->b);
		if (i == 1)
			write(1, "rrb\n", 4);
	}
	else
	{
		help_rrot(&x->a);
		help_rrot(&x->b);
		if (i == 1)
		{
			write(1, "rrr\n", 4);
			x->moves += 1;
		}
	}
	x->moves += 1;
}
