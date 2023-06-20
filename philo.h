/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:19:21 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/20 19:38:12 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "color.h"

enum e_printarg
{
	PMYFORK,
	PNOTMYFORK,
	PEAT,
	PSLEEP,
	PTHINK,
	PDIE,
};
enum e_fork
{
	TAKE,
	DROP
};
enum e_state
{
	NOTDIE,
	DIE
};
typedef struct s_data
{
	int				nbr_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				nbr_eat;
	int				check_state;
	long			start_time;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				myfork;
	int				notmyfork;
	int				nbr_ate;
	long			start_meal;
	t_data			*data;
	pthread_t		th;
}	t_philo;

typedef struct s_main
{
	int				id_cur;
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*fork;
}	t_main;

int				ft_check(int ac, char **av);
int				ft_checkarg(int ac);
int				ft_checkformat(char **av);
int				ft_isdigit(char c);

int				ft_printerr(int mode);
long			ft_atol(char *str);

int				ft_init(t_main *main, int ac, char **av);
void			ft_initdataphilo(t_data *data, int ac, char **av);
pthread_mutex_t	*ft_initfork(int nbr_philo);
t_philo			*ft_initphilo(t_data *data);

int				ft_crttheard(t_main *main);
void			ft_sleep_think(t_philo *philo);

void			ft_print(t_philo *philo, int mode);

//time.c
long			current_time(void);
void			time_to_action(long time_action);
long			time_diff(long time);

//check_die.c
void			ft_checkdie(t_main *main);

//clear
void			ft_clear(t_main *main);
#endif