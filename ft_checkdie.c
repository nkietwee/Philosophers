/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:41:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/08 01:56:19 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




// int ft_checktime(t_main * main)
// {
    
//     // if (main->philo)


// }


// int ft_check_nbr_ate(t_main *main)
// {
//     int i;

//     i = 0;
//     while (i < main->data.nbr_philo)
//     {
//         if (main->philo[i].nbr_ate == main->data.nbr_eat || main->philo[i].nbr_ate == -1)
//             i++;
//         else
//             return (EXIT_FAILURE);  
//     }
//     return (EXIT_SUCCESS);

// }

int ft_check_nbr_ate(t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.nbr_philo)
    {
        if (main->philo[i].nbr_ate < main->data.nbr_eat || main->philo[i].nbr_ate == -1)
            return (EXIT_FAILURE);  
        i++;
    }
    return (EXIT_SUCCESS);

}

int ft_checkdie (t_main *main)
{
    int i;

    i = 0;
    // while (i < main->data.nbr_philo)
    while (!main->philo[i].check_state)
    {
        if (i > main->data.nbr_philo)
            i = 0;
        if (main->data.nbr_eat != -1 && ft_check_nbr_ate(main) == EXIT_SUCCESS)
        {
            printf("check_nbr_ate\n");
            // ft_print(main->philo, DIE);
            main->philo[i].check_state = 1;
            // return (EXIT_FAILURE); // ??
            return (EXIT_SUCCESS); // ??
        }
        if (time_diff(main->philo[i].last_meal) > main->data.time_die)
        {
            // printf("time_diff\n");
            printf("time_diff[%d] : %lu\n" , main->philo->id, time_diff(main->philo[i].last_meal));
            printf("time_die : %d\n" , main->data.time_die);
            ft_print(main->philo , DIE);
            main->philo[i].check_state = 1;
            return (EXIT_SUCCESS);
        }
        // i++;
    }    
    return(EXIT_SUCCESS);
}