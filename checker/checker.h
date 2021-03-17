/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:48 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/17 18:56:33 by iidzim           ###   ########.fr       */
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

typedef struct      s_inst_list
{
    char            *inst;
    struct s_inst_list   *next;
}                   t_inst_list;

typedef struct s_all{
    t_list *l;
    
}               t_all;

int ft_strlen(char *s);
int print_err(void);
long ft_atoi(char *s);
int ft_isdigit(char c);
int overflow(long n);
char	*ft_strjoin(char *s1, char *s2);
t_list *fill_list(int n, int *dup);
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **list, t_list *new);
t_inst_list	*ft_inst_new(char *value);
void	ft_inst_addback(t_inst_list **list, t_inst_list *new);
t_inst_list	*ft_inst_new(char *value);
int valid_instruction(char *inst);
int get_instructions(void);
int			ft_strncmp(char *s1, char *s2, size_t n);


#endif