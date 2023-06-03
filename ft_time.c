/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/04 00:58:24 by nkietwee         ###   ########.fr       */
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
    long    start_time;

    start_time = current_time();   
    while (current_time() - start_time < time_action)
        usleep(180);
    return(EXIT_SUCCESS);
}   