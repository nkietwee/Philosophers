/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:41:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/17 18:29:29 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


// int ft_checkdie (t_main *main)
// {
//     int i;

//     i = 0;
//     while (!main->philo[i].check_state)
//     {
//         if (main->data.nbr_eat != -1 && ft_check_nbr_ate(main) == EXIT_SUCCESS)
//         {
//             printf("check_nbr_ate\n");
//             main->philo[i].check_state = 1;
//             return (EXIT_SUCCESS); // ??
//         }
//         // if ((main->philo[i].nbr_ate < main->data.nbr_eat || main->data.nbr_eat == -1)
//         //      || time_diff(main->philo[i].start_meal) > main->data.time_die)
//         if (time_diff(main->philo[i].start_meal) > main->data.time_die)
//         {
//             printf("time_diff\n");
//             printf("time_diff[%d] : %lu\n" , main->philo->id, time_diff(main->philo[i].start_meal));
//             printf("time_die : %d\n" , main->data.time_die);
//             ft_print(main->philo , DIE);
//             main->philo[i].check_state = 1;
//             return (EXIT_SUCCESS);
//         }
//         i++;
//         i = i % main->data.nbr_philo;
//     }    
//     return(EXIT_SUCCESS);
// }

int ft_check_nbr_ate(t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.nbr_philo)
    {
        if ((main->philo[i].nbr_ate < main->data.nbr_eat) || main->philo[i].nbr_ate == -1)
            return (EXIT_FAILURE);  
        i++;
    }
    return (EXIT_SUCCESS);

}

void ft_checkdie (t_main *main)
{
    int i;

    i = 0;
    while (!main->data.check_state)
    {
        if (main->data.nbr_eat != -1 && ft_check_nbr_ate(main) == EXIT_SUCCESS)
        {
            main->data.check_state = DIE;
            // usleep(10);
            return ; // ??
        }
        // if (((main->data.nbr_ea`t <= main->philo[i].nbr_ate) || main->data.nbr_eat == -1 ) \
        //  && time_diff(main->philo[i].start_meal) > main->data.time_die)
          if (((main->philo[i].nbr_ate < main->data.nbr_eat) || main->data.nbr_eat == -1 ) \
         && time_diff(main->philo[i].start_meal) > main->data.time_die)
        {
            main->data.check_state = DIE;
            ft_print(main->philo , PDIE);
            return ;
        }
        usleep(5);
        i++;
        i = i % main->data.nbr_philo;
    }    
}