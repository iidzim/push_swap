/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:53:46 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 13:20:49 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static char	*ft_join(char *s, char c)
{
	int		i;
	char	*str;

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

int	get_next_line(char **line)
{
	char	*buffer;
	int		flag;

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

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (++i < 11)
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
	char	**tab;

	tab = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", 32);
	i = -1;
	while (++i < 11)
	{
		if (!ft_strcmp(inst, tab[i]))
		{
			free_tab(tab);
			return (1);
		}
	}
	free_tab(tab);
	return (0);
}
