/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/06 17:52:04 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    current_time(void)
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_sec / 1000));
}

long    time_to_action(long time_action)
{
    long    start;

    start = current_time();   
    while (current_time() -  start < time_action) // check_die
        usleep(50);
    // usleep(time_action); It cann't use in case It die 
    return(EXIT_SUCCESS);
}

long    time_diff(long time)
{
    return(time - current_time());    
}