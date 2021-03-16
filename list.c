/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:35:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/16 16:57:34 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct      s_list{
    int             *value;
	struct s_list	*next;
	struct s_list	*prev;
}                   t_list;

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

//insert if the list is empty

t_list *create(void *val)
{
    t_list *l;

    if (!(l = malloc(sizeof(t_list))))
        return (NULL);
    l->value = val;
    l->prev = NULL;
    l->next = NULL;
    return (l);
}

// insert an element to the top of stack
void *push(t_list *l, int value)
{
    t_list *temp;
    
    temp = malloc(sizeof(t_list));
    if (value)
    {
        temp->value = value;
        temp->next = l->prev;
        temp->prev = NULL;
    }
}

// remove the element from the top of stack
