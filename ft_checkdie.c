/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:41:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/06 17:54:46 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




// int ft_checktime(t_main * main)
// {
    
//     // if (main->philo)


// }

int ft_check_nbr_ate(t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.nbr_philo)
    {
        if (main->philo[i].nbr_ate == main->data.nbr_eat || main->philo[i].nbr_ate == -1)
            i++;
        else
            return (EXIT_FAILURE);  
    }
    return (EXIT_SUCCESS);

}

int ft_checkdie (t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.nbr_philo)
    {
        if (ft_check_nbr_ate(main) == EXIT_SUCCESS)
        {
            main->philo[i].check_state = 1;
            return (EXIT_SUCCESS);
        }
        if (time_diff(main->philo[i].last_meal) > main->data.time_die)
        {
            main->philo[i].check_state = 1;
            return (EXIT_SUCCESS);
        }
    }    
    //clearmutex
    //free
    return(EXIT_SUCCESS);
}