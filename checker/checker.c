/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/29 10:17:00 by iidzim           ###   ########.fr       */
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

int get_next_inst(t_all *x)
{
	char *line;

	while (get_next_line(0, &line, 4))
	{
		if (strcmp(&line[0], "") == 0)
		{
			if (sorted(x->a))
				printf("OK\n");
			else
				printf("KO\n");
			ft_freelst(x->a);
			ft_freelst(x->b);
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

int sorted(t_list *l)
{
	t_list *temp;

	temp = l;
	if(l != NULL && l->next != NULL)
	{
		while(temp->next != NULL)
		{
			if (temp->value > temp->next->value)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}

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
