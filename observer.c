/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:00:44 by macampos          #+#    #+#             */
/*   Updated: 2024/03/18 13:53:05 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observe(t_table *table)
{
	t_philosopher		*philo;

	philo = table->firstphilo;
	while (1)
	{
		pthread_mutex_lock(&table->write);
		if (philo->mealseaten >= table->meals && table->meals != -1)
		{
			pthread_mutex_unlock(&table->write);
			break;
		}
		if (get_time() - philo->last_meal > table->time_to_die)
		{
			table->dead = 1;
			pthread_mutex_unlock(&table->write);
			break ;
		}
		pthread_mutex_unlock(&table->write);
		philo = philo->next;
	}
	if (table->dead)
		printf("%llu %d died\n", get_time() - philo->table->start_time, philo->id
			+ 1);
	return (NULL);
}
