/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:27:10 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_acts(void *p);
void	philo_eat(t_philo *ptr);
void	philo_sleep(t_philo *ptr);
void	philo_think(t_philo *ptr);

void	*philo_acts(void *p)
{
	t_philo	*ptr;
	t_table	*t;

	ptr = (t_philo *)p;
	t = ptr->av;
	if (ptr->id % 2)
		usleep(1500);
	while (!t->dinner_over)
	{
		if (t->max_meal_ct > 0 && ptr->meal_ct == t->max_meal_ct)
			break ;
		philo_eat(ptr);
		philo_sleep(ptr);
		philo_think(ptr);
	}
	return (NULL);
}

void	philo_eat(t_philo *ptr)
{
	if (!ptr->av->dinner_over)
	{
		pthread_mutex_lock(&ptr->av->fork_mutex[ptr->l_fork]);
		log_act(ptr, "has taken a fork");
		pthread_mutex_lock(&ptr->av->fork_mutex[ptr->r_fork]);
		log_act(ptr, "has taken a fork");
		log_act(ptr, "is eating");
		ptr->meal_time = timestamp_ms(ptr->av);
		ptr->meal_ct += 1;
		sleep_until(ptr, ptr->av->eat_time);
		pthread_mutex_unlock(&ptr->av->fork_mutex[ptr->l_fork]);
		pthread_mutex_unlock(&ptr->av->fork_mutex[ptr->r_fork]);
	}
}

void	philo_sleep(t_philo *ptr)
{
	if (!ptr->av->dinner_over)
	{
		log_act(ptr, "is sleeping");
		sleep_until(ptr, ptr->av->sleep_time);
	}
}

void	philo_think(t_philo *ptr)
{
	if (!ptr->av->dinner_over)
		log_act(ptr, "is thinking");
}
