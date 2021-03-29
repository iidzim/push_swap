/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:26:09 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/29 10:26:41 by iidzim           ###   ########.fr       */
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
		swap(x, 'a');
	//case2
	if (left > mid && mid > right && left > right)
	{
		swap(x, 'a');
		reverse_rot(x, 'a');
	}
	//case3
	if (left > mid && mid < right && left > right)
		rot(x, 'a');	
	//case4
	if (left < mid && mid > right && left < right)
	{
		swap(x, 'a');
		rot(x, 'a');
	}
	//case5
	if (left < mid && mid > right && left > right)
		reverse_rot(x, 'a');
}
