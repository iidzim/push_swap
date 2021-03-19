/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:49:11 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/19 15:52:29 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*p;
	int		size;

	i = 0;
	size = ft_strlen(str);
	p = (char *)malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		p = (char *)malloc(1 * sizeof(char));
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (len-- > 0)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	int		size_s1;
	int		size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	i = -1;
	j = 0;
	if (p)
	{
		while (s1[++i] != '\0')
			p[i] = s1[i];
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (n - 1 > i && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}
