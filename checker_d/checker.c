/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 12:11:39 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while(++i < 11)
	{
		free(tab[i]);
		tab[i] = NULL;	
	}
	free(tab);
	tab = NULL;
}

int	valid_instruction(char *inst)
{
	int		i;
	int		len;
	char	**tab;

	tab = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", 32);
	i = -1;
	len = ft_strlen(inst);
	printf("*********[%s]\n", inst);
	while (++i < 11)
	{
		if (!strcmp(inst, tab[i]))
		{
			printf("okok\n");
			free_tab(tab);
			return (1);
		}
	}
	free_tab(tab);
	return (0);
}

static    char    *ft_join(char *s, char c)
{
    int        i;
    char    *str;

    i = 0;
    while (s[i])
        i++;
    str = (char *)malloc(i + 2);
    if (str == NULL)
        return (0);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(s);
    return (str);
}

int    get_next_line(char **line)
{
    char    *buffer;
    int        flag;

    buffer = (char *)malloc(2);
    flag = read(0, buffer, 1);
    *line = (char *)malloc(1);
    if (!line || !(*line) || !buffer)
        return (-1);
    *line[0] = '\0';
    while (flag > 0)
    {
        buffer[1] = 0;
        if (buffer[0] == '\n')
            break ;
        *line = ft_join(*line, buffer[0]);
        flag = read(0, buffer, 1);
    }
    free(buffer);
    return (flag);
}

// int	get_next_inst(t_all *x)
// {
// 	char	*line;
// 	char	*str;
// 	char	*temp;

// 	str = ft_strdup("");
// 	while (get_next_line(&line) > 0)
// 	{
// 		// printf("line >>> %s\n", line);
// 		if (line[0] == '\0')
// 			break;
// 		temp = str;
// 		str = ft_strjoin(str, line);
// 		free(temp);
// 		free(line);
// 	}
// 	free(line);
// 	printf("str >>> %s\n", str);
// 	if (valid_instruction(str) && ft_strlen(str))
// 		exec_op(str, x, 0);
// 	else //if (!valid_instruction(str) && ft_strlen(str))
// 	{
// 		write(2, "Error\n", 6);
// 		free(str);
// 		return (1);
// 	}
// 	free(str);
// 	return (0);
// }

int	print_err(char *str)
{	
	(void)str;
	write(2, "Error\n", 6);
	// free(str);
	exit (1);
}
int	get_next_inst(t_all *x)
{
	char	*buff;
	char	*pfree;
	int		new;
	char	*str;

	new = 1;
	while (get_next_line(&buff) > 0)
	{
		if (new)
			str = ft_strdup("");
		if (buff[0] != '\0')
		{
			new = 0;
			pfree = str;
			str = ft_strjoin (str, &buff[0]);
			free (pfree);
			printf ("|%s|\n", str);
			if (valid_instruction(str))
				exec_op(str, x, 0);
			// else
			// 	print_err(str);
		}
		else
			print_err(str);
		new = 1;
	}
	if (buff[0])
	{
		if (valid_instruction(buff))
			exec_op(str, x, 0);
		else
			print_err(str);	
	}
	free(buff);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
			get_next_inst(&x);
		if (sorted(&x))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_freelst(x.a);
		ft_freelst(x.b);
	}
	else if (argc == 1)
		return (0);
	else
		write(2, "Error\n", 6);
	system("leaks checker");
	return (0);
}
