/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:48 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/22 15:44:58 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    int             value;
    struct s_list   *next;
}                   t_list;

typedef struct      s_all
{
    t_list          *a;
    t_list          *b;
    int             size_a;
    int             size_b;
}                   t_all;

int ft_strlen(char *s);
int print_err(void);
int ft_isdigit(char c);
long ft_atoi(char *s);
int overflow(long n);
char is_dup(int *dup, int n, int i);

t_list *ft_lstnew(int value);
void ft_lstadd_front(t_list **list, t_list *new);
int list_size(t_list *l);
void ft_freelst(t_list *instructions);
void fill_list(int *dup, t_all *x);
void print_list(t_list *l);
void ft_delete_node(t_list **l);
void ft_lstadd_val(t_list **l, int val);

char *ft_strjoin(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, size_t n);
char *ft_strdup(char *str);
char *ft_substr(char *s, int start, size_t len);
int	ft_return(char **str, char **line);
int	get_next_line(int fd, char **line, int buff_size);

int valid_nbr(int argc, char **argv, t_all *x);
int valid_instruction(char *inst);
int get_next_inst(t_all *x);
int sorted(t_list *l);

int exec_op(char *inst, t_all *x);
void swap(t_all *x, char c);
void push(t_all *x, char c);
void rot(t_all *x, char c);
void reverse_rot(t_all *x, char c);

//////////////
void quick_sort(t_all *x);

#endif