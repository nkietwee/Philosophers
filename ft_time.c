/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/19 01:20:34 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long current_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    // return((time.tv_usec / 1000) + (time.tv_sec * 1000)); //true
    return ((time.tv_usec) + (time.tv_sec * 1000000)); // true
}

int time_to_action(unsigned long int time_action, int *check_state)
{
    unsigned long int start;

    // usleep(time_action);
    start = current_time();
    while (((current_time() - start < time_action * 1000))) // check_die
        usleep(10);
    // printf(URED"out\n" reset);
    // usleep(time_action); It cann't use in case It die
    return (*check_state);
}

unsigned long int time_diff(unsigned long int time)
{
    return (current_time() - time);
}