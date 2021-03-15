/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/15 17:17:34 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int print_err(char *s)
{
    write(2, "Error\n", 8);
    write(2, s, ft_strlen(s));
    exit(1);
}

int	ft_atoi(char *s)
{
	int n;
    int signe;

	n = 0;
    signe = 1;
	if (*s == '-')
    {
        signe = -1;
        s++;
    }
	while (s != '\0' && ft_isdigit(s))
	{
		n = n * 10 + (s - 48);
	    s++;
	}
	if (s == '\0')
		return (n);
	if (!ft_isdigit(s))
		print_err("digit");
	return (n);
}
