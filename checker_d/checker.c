/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/26 17:26:13 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_instruction(char *inst)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	tab = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", 32);
	i = -1;
	while (++i < 11)
	{
		len = ft_strlen(inst);
		j = 0;
		if (len > 3)
			return (0);
		else
		{
			if (!ft_strncmp(inst, tab[i], ft_strlen(inst)))
				return (1);
		}
	}
	return (0);
}

int	get_next_inst(t_all *x)
{
	char	*line;

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
			break ;
		}
		if (valid_instruction(line))
			exec_op(line, x, 0);
		else
		{
			write(2, "Error\n", 6);
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_all	x;

// 	if (argc >= 2)
// 	{
// 		if (!valid_nbr(argc, argv, &x))
// 			get_next_inst(&x);
// 	}
// 	else if (argc == 1)
// 		return (0);
// 	else
// 		write(2, "Error\n", 6);
// 	system("leaks checker");
// 	return (0);
// }
