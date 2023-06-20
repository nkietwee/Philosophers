/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:48:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 16:19:21 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

void	time_to_action(long time_action)
{
	long	start;

	start = current_time();
	while ((current_time() - start < time_action))
		usleep(50);
}

long	time_diff(long time)
{
	return (current_time() - time);
}
