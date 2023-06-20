/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:55:49 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 18:56:25 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
	res = (res * 10) + str[i] - '0';
	i++;
	}
	return (res);
}
