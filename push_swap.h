/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:48 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/27 13:20:37 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "checker.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct s_all
{
	t_list			*a;
	t_list			*b;
	int				size_a;
	int				size_b;
	int				moves;
	int				maxbits;
	int				max_num;
}				t_all;

/*
** list.c
*/
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **list, t_list *new);
void	ft_delete_node(t_list **l);
void	ft_lstadd_val(t_list **l, int val, int index);
void	ft_freelst(t_list *instructions);

/*
** utils.c
*/
void	fill_list(int *dup, t_all *x);
int		sorted(t_list *l);
int		find_max_min(t_list *a, int i);
int		*sort_tab(int *tab, t_all *x);
void	print_list(t_list *l);

/*
** utils2.c
*/
int		valid_nbr(int argc, char **argv, t_all *x);

/*
** operation.c - operation2.c
*/
int		exec_op(char *inst, t_all *x, int i);
void	swap(t_all *x, char c, int i);
void	push(t_all *x, char c, int i);
void	rot(t_all *x, char c, int i);
void	reverse_rot(t_all *x, char c, int i);
void	push_b_to_a(t_all *x);

/*
** sort_small_stack.c
*/
void	sort_small_stack(t_all *x);

/*
** sort_big_stack.c
*/
void	sort_big_stack(t_all *x);

#endif