/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:35:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/15 17:54:16 by iidzim           ###   ########.fr       */
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

//insert element
int push(t_list *l, int value)
{
    
}