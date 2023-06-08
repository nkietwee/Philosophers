/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:41:42 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/09 04:06:23 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int ft_checkformat(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    (void)ac;
    while (av[i])
    {
    j = 0;
        while (av[i][j])
        {
            // if (!(av[i][j] >= '0' && av[i][j] <= '9'))
            if (ft_isdigit(av[i][j]) == EXIT_FAILURE) 
            {           
                printf("found arg\n");
                return (EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int ft_checkarg(int ac)
{
    if (ac != 5 && ac != 6)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int ft_check(int ac, char **av)
{
    if (ft_checkarg(ac) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (ft_checkformat(ac, av) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

