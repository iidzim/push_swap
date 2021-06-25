/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/25 16:43:46 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int valid_nbr(int argc, char **argv, t_all *x)
{
	int     i;
	int     n;
	int     *dup;

	dup = malloc(sizeof(int) * (argc));
	// memset(dup, 2147483647, (argc - 1) * 4);
	i = 0;
	while (argc > ++i)
	{
		n = overflow(ft_atoi(argv[i]));
		if (is_dup(dup, n, i))
		{
			free(dup);
			print_err();
		}
		dup[i-1] = n;
	}
	dup[i - 1] = '\0';
	x->size_a = argc - 1;
	fill_list(dup, x);
	print_list(x->a);
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

// char	*read_cmd(void)
// {
// 	size_t	r;
// 	char	*line;
// 	char	*buffer;

// 	buffer = malloc(sizeof(char) * 2);
// 	r = read(0, buffer, 1);
// 	line = malloc(sizeof(char) * 2);
// 	if (!buffer || !line)
// 		return (NULL);
// 	line[0] = '\0';
// 	while (r > 0)
// 	{
// 		buffer[1] = 0;
// 		if (buffer[0] == '\n')
// 			break ;
// 		line = ft_strjoinchar(line, buffer[0]);
// 		r = read(0, buffer, 1);
// 	}
// 	free(buffer);
// 	return (line);
// }

int get_next_inst(t_all *x)
{
	char *line;

	while (get_next_line(0, &line, 4) > 0)
	{
		if (!strcmp(&line[0], ""))
		{
			if (sorted(x->a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			ft_freelst(x->a);
			ft_freelst(x->b);
			break;
		}
		if (valid_instruction(line))
			exec_op(line, x, 0);
		else
			print_err();
		free(line);
	}
	return 0;
}

int sorted(t_list *l)
{
	// printf("check_if_sorted\n");
	// print_list(l);
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

// int main(int argc, char **argv)
// {
// 	t_all x;

// 	if (argc >= 2)
// 	{
// 		valid_nbr(argc, argv, &x);
// 		get_next_inst(&x);
// 	}
// 	else if (argc == 1)
// 		return (0);
// 	else
// 		print_err();
// 	print_list(x.a);
// 	return (0);
// }
