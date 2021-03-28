/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:51:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/28 15:27:00 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void sort3num(t_all *x)
{
    int left, mid, right;
	
	left = x->a->value;
	mid = x->a->next->value;
	right = x->a->next->next->value;
	//case1
	if (left > mid && mid < right && left < right)
		swap(&x->a);
	//case2
	if (left > mid && mid > right && left > right)
	{
		swap(&x->a);
		reverse_rot(x, x);
	}
	//case3
	if (left > mid && mid < right && left > left)
		
	//case4
	if (left < mid && mid > right && left < right)
	{
		
	}
	//case5
	if (left < mid && mid > right && left > left)

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