/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:48 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/17 11:45:48 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list{
    int value;
    struct s_list *next;
}               t_list;

int ft_strlen(char *s);
int print_err(void);
long ft_atoi(char *s);
int ft_isdigit(char c);
int overflow(long n);
// int fill_list(int n, int *dup);
t_list *fill_list(int n, int *dup);
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **list, t_list *new)
;

#endif