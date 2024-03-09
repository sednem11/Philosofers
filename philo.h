#ifndef PHILO_H
# define PHILO_h
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef	unsigned long long	t_time;

typedef struct s_philosophers	t_philosophers;

typedef struct s_table
{
    int     		philosophers;
    int     		meals;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			time_to_die;
	t_time			start_time;
    pthread_mutex_t *forks;
    t_philosopher 	*firstphilo;
}   				t_table;


typedef struct  s_philosopher
{
    pthread_mutex_t *myfork;
    pthread_mutex_t *leftfork;
    int dead;
    t_philosopher *next;
}   t_philosopher;

int		ft_atoi(const char *str);

#endif