/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 18:33:27 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	print_err(char *str)
{	
	write(2, "Error\n", 6);
	free(str);
	exit (1);
}

int	helper(t_data *m, t_all *x)
{
	if (m->buff[0])
	{
		if (valid_instruction(m->buff))
			exec_op(m->buff, x, 0);
		else
		{
			print_err(m->buff);
			free(m->buff);
			return (1);
		}
	}
	free(m->buff);
	return (0);
}

int	get_next_inst(t_all *x)
{
	t_data	m;

	m.new = 1;
	while (get_next_line(&m.buff) > 0)
	{
		if (m.new)
			m.str = ft_strdup("");
		if (m.buff[0] != '\0')
		{
			m.new = 0;
			m.temp = m.str;
			m.str = ft_strjoin(m.str, &(m.buff[0]));
			free (m.temp);
			if (valid_instruction(m.str))
				exec_op(m.str, x, 0);
			else
				print_err(m.str);
		}
		else
			print_err(m.str);
		m.new = 1;
		free(m.str);
		free(m.buff);
	}
	return (helper(&m, x));
}

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	while (temp)
	{
		printf("<%d>\n", temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
		{
			// print_list(x.a);
			get_next_inst(&x);
			// printf("**********\n");
			// print_list(x.a);
			if (sorted(&x))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		ft_freelst(x.a);
		ft_freelst(x.b);
	}
	else if (argc == 1)
		return (0);
	else
		write(2, "Error\n", 6);
	return (0);
}
