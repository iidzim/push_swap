/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/14 19:30:34 by iidzim           ###   ########.fr       */
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

int print_err(char *s)
{
    write(2, "Error: \n", 8);
    write(2, s, ft_strlen(s));
    exit(1);
}

int overflow(long n)
{
    if (n > 2147483647 || n < -2147483648)
        print_err("overflow");
    return (n);
}

long is_integer(char *s)
{
    int i;
    int signe;
    long n;

    i = 0;
    n = 0;
    signe = 1;
    if (s[i] == '-')
    {
        signe = -1;
        s[i] *= -1;
        i += 1;
    }
    while (s[i])
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            n = n * 10 + (s[i] - 48);
            i++;
        }
        else
            print_err("must be digit");
    }
    return (overflow(n * signe));
}
char    is_dup(int *arr, int i, int n)
{
    int j;

    j = -1;
    while (++j <= i)
        if (arr[j] == n)
            return (1);
    return (0);    
}

int valid_nbr(int argc, char **argv)
{
    int     i;
    int     n;
    int     *dup;

    if (!(dup = malloc(argc * sizeof(int))))
        return (1);
    memset(dup, 0, argc);
    i = 0;
    while (argc > ++i)
    {
        n = is_integer(argv[i]);
        if (is_dup(dup, n, i - 1)) 
            print_err("DUPLICATE!");
        dup[i - 1] = n;
    }
    
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%d\n", dup[i]);
    }
    
    return (1);
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        if (valid_nbr(argc, argv))
            print_err("msg");
        // fill_list(argc, argv);
        //instructions
        // if (valid_instruction(argc, argv))
        //     print_err("msg");
    }
    else
        exit(1);
    return (0);
}