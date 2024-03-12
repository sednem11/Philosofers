/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:33:12 by macampos          #+#    #+#             */
/*   Updated: 2024/03/11 17:45:31 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_forks(pthread_mutex_t *myfork, pthread_mutex_t *leftfork)
{
	if (myfork)
		pthread_mutex_unlock(myfork);
	if (leftfork)
		pthread_mutex_unlock(leftfork);
}

void	take_forks(t_philosopher *philo, int *dead)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->leftfork);
		if (*dead || philo->table->philosophers == 1)
		{
			*dead = 1;
			return (unlock_forks(NULL, philo->leftfork));
		}
		pthread_mutex_lock(philo->myfork);
		if (*dead)
			unlock_forks(philo->myfork, philo->leftfork);		
		return ;
	}
	pthread_mutex_lock(philo->leftfork);
	if (*dead)
	{
		*dead = 1;
		return (unlock_forks(NULL, philo->leftfork));
	}
	pthread_mutex_lock(philo->myfork);
	if (*dead)
		unlock_forks(philo->myfork, philo->leftfork);
}

int		eat(t_philosopher *philo, int *dead)
{
	take_forks(philo, &dead);
	if (*dead)
		return(0);
	_usleep(philo->table->time_to_eat);
	
}

void	*philo_function(t_philosopher *philo)
{
	int		dead;

	dead = 0;
	while(!philo->dead)
	{
		if (philo->table->dead)
			break;
		if(!eat(philo, &dead))
			break;
	}
}
void    routine_start(t_table *table)
{
	t_philosopher   *philo;

	philo = table->firstphilo;
	while(philo)
	{
		if(philo->id % 2 == 0)
			pthread_create(philo->thread, NULL, philo_function, philo);
		philo = philo->next;
		if(philo == table->firstphilo)
			break;   
	}
	philo = table->firstphilo->next;
	while(philo)
	{
		if (philo->id % 2 == 1)
			pthread_create(philo->thread, NULL, philo_function, philo);
		philo = philo->next;
		if (philo == table->firstphilo)
			break;
	}
}
