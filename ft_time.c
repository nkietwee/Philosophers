/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 15:41:47 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    current_time(void)
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_sec / 1000));
}

// long