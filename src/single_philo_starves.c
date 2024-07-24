/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo_starves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/23 16:34:13 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*single_philo_starves(t_philo *p);

void	*single_philo_starves(t_philo *p)
{
	t_philo	*ptr;

	ptr = (t_philo *)p;
	pthread_mutex_lock(&ptr->av->fork_mutex[ptr->r_fork]);
	log_act(ptr, "has taken a fork");
	ptr->meal_time = timestamp_ms(ptr->av);
	sleep_until(ptr, ptr->av->die_time);
	log_act(ptr, "died");
	ptr->av->dinner_over = 1;
	return (NULL);
}
