/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:12 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/18 11:57:59 by iidzim           ###   ########.fr       */
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

int print_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long ft_atoi(char *s)
{
	int		signe;
	long	x;

	signe = 1;
	x = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s != '\0' && ft_isdigit(*s))
	{
		x = (x * 10) + ((char)*s - '0');
		s++;
	}
	if (!ft_isdigit(*s) && *s != '\0')
		print_err();
	return (x * signe);
}

int overflow(long n)
{
	if (n > INT32_MAX || n < INT32_MIN)
		print_err();
	return ((int)n);
}

t_list	*ft_lstnew(int value)
{
	t_list	*head;

	head = (t_list*)malloc(sizeof(t_list));
	if (head == 0)
		return (NULL);
	head->value = value;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}

t_inst_list	*ft_inst_new(char *value)
{
	t_inst_list	*head;

	head = (t_inst_list*)malloc(sizeof(t_inst_list));
	if (head == 0)
		return (NULL);
	head->inst = value;
	head->next = NULL;
	return (head);
}

void	ft_inst_addback(t_inst_list **list, t_inst_list *new)
{
	t_inst_list	*last;

	if (!new)
		return ;
	last = *list;
	new->next = NULL;
	if ((*list) == NULL)
		(*list) = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
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

void	ft_freelst(t_inst_list *instructions)
{
	t_inst_list *temp;

	while(instructions != NULL)
	{
		temp = instructions;
		instructions = instructions->next;
		free(temp);
	}
	print_err();
}