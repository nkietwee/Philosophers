/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/04 00:51:41 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(int id, long start_time, int mode)
{
    long    time;
    
    time = current_time() - start_time; 
    printf("%ld ms   " ,time);
    if (mode == MYFORK)
        printf("Philo[%d] takemyfork\n", id);
    else if (mode == NOTMYFORK)
        printf("Philo[%d] notmyfork\n", id);
    else if (mode == EAT)
        printf("Philo[%d] eat\n", id);

}