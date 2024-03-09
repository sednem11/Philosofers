/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:18:47 by macampos          #+#    #+#             */
/*   Updated: 2024/03/07 16:34:39 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_function(void *arg)
{
	
}

t_philosopher	initiate_philos(t_table *table)
{
	t_philosopher	*philos;
	t_philosopher	*philos;
}

void    initiate_values(t_table *table, int argc, char **argv)
{
	table->philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		table->meals = ft_atoi(argv[5]);
	table->start_time = gettime();
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philosophers);
	table->firstphilo = (table);
}

int main(int argc, char **argv)
{
	struct s_table	table;
	int n;
	int i;
	
	i = 0;
	n = argv[1];
	pthread_t	threads[n];
	
	if (argc == 5 || argc == 6)
	{
		initiate_values(&table, argc, argv);
	}
}
