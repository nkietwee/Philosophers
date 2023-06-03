/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:19:04 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 10:45:18 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
     t_main main;

     if (ft_check(ac, av) ==  EXIT_FAILURE)
          return (EXIT_FAILURE);
     if (ft_init(&main, ac, av) == EXIT_FAILURE)
          return(EXIT_FAILURE);
     // printf("tmp\n");
     // exit(0);
     // if ()          
   return (EXIT_SUCCESS);
}