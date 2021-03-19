/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/19 19:10:52 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	free(dup);
	return (0);
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
	if (inst[0] == 's')
		swap(x, inst[1]);
	// else if (inst[0] == 'r' && inst[2] == '\0')
	// 	rot(x, inst[1]);
	// else if (inst[0] == 'r' && inst[2] != '\0')
	// 	reverse_rot(x, inst[2]);
	// else
	// {
	// 	print_list(x->a);
	// 	printf("take the first element at the top of a and put it at the top of b\n");
	// 	push(x, inst[1]);
	// 	printf("stack b : ");
	// 	print_list(x->b);
	// 	printf("stack a : ");
	// 	print_list(x->a);
	// }
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
