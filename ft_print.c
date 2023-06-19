/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/19 01:04:56 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);    
}

void    ft_putstr(char *str)
{
    if (!str)
        return ;
    write(1, str, ft_strlen(str));
 
}

void    ft_print(t_philo *philo,int mode)
{
    unsigned long    time;
    
    time = current_time() - philo->data->start_time ;
    time = time / 1000;
    // printf("[%d]  : %d\n" ,philo->id , philo->data->check_state);
    // printf(" [%d] : [%p]\n" ,philo->id , &philo->data->check_state);
    pthread_mutex_lock(&philo->data->print);
    // printf("id:%d", philo->id);
    
    // printf("id:%d", philo->id);
    if (philo->data->check_state == NOTDIE)
    {
        printf(BBLU"%d ms " reset, (int)time);
        if (mode == PMYFORK)
            printf("Philo %d takemyfork\n", philo->id);
        else if (mode == PNOTMYFORK)
            printf("Philo %d notmyfork\n", philo->id);
        else if (mode == PEAT)
            printf("Philo %d eat\n", philo->id);
        else if (mode == PSLEEP)
            printf("Philo %d sleep\n", philo->id);
        else if (mode == PTHINK)
            printf("Philo %d think\n", philo->id);
        // else if (mode == PDIE)
        //     printf("Philo %d die\n", philo->id);
    }
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