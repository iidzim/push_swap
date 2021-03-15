/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/15 12:56:33 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int overflow(long n)
{
    if (n > 2147483647 || n < -2147483648)
        print_err("overflow !");
    return (n);
}

long is_integer(char *s)
{
    int i;
    int signe;
    long n;

    return (atoi(s));

    // i = 0;
    // n = 0;
    // signe = 1;
    // if (s[i] == '-')
    // {
    //     signe = -1;
    //     s[i] *= -1;
    // }
    // while (s[++i])
    // {
    //     if (s[i] >= 48 && s[i] <= 57)
    //         n = n * 10 + (s[i] - 48);
    //     else
    //         print_err("must be digit");
    // }
    // return (overflow(n * signe));
}

char    is_dup(int *dup, int n, int i)
{
    int j;

    j = 0;
    while (++j < i - 1)
        if (dup[j] == n)
            return (1);
    return (0);
}

int valid_nbr(int argc, char **argv)
{
    int     i;
    int     n;
    int     *dup;

    dup = malloc(sizeof(int) * argc);
    memset(dup, 0, argc * 4); //0,0,0,0...
    i = 0;
    while (argc > ++i) // i = 1
    {
        n = is_integer(argv[i]);
        if (is_dup(dup, n, i - 1))
            print_err("DUPLICATE !");
        dup[i-1] = n;
    }
    i = 0;
    while (++i < argc)
        printf("%d\n", dup[i]);
    return (0);
}

// int fill_list(argc, argv)
// {
//     t_stack *l;

//     if (!(l = malloc(sizeof(t_stack))))
//         return (-1);
//     l->size = argc;
//     l->tab = malloc(sizeof(int) * l->size);
//     //1rst arg should be at the top of the stack
//     push(l, argv);
    
//     return (0);
// }

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        if (valid_nbr(argc, argv))
            print_err("random number of either positive or negative numbers without any duplicates");
        // fill_list(argc, argv);
        //instructions
        // if (valid_instruction(argc, argv))
        //     print_err("msg");
    }
    else
    {
        printf("add more args");
        exit(1);
    }
    return (0);
}