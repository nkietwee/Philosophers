/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:41:55 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/01 16:3 by7nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_initdataphilo(t_data *data, int ac, char **av)
{
    data->nbr_philo = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->nbr_eat = ft_atoi(av[5]);
    else
        data->nbr_eat = -1;
    data->check_state = 0;
    // return(EXIT_SUCCESS);
}

t_philo    *ft_initphilo(t_data *data)
{
    int i;
    t_philo *philo;
    
    i = 0;
    philo = malloc(sizeof(t_philo) * data->nbr_philo);
    if (!philo)
        return (NULL);
    while (i < data->nbr_philo)
    {
        philo[i].id = i + 1; // id start at 1 to nbr_philo
        philo[i].myfork = i; // for position
        philo[i].notmyfork = (i + 1) % data->nbr_philo; // for position
        philo[i].nbr_ate = 0;
        philo[i].data = data;
        // philo[i].check_state = 0;
        i++;
    }
    return (philo);
}

pthread_mutex_t *ft_initfork(int nbr_philo)
{
    int i;
    pthread_mutex_t *fork;
    
    fork = NULL;
    fork = malloc(sizeof(pthread_mutex_t) * nbr_philo);
    if (!fork)
        return (NULL);
    i = 0;
    while(i < nbr_philo)
    {
        pthread_mutex_init(&fork[i] , NULL);
        i++;
    }
    return (fork);
}

int ft_init(t_main *main, int ac, char **av)
{
    // main->print = NULL;
    ft_initdataphilo(&main->data, ac, av);
    if (main->data.nbr_philo == 0)
        return (EXIT_FAILURE);
    main->philo =  ft_initphilo(&main->data);
    if (!main->philo)
        return (EXIT_FAILURE);
    main->fork =  ft_initfork(main->data.nbr_philo);
    if (!main->fork)
        return (EXIT_FAILURE);
    // main->data.print = pthread_mutex_init(main->data.print, NULL);
    pthread_mutex_init(&main->data.print, NULL);
    // if (!main->print)
    //     return (EXIT_FAILURE); 
    // ft_crttheard(main);
    return(EXIT_SUCCESS);
}