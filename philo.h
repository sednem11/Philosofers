#ifndef PHILO_H
# define PHILO_h
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef	unsigned long long	t_time;

typedef struct s_philosopher	t_philosopher;

typedef struct s_table
{
    int     		philosophers;
    int     		meals;
	int				dead;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			time_to_die;
	t_time			start_time;
    pthread_mutex_t *forks;
	pthread_mutex_t	write;
    t_philosopher 	*firstphilo;
}   				t_table;

typedef struct  s_philosopher
{
    pthread_mutex_t	*myfork;
    pthread_mutex_t	*leftfork;
    int 			dead;
	int				id;
	int				mealseaten;
	t_table			*table;
	pthread_t		thread;
    t_philosopher	*next;
}					t_philosopher;

int		ft_atoi(const char *str);

#endif