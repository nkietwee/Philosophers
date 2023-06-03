/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 18:03:48 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(int id, long start_time, int mode)
{
    long    time;
    // time = current_time();
    time = current_time() - start_time; 
    printf("time : %ld ms   " ,time);
    // prin"tf("id : %d\n" ,id);
    if (mode == MYFORK)
    {
        printf("Philo[%d] takemyfork\n", id);
    }
    else if (mode == NOTMYFORK)
        printf("Philo[%d] notmyfork\n", id);
    else if (mode == EAT)
        printf("Philo[%d] eat\n", id);

}