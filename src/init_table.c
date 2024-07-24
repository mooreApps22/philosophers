/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:26:25 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_table(char **av, t_table *t);
void	init_philo(t_table *t);

void	init_table(char **av, t_table *t)
{
	int	i;	

	i = -1;
	t->phil_ct = ft_atoi(av[1]);
	t->die_time = ft_atoi(av[2]);
	t->eat_time = ft_atoi(av[3]);
	t->sleep_time = ft_atoi(av[4]);
	t->max_meal_ct = 0;
	if (av[5])
		t->max_meal_ct = ft_atoi(av[5]);
	t->fork_mutex = ft_calloc(t->phil_ct, (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&t->log_mutex, NULL);
	pthread_mutex_init(&t->died_mutex, NULL);
	while (++i < t->phil_ct)
		pthread_mutex_init(&t->fork_mutex[i], NULL);
	t->p = ft_calloc(t->phil_ct, (sizeof(t_philo)));
	init_philo(t);
	t->st_time = start_timer_ms();
}

void	init_philo(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->phil_ct)
	{
		t->p[i].id = i + 1;
		t->p[i].meal_time = 0;
		t->p[i].meal_ct = 0;
		t->p[i].l_fork = i;
		t->p[i].r_fork = (i + 1) % t->phil_ct;
		t->p[i].av = t;
		i++;
	}
}
