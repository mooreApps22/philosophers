/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seat_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:49:37 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void		seat_table(t_table *t);
static void	medic(t_table *t);
static void	check_pulse(t_philo *p);

void	seat_table(t_table *t)
{
	int	i;

	printf("=================================\n");
	printf("Ms	Philo	Message\n");
	if (t->phil_ct == 1)
		single_philo_starves(t->p);
	else
	{
		i = -1;
		while (++i < t->phil_ct)
			pthread_create(&t->p[i].tid, NULL, &philo_acts, (void *)&t->p[i]);
		while (!t->dinner_over)
			medic(t);
	}
}

static void	medic(t_table *t)
{
	int	meal_ct;
	int	i;

	meal_ct = 0;
	i = 0;
	while (!t->dinner_over)
	{
		check_pulse(&t->p[i]);
		if (t->max_meal_ct > 0)
		{
			while (meal_ct < t->phil_ct)
			{
				if (t->p[meal_ct].meal_ct < t->max_meal_ct)
					break ;
				meal_ct++;
			}
			if (meal_ct == t->phil_ct)
				t->dinner_over = 1;
		}
		usleep(5000);
		if (i == t->phil_ct - 1)
			i = -1;
		i++;
	}
}

static void	check_pulse(t_philo *p)
{
	pthread_mutex_lock(&p->av->died_mutex);
	if ((timestamp_ms(p->av) - p->meal_time) >= p->av->die_time)
	{
		log_act(p, "died");
		p->av->dinner_over = 1;
	}
	pthread_mutex_unlock(&p->av->died_mutex);
}
