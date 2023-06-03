/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:55:49 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 11:41:30 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    long res;
    
    if (!str)
        return (0); 
    i = 0;
    res = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0';
        // if (res > 2147483647) // protect value over max int 
        //     return(0); // If value == 0
        i++;
    }
    // printf("res : %ld\n", res);
    // exit(0);
    return (res);
}