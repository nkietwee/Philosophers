/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/04 15:12:09 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(int id, long start_time, int mode)
{
    long    time;
    
    time = current_time() - start_time; 
    printf(BBLU"%ld ms " reset,time);
    // printf(BWHT" ms   " reset);
    if (mode == MYFORK)
        printf(BWHT"Philo[%d]" GRN" takemyfork\n"reset, id);
    else if (mode == NOTMYFORK)
        printf(BWHT"Philo[%d] " BGRN"notmyfork\n"reset, id);
    else if (mode == EAT)
        printf(BWHT"Philo[%d]" BCYN " eat\n"reset, id);
    else if (mode == SLEEP)
        printf(BWHT"Philo[%d]" BMAG" sleep\n"reset, id);
    else if (mode == THINK)
        printf(BWHT"Philo[%d]" BYEL " think\n"reset, id);
    else if (mode == DIE)
        printf(BWHT"Philo[%d]" URED " die\n"reset, id);


}