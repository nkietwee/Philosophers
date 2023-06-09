/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/09 13:25:46 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    current_time(void)
{
    struct timeval  time;
    
    
    gettimeofday(&time, NULL);
    return((time.tv_usec / 1000) + (time.tv_sec * 1000)); //true
}

int    time_to_action(long time_action, int *check_state)
{
    long    start;

    start = current_time();   
    while (!(*check_state) && (current_time() -  start < time_action)) // check_die
        usleep(100);
    // printf(URED"out\n" reset);
    // usleep(time_action); It cann't use in case It die 
    return(*check_state);
}

long    time_diff(long time)
{
    return(current_time() - time);
}