/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:31 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 16:41:42 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_think(t_philo *philo)
{
	ft_print(philo, PSLEEP);
	time_to_action(philo->data->time_sleep);
	ft_print(philo, PTHINK);
}

int	ft_take_and_drop(t_philo *philo, pthread_mutex_t *fork, int mode)
{
	if (mode == TAKE)
	{
		if (philo->data->check_state == DIE \
		|| pthread_mutex_lock(&fork[philo->myfork]) != 0)
			return (EXIT_FAILURE);
		ft_print(philo, PMYFORK);
		if (philo->data->check_state == DIE \
		|| pthread_mutex_lock(&fork[philo->notmyfork]) != 0)
			return (EXIT_FAILURE);
		ft_print(philo, PNOTMYFORK);
	}
	else if (mode == DROP)
	{
		if (philo->data->check_state == DIE \
		|| pthread_mutex_unlock(&fork[philo->myfork]) != 0)
			return (EXIT_FAILURE);
		if (philo->data->check_state == DIE \
		|| pthread_mutex_unlock(&fork[philo->notmyfork]) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_philoeat(t_philo *philo, pthread_mutex_t *fork)
{
	if (philo->data->check_state == DIE \
	|| ft_take_and_drop(philo, fork, TAKE) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_print(philo, PEAT);
	philo->nbr_ate++;
	philo->start_meal = current_time();
	time_to_action(philo->data->time_eat);
	if (ft_take_and_drop(philo, fork, DROP) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	*routine(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = main->id_cur;
	main->philo[i].start_meal = main->data.start_time;
	while (!main->data.check_state)
	{
		if (ft_philoeat(&main->philo[i], main->fork) == EXIT_FAILURE)
			break ;
		ft_sleep_think(&main->philo[i]);
	}
	return (NULL);
}

int	ft_crttheard(t_main *main)
{
	int	i;

	i = 0;
	main->data.start_time = current_time();
	while (i < main->data.nbr_philo)
	{
		main->id_cur = i;
		if (pthread_create(&main->philo[i].th, NULL, &routine, main))
			return (EXIT_FAILURE);
		if (pthread_detach(main->philo[i].th) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		usleep(10);
		i += 2;
		if (i >= main->data.nbr_philo && i % 2 == 0)
		{
			usleep (50);
			i = 1;
		}
	}
	return (EXIT_SUCCESS);
}
