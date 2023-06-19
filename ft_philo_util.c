/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:55:49 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/19 00:39:59 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int ft_atol(char *str)
{
    int i;
    unsigned long int res;
    
    if (!str)
        return (0); 
    i = 0;
    res = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0';
        i++;
    }
    // printf("res : %ld\n", res);
    // exit(0);
    return (res);
}