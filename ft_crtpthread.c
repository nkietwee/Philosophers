/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:31 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/14 01:46:19 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_sleep_think(t_philo *philo)
{
    ft_print(philo, SLEEP);
    if (time_to_action(philo->data->time_sleep, &philo->data->check_state))
        return (EXIT_FAILURE);
    ft_print(philo, THINK); // segfault
    return (EXIT_SUCCESS);
}

int    ft_take_and_drop(t_philo *philo, pthread_mutex_t *fork, int mode)
{
    if (mode == TAKE)
    {
        if (philo->data->check_state == 1 || pthread_mutex_lock(&fork[philo->myfork]) != 0) // 0 success
            return(EXIT_FAILURE);
        ft_print(philo, MYFORK);
        if (philo->data->check_state == 1 || pthread_mutex_lock(&fork[philo->notmyfork]) != 0) // 0 success
            return(EXIT_FAILURE);
        ft_print(philo, NOTMYFORK);
    }
    else if (mode == DROP)
    {
        if (pthread_mutex_unlock(&fork[philo->myfork]) != 0) // 0 success
            return(EXIT_FAILURE);
        if (pthread_mutex_unlock(&fork[philo->notmyfork]) != 0) // 0 success
            return(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int ft_philoeat(t_philo *philo, pthread_mutex_t *fork)
{
    if (philo->data->check_state == 1 || ft_take_and_drop(philo, fork, TAKE) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_print(philo, EAT);
    // printf("---------last_meal[%d] : %lu-------\n" ,philo->id , philo->start_meal - philo->start_time);
    philo->nbr_ate++; // in case It have amount of eat
    philo->start_meal = current_time(); // for check_die
    time_to_action(philo->data->time_eat, &philo->data->check_state);
    // if (philo->data->check_state == 1 || ft_take_and_drop(philo, fork, DROP) == EXIT_FAILURE)
    if (ft_take_and_drop(philo, fork, DROP) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);    
}

void    *routine(void *arg)
{
    (void)arg;
    t_main  *main;
    int     i;
    
    main = (t_main *)arg;
    i = main->id_cur;
    main->philo[i].start_meal = main->philo[i].start_time;//??
    while (!main->data.check_state) // when it die // main->data.eat <= main->data.ate
    {
        if (ft_philoeat(&main->philo[i], main->fork) == EXIT_FAILURE)
            break;
        if (ft_sleep_think(&main->philo[i]) == EXIT_FAILURE)
            break;
    }    
    return (NULL);
}

int ft_crttheard(t_main *main)
{
    int i; 
    
    i = 0;  
    main->philo[i].start_time = current_time();
    while (i < main->data.nbr_philo)
    {
        
        main->philo[i].start_time = main->philo[0].start_time;
        main->id_cur = i;
        if (pthread_create(&main->philo[i].th, NULL, &routine, main) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        // if (pthread_join(main->philo[i].th , NULL) == EXIT_FAILURE)
        //     return (EXIT_FAILURE); 
        if (pthread_detach(main->philo[i].th) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        usleep (10);
        i += 2; // for even nbr
        if (i >= main->data.nbr_philo && i % 2 == 0) // start odd number
        {
            usleep(10);
            i = 1;
        }
    }
    return (EXIT_SUCCESS);
}