/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:43:18 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/17 16:44:26 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_clearmutex(t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.nbr_philo)
    {
        pthread_mutex_destroy(&main->fork[i]);
        i++;
    }
    pthread_mutex_destroy(&main->data.print);
}

void    ft_clear(t_main *main)
{
    if (main->data.check_state == DIE)
    {
        ft_clearmutex (main);
        free (main->philo);
        free (main->fork);
        main->philo = NULL;
        main->fork = NULL;
    }
}