/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/19 00:50:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char    is_dup(int *dup, int n, int i)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (dup[j] == n)
			return (1);
	}
	return (0);
}

int valid_nbr(int argc, char **argv, t_all *x)
{
	int     i;
	int     n;
	int     *dup;

	dup = malloc(sizeof(int) * (argc - 1));
	memset(dup, 'x', (argc - 1) * 4);
	i = 0;
	while (argc > ++i)
	{
		n = overflow(ft_atoi(argv[i]));
		if (is_dup(dup, n, i))
			print_err();
		dup[i-1] = n;
	}
	fill_list(argc - 1, dup, x);
	print_list(x->a);
	free(dup);
	return (0);
}

void fill_list(int n, int *dup, t_all *x)
{
	int index;

	index = n - 1;
	while(index >= 0)
	{
		if (!x->a)
			x->a = ft_lstnew(dup[index]);
		else
			ft_lstadd_front(&x->a, ft_lstnew(dup[index]));
		index--;
	}
}

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	while(temp)
	{
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int valid_instruction(char *inst)
{
	int		i;
	int		j;
	int		len;
	char	*tab[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = -1;
	while (++i < 11)
	{
		len = ft_strlen(inst);
		j = 0;
		if (len > 3)
			return 0;
		else
		{
			if (!ft_strncmp(inst, tab[i], ft_strlen(inst)))
				return 1;
		}
	}
	return 0;
}

int exec_op(char *inst, t_all *x)
{
	printf("in\n");
	if (inst[0] == 's')
	{
		printf("before\n");
		// print_list(x->a);
		swap(x, inst[1]);
		printf("after\n");
		// print_list(x->a);
	}
	// else if (inst[0] == 'r' && inst[2] == '\0')
	// 	rot(x, inst[1]);
	// else if (inst[0] == 'r' && inst[2] != '\0')
	// 	reverse_rot(x, inst[2]);
	else
		push(x, inst[1]);
	return 0;
}

int get_next_inst(t_all *x)
{
	char *line;

	while (get_next_line(0, &line, 4))
	{
		if (strcmp(&line[0], "") == 0)
		{
			// if sorted ->ok else ko
			break;
		}
		if (valid_instruction(line))
			exec_op(line, x);
		else
			print_err();
		free(line);
	}
	return 0;
}


// random number of either positive or negative numbers without any duplicates
int main(int argc, char **argv)
{
	t_all x;
	
	if (argc >= 2)
	{
		valid_nbr(argc, argv, &x);
		get_next_inst(&x);
	}
	else
		print_err();
	return (0);
}
