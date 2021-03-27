/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/27 19:03:05 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void sort3num(t_all *x)
{
    
}

int main(int argc, char **argv)
{
	t_all x;
	
	if (argc >= 2)
	{
		valid_nbr(argc, argv, &x);
		sort(&x);
	}
	else
		print_err();
	return (0);
}