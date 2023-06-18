/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:41:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/18 22:15:30 by nkietwee         ###   ########.fr       */
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
        if ((main->philo[i].nbr_ate < main->data.nbr_eat))
            return (EXIT_FAILURE);  
        i++;
        // if (main->data.check_state == DIE || \
        // ((main->philo[i].nbr_ate < main->data.nbr_eat) || main->philo[i].nbr_ate == -1))
            // return (EXIT_FAILURE);  
    }
    return (EXIT_SUCCESS);

}

void ft_checkdie (t_main *main)
{
    int i;
    long time;

    i = 0;
    while (!main->data.check_state)
    {
        if (main->data.nbr_eat != -1 && ft_check_nbr_ate(main) == EXIT_SUCCESS )
        {
            main->data.check_state = DIE;
            // usleep(10);
            return ; // ??
        }
        // if (((main->data.nbr_ea`t <= main->philo[i].nbr_ate) || main->data.nbr_eat == -1 ) \
        //  && time_diff(main->philo[i].start_meal) > main->data.time_die)
          if (((main->philo[i].nbr_ate < main->data.nbr_eat)|| main->data.nbr_eat == -1) \
         && time_diff(main->philo[i].start_meal) > main->data.time_die) // protect above If it eat already
        {
            pthread_mutex_lock(&main->data.print);
            if (main->data.check_state == NOTDIE)
            {
                main->data.check_state = DIE;
                time = current_time() - main->data.start_time;
                printf(BBLU"%ld ms " reset, time);
                printf("Philo %d die\n", main->philo->id);
                // ft_print(main->philo , PDIE);
            }
            pthread_mutex_unlock(&main->data.print);
            break;
        }
        usleep(10);
        i++;
        i = i % main->data.nbr_philo;
    }    
}