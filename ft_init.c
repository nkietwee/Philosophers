/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:40:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 19:50:05 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initdataphilo(t_data *data, int ac, char **av)
{
	data->nbr_philo = ft_atol(av[1]);
	data->time_die = ft_atol(av[2]);
	data->time_eat = ft_atol(av[3]);
	data->time_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->nbr_eat = ft_atol(av[5]);
	else
	data->nbr_eat = -1;
	data->check_state = NOTDIE;
}

t_philo	*ft_initphilo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].myfork = i;
		philo[i].notmyfork = (i + 1) % data->nbr_philo;
		philo[i].nbr_ate = 0;
		philo[i].data = data;
		i++;
	}
	return (philo);
}

pthread_mutex_t	*ft_initfork(int nbr_philo)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = NULL;
	fork = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < nbr_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

int	ft_init(t_main *main, int ac, char **av)
{
	ft_initdataphilo(&main->data, ac, av);
	if (main->data.nbr_philo == 0 || main->data.nbr_eat == 0)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	main->philo = ft_initphilo(&main->data);
	if (!main->philo)
		return (EXIT_FAILURE);
	main->fork = ft_initfork(main->data.nbr_philo);
	if (!main->fork)
		return (EXIT_FAILURE);
	pthread_mutex_init(&main->data.print, NULL);
	return (EXIT_SUCCESS);
}
