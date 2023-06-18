/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:19:21 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/18 20:05:25 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h> //usleep
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
#include "color.h"
//enum is group data of constant
enum error
{
    ERR_ARG
    
};

enum printarg
{
    PMYFORK
    ,PNOTMYFORK
    ,PEAT
    ,PSLEEP
    ,PTHINK
    ,PDIE
};

enum fork
{
    TAKE
    ,DROP   
};

enum state
{
    NOTDIE
    ,DIE


};

typedef struct  s_data
{
    int     nbr_philo;
    long     time_die;
    long     time_eat;
    long     time_sleep;
    int     nbr_eat;
    int     check_state;
    long        start_time; //??
    pthread_mutex_t print; // for lock print
    // long    start_meal;

}   t_data ;

typedef struct s_philo
{
    int         id; // start at 1 to nbr_philo
    int         myfork;
    int         notmyfork;
    int         nbr_ate;
    long        start_meal; //last_meal
    t_data      *data;
    pthread_t   th;  // t_id 1 : 1 philo

}   t_philo ;

typedef struct s_main
{
    int             id_cur;
    t_data          data;
    t_philo         *philo;
    pthread_mutex_t *fork; // fork 1 : 1 philo

} t_main ;

int             ft_check(int ac, char **av);
int             ft_checkarg(int ac);
int             ft_checkformat(int ac, char **av);
int             ft_isdigit(char c); //??


int             ft_printerr(int mode);
long             ft_atol(char *str);

int             ft_init(t_main *main, int ac, char **av);
void            ft_initdataphilo(t_data *data, int ac, char **av);
// int             ft_initdataphilo(t_data *data, int ac, char **av);
pthread_mutex_t *ft_initfork(int nbr_philo);
t_philo         *ft_initphilo(t_data *data);


int             ft_crttheard(t_main *main);
int             ft_sleep_think(t_philo *philo);


void            ft_print(t_philo *philo,int mode);

long            current_time(void);
int             time_to_action(long time_action, int *check_state);
long            time_diff(long time);

void            ft_checkdie (t_main *main);

void            ft_clear(t_main *main);
#endif