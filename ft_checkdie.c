/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:41:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 19:21:58 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_nbr_ate(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.nbr_philo)
	{
		if (main->philo[i].nbr_ate < main->data.nbr_eat)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_checkdie(t_main *main)
{
	int		i;

	i = 0;
	while (!main->data.check_state)
	{
		if (main->data.nbr_eat != -1 && ft_check_nbr_ate(main) == EXIT_SUCCESS)
		{
			main->data.check_state = DIE;
			return ;
		}
		if (((main->philo[i].nbr_ate < main->data.nbr_eat) \
		|| main->data.nbr_eat == -1) \
		&& time_diff(main->philo[i].start_meal) > main->data.time_die)
		{
			if (main->data.check_state == NOTDIE)
			{
				ft_print (main->philo, PDIE);
				main->data.check_state = DIE;
			}
			return ;
		}
		usleep(10);
		i++;
		i = i % main->data.nbr_philo;
	}
}
