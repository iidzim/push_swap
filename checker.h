/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:10:56 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 13:21:03 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		ft_strlen(char *s);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(char **line);
char	**ft_split(char *s, char c);
int		valid_instruction(char *inst);

#endif