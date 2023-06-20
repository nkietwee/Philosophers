/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 19:17:17 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void	ft_print(t_philo *philo, int mode)
{
	long	time;

	time = current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->check_state == NOTDIE)
	{
		printf(BBLU"%ld ms " RESET, time);
		if (mode == PMYFORK)
			printf("Philo %d takemyfork\n", philo->id);
		else if (mode == PNOTMYFORK)
			printf("Philo %d notmyfork\n", philo->id);
		else if (mode == PEAT)
			printf("Philo %d eat\n", philo->id);
		else if (mode == PSLEEP)
			printf("Philo %d sleep\n", philo->id);
		else if (mode == PTHINK)
			printf("Philo %d think\n", philo->id);
		else if (mode == PDIE)
			printf("Philo %d die\n", philo->id);
	}
	pthread_mutex_unlock(&philo->data->print);
}
