/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:19:21 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/03 18:02:46 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//enum is group data of constant
enum error
{
    ERR_ARG
    
};

enum arg
{
    MYFORK
    ,NOTMYFORK
    ,EAT
    
};

enum fork
{
    TAKE
    ,DROP
    
};

typedef struct  s_data
{
    int nbr_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int nbr_eat;

}   t_data ;

typedef struct s_philo
{
    int         id; // start at 1 to nbr_philo
    int         myfork;
    int         notmyfork;
    int         nbr_ate;
    int         check_state;
    long        start_time;
    t_data      *data;
    pthread_t   th;  // t_id 1 : 1 philo

}   t_philo ;

typedef struct s_main
{
    int             i;
    t_data          data;
    t_philo         *philo;
    pthread_mutex_t *fork; // fork 1 : 1 philo

} t_main ;

int ft_check(int ac, char **av);
int ft_checkarg(int ac);
int ft_checkformat(int ac, char **av);
int ft_isdigit(char c); //??


int     ft_printerr(int mode);
int     ft_atoi(char *str);

int     ft_init(t_main *main, int ac, char **av);
int     ft_initdataphilo(t_data *data, int ac, char **av);
pthread_mutex_t *ft_initfork(int nbr_philo);
t_philo *ft_initphilo(t_data *data);


int ft_crttheard(t_main *main);




void    ft_print(int id, long time, int mode);


long    current_time(void);

#endif