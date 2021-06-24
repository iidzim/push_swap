/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:53:46 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/23 10:50:09 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_find(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_free(char **s1, int ret)
{
	free(*s1);
	*s1 = NULL;
	return (ret);
}

int		ft_return(char **str, char **line)
{
	int		k;
	char	*ptr;

	k = 0;
	if (ft_find(*str))
	{
		while ((*str)[k] != '\n')
			k++;
		*line = ft_substr(*str, 0, k);
		ptr = *str;
		*str = ft_strdup(*str + k + 1);
		return (ft_free(&ptr, 1));
	}
	*line = ft_strdup(*str);
	return (ft_free(str, 0));
}

int		get_next_line(int fd, char **line, int buff_size)
{
	ssize_t		r;
	static char *str;
	char		*ptr;
	char		*buff;

	r = 0;
	if (buff_size < 0 || !(buff = malloc(sizeof(char) * buff_size + 1)) ||
		fd < 0 || !line)
		return (-1);
	if (!str)
		str = ft_strdup("");
	while ((r = read(fd, buff, buff_size)) > 0)
	{
		buff[r] = '\0';
		ptr = str;
		str = ft_strjoin(str, buff);
		ft_free(&ptr, 0);
		if (ft_find(str))
			break ;
	}
	ft_free(&buff, 0);
	if (r == -1)
		return (ft_free(&str, -1));
	return (ft_return(&str, line));
}
