/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/17 19:42:22 by iidzim           ###   ########.fr       */
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

int valid_nbr(int argc, char **argv)
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
	// i = -1;
	// while (++i < argc - 1)
	// 	printf("%d | ", dup[i]);
	// printf("\n");
	
	fill_list(argc - 1, dup);
	free(dup);
	return (0);
}

t_list *fill_list(int n, int *dup)
{
	t_list *l;
	t_list *new;
	int index;

	index = n - 1;
	while(index >= 0)
	{
		if (!new)
			l = ft_lstnew(dup[index]);
		else
		{
			new = ft_lstnew(dup[index]);
			ft_lstadd_front(&l, new);
			// printf("%d\n", l->value);
		}
		index--;
	}
	return (l);
}

int valid_instruction(char *inst)
{
	int		i;
	int		j;
	int		len;
	char	*plz[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = -1;
	while (++i < 11)
	{
		len = ft_strlen(inst);
		j = 0;
		if (len > 3)
			return 0;
		else
		{
			if (!ft_strncmp(inst, plz[i], ft_strlen(inst)))
				return 1;
		}
	}
	return 0;
} 

int get_instructions(void)
{
	t_inst_list	*instructions;
	t_inst_list	*new;
	char	*buff;
	char	*c;
	ssize_t	r;

	printf("00000$\n");
	instructions = NULL;
	buff = strdup("");
	c = malloc(sizeof(char) * 2);
	c[1] = 0;
	while ((r = read(0, c, 1)) > 0)
	{
		if (*c != '\n')
		{
			buff = ft_strjoin(buff, c);
			// printf("[%s]\n", c);
		}
		else
		{
			if (valid_instruction(buff))
			{
				if (!instructions)
					instructions = ft_inst_new(buff);
				else
				{
					printf("$$$$$\n");
					new = ft_inst_new(buff);
					ft_inst_addback(&instructions, new);
					printf("%s | \n", instructions->inst);
				}
			}
		}			
	}
	return 0;
}

// random number of either positive or negative numbers without any duplicates
int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		valid_nbr(argc, argv);
		//instructions
		get_instructions();
	}
	else
		print_err();
	return (0);
}
