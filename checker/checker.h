/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:48 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/14 19:25:23 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list{
    int content;
    int *next;
    int *previous;
}               t_list;

#endif