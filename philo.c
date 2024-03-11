/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:36:04 by macampos          #+#    #+#             */
/*   Updated: 2024/03/09 17:36:44 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*free_philos(t_philosopher *philo)
{
	t_philosopher	*temp;

	while(temp != NULL)
	{
		temp = philo->next;
		free(philo);
		philo = temp;
	}
	return(NULL);
}

t_philosopher	*create_philo(t_table *table, int id)
{
	t_philosopher *philo;

	philo = malloc(sizeof(t_philosopher));
	philo->id = id;
	philo->dead = 0;
	philo->mealseaten = 0;
	philo->table = table;
	philo->next = NULL;
	philo->myfork = &table->forks[id];
	philo->leftfork = &table->forks[(id + 1) % table->philosophers];
	return (philo);
}

t_philosopher	*initiate_philos(t_table *table)
{
	int				i;
	t_philosopher	*philos;
	t_philosopher	*philo;

	i = 0;
	philo = NULL;
	philos = NULL;
	while(i < table->philosophers)
	{
		if(philo)
		{
			philo->next = create_philo(table, i);
			philo = philo->next;
		}
		else
			philo = create_philo(table, i);
		if (!philo)
			return(free_philos(table));
		if (!philos)
			philos = philo;
		philo->next = philos;
		i++;
	}
	return(philos);
}
