/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:31 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/06 17:38:12 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int    ft_think(t_philo *philo)
// {
//     ft_print(philo->id, philo->start_time, THINK);
//     return (EXIT_SUCCESS);
// }

int    ft_sleep(t_philo *philo)
{
    ft_print(philo->id, philo->start_time, SLEEP);
    time_to_action(philo->data->time_sleep);
    ft_print(philo->id, philo->start_time, THINK);
    return(EXIT_SUCCESS);
}

int    ft_take_and_drop(t_philo *philo, pthread_mutex_t *fork, int mode)
{
    // printf("state : %d\n" ,philo->check_state);
    // philo->check_state = 1;
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
        ft_print(philo->id, philo->start_time, DIE);
        // printf("DIE\n");
        // exit(0);
        return(EXIT_FAILURE);
    }
    ft_print(philo->id, philo->start_time, EAT);
    time_to_action(philo->data->time_eat);
    philo->last_meal = current_time(); // for check_die
    // printf("last_meal : %ld\n" , philo->last_meal - philo->start_time);
    ft_take_and_drop(philo, fork, DROP);
    philo->nbr_ate++; // in case It have amount of eat
    // printf("nbr_ate : %d\n", philo->nbr_ate);
    return (EXIT_SUCCESS);    
}

void    *routine(void *arg)
{
    (void)arg;
    t_main  *main;
    int     i;
    
    main = (t_main *)arg;
    // main->philo->last_meal = main->philo;//??
    i = main->id_cur;
    // while (1)
    while (1) // when it die // main->data.eat <= main->data.ate
    {
        if (ft_philoeat(&main->philo[i], main->fork) == EXIT_FAILURE)
            break;
        if (ft_sleep(&main->philo[i]) == EXIT_FAILURE)
            break;
        // if (ft_think(&main->philo[main->i]) == EXIT_FAILURE)
        //     break;
    }
    
    return (NULL);
}

int ft_crttheard(t_main *main)
{
    int i; 
    
    i = 0;  
    // main->philo[main->i].start_time = current_time();
    while (i < main->data.nbr_philo)
    {
        
        main->philo[i].start_time = current_time(); 
        main->id_cur = i;
        if (pthread_create(&main->philo[i].th, NULL, &routine, main) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (pthread_detach(main->philo[i].th) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        // usleep (50);
        i += 2; // for even nbr
        if (i >= main->data.nbr_philo && i % 2 == 0) // start odd number
        {
            // usleep();
            i = 1;
        }
    }
    
    return (EXIT_SUCCESS);
}

