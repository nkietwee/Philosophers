/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:31 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/04 01:22:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int    ft_think(t_philo *philo)
{
    ft_print(philo->id, philo->start_time, THINK);
    return (EXIT_SUCCESS);
}

int    ft_sleep(t_philo *philo)
{
    time_to_action(philo->data->time_sleep);
    ft_print(philo->id, philo->start_time, SLEEP);
    return(EXIT_SUCCESS);
}

int    ft_take_and_drop(t_philo *philo, pthread_mutex_t *fork, int mode)
{
    // printf("state : %d\n" ,philo->check_state);
    if (mode == TAKE)
    {
        if (philo->check_state == 1 || pthread_mutex_lock(&fork[philo->myfork]) != 0) // 0 success
        {
            // printf("found\n");
            return(EXIT_FAILURE);
        }
        ft_print(philo->id,philo->start_time , MYFORK);
        if (pthread_mutex_lock(&fork[philo->notmyfork]) != 0) // 0 success
            return(EXIT_FAILURE);
        ft_print(philo->id, philo->start_time, NOTMYFORK);
        // philo->check_state = 1;
    }
    else if (mode == DROP)
    {
        // printf("DROP\n");
        if (pthread_mutex_unlock(&fork[philo->myfork]) != 0) // 0 success
            return(EXIT_FAILURE);
        if (pthread_mutex_unlock(&fork[philo->notmyfork]) != 0) // 0 success
            return(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int ft_philoeat(t_philo *philo, pthread_mutex_t *fork)
{
    // philo->check_state = 1;
    if (ft_take_and_drop(philo, fork, TAKE) == EXIT_FAILURE)
    {
        // printf("DIE\n");
        // exit(0);
        return(EXIT_FAILURE);
    }
    philo->nbr_ate++; // in case It have amount of eat
    ft_print(philo->id, philo->start_time, EAT);
    time_to_action(philo->data->time_eat);
    ft_take_and_drop(philo, fork, DROP);
    return (EXIT_SUCCESS);    
}

void    *routine(void *arg)
{
    (void)arg;
    t_main  *main;
    
    main = (t_main *)arg;
    main->philo[main->i].start_time = current_time();
    while (1)
    {
        if (ft_philoeat(&main->philo[main->i], main->fork) == EXIT_FAILURE)
            break;
        if (ft_sleep(&main->philo[main->i]) == EXIT_FAILURE)
            break;
        if (ft_think(&main->philo[main->i]) == EXIT_FAILURE)
            break;
    }
    
    return (NULL);
}

int ft_crttheard(t_main *main)
{
    main->i = 0;   
    while (main->i < main->data.nbr_philo)
    {
         
        // pthread_create(&main->philo[main->i].th, NULL, &routine, main);
        if (pthread_create(&main->philo[main->i].th, NULL, &routine, main) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        // pthread_join(main->philo[i].th, NULL);
        if (pthread_detach(main->philo[main->i].th) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        // main->i += 2; // for even nbr
        // break;
        // if (main->i >= main->data.nbr_philo) // start odd number
        //     main->i = 1;
    }
    
    return (EXIT_SUCCESS);
}

