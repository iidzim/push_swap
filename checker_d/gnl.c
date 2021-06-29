/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:53:46 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 12:27:09 by iidzim           ###   ########.fr       */
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
