/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:31 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 18:04:28 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void    ft_sleep()
// {
    
// }

// void    ft_think()
// {
    

// }

int    ft_take_and_drop(t_philo *philo, pthread_mutex_t *fork, int mode)
{
    // printf("state : %d\n" ,philo->check_state);
    if (mode == TAKE)
    {
        if (philo->check_state == 1 || pthread_mutex_lock(&fork[philo->myfork]) != 0) // 0 success
        {
            // printf("found\n");
            // exit (0);
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
    philo->nbr_ate++;
    ft_print(philo->id, philo->start_time, EAT);
    ft_take_and_drop(philo, fork, DROP);
    // exit(0);
    // printf("nbr_ate : %d\n" , philo->nbr_ate);
    // ft_print(1, MYFORK);
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
        exit(0);
        // ft_sleep();
        // ft_think();
    }
    
    return (NULL);
}

int ft_crttheard(t_main *main)
{
    // main->i = 0;   
    // printf("nbr_philo_crt : %d\n", main->data->nbr_philo);
    while (main->i < main->data.nbr_philo)
    {
         
        // pthread_create(&main->philo[main->i].th, NULL, &routine, main);
        if (pthread_create(&main->philo[main->i].th, NULL, &routine, main) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        // exit(0);
        // pthread_join(main->philo[i].th, NULL);
        // if (pthread_detach(main->philo[main->i].th) == EXIT_FAILURE)
        //     return (EXIT_FAILURE);
        // main->i += 2;
        // if (main->i >= main->data->nbr_philo)
        //     main->i = 1;
    }
    
    return (EXIT_SUCCESS);
}

