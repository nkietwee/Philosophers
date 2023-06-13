/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/13 17:36:15 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(t_philo *philo,int mode)
{
    long    time;
    
    time = current_time() - philo->start_time; 
    pthread_mutex_lock(&philo->data->print);
    printf(BBLU"%ld ms " reset, time);
    
      if (mode == MYFORK)
        printf("Philo %d takemyfork\n", philo->id);
    else if (mode == NOTMYFORK)
        printf("Philo %d notmyfork\n", philo->id);
    else if (mode == EAT)
        printf("Philo %d eat\n", philo->id);
    else if (mode == SLEEP)
        printf("Philo %d sleep\n", philo->id);
    else if (mode == THINK)
        printf("Philo %d think\n", philo->id);
    else if (mode == DIE)
        printf("Philo %d die\n", philo->id);
        
    // if (mode == MYFORK)
    //     printf(BWHT"Philo %d" GRN" takemyfork\n"reset, philo->id);
    // else if (mode == NOTMYFORK)
    //     printf(BWHT"Philo %d" BGRN" notmyfork\n"reset, philo->id);
    // else if (mode == EAT)
    //     printf(BWHT"Philo %d" BCYN " eat\n"reset, philo->id);
    // else if (mode == SLEEP)
    //     printf(BWHT"Philo %d" BMAG" sleep\n"reset, philo->id);
    // else if (mode == THINK)
    //     printf(BWHT"Philo %d" BYEL " think\n"reset, philo->id);
    // else if (mode == DIE)
    //     printf(BWHT"Philo %d" URED " die\n"reset, philo->id);

/* 
    if (mode == MYFORK)
        printf(BWHT"Philo %d" GRN" takemyfork\n"reset, philo->id);
        // printf(BWHT"Philo[%d]" GRN" takemyfork\n"reset, philo->id);
    else if (mode == NOTMYFORK)
        printf(BWHT"Philo %d" BGRN" notmyfork\n"reset, philo->id);
        // printf(BWHT"Philo[%d] " BGRN"notmyfork\n"reset, philo->id);
    else if (mode == EAT)
        printf(BWHT"Philo %d" BCYN " eat\n"reset, philo->id);
        // printf(BWHT"Philo[%d]" BCYN " eat\n"reset, philo->id);
    else if (mode == SLEEP)
        printf(BWHT"Philo %d" BMAG" sleep\n"reset, philo->id);
        // printf(BWHT"Philo[%d]" BMAG" sleep\n"reset, philo->id);
    else if (mode == THINK)
        printf(BWHT"Philo %d" BYEL " think\n"reset, philo->id);
        // printf(BWHT"Philo[%d]" BYEL " think\n"reset, philo->id);
    else if (mode == DIE)
        printf(BWHT"Philo %d" URED " die\n"reset, philo->id);
       // printf(BWHT"Philo[%d]" URED " die\n"reset, philo->id); */
    pthread_mutex_unlock(&philo->data->print);


}