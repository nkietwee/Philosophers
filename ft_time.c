/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/06 19:43:21 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    current_time(void)
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_sec / 1000));
}

long    time_to_action(long time_action, long check_state)
{
    long    start;

    start = current_time();   
    while ((check_state == 0) && (current_time() -  start < time_action)) // check_die
        usleep(150);
    // usleep(time_action); It cann't use in case It die 
    return(EXIT_SUCCESS);
}

long    time_diff(long time)
{
    return(current_time() - time);
}