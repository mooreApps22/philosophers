/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:24:06 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	start_timer_ms(void);
long long	timestamp_ms(t_table *av);
void		sleep_until(t_philo *ptr, int wait_time);
void		log_act(t_philo *p, char *s);

long long	start_timer_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000LL) + (tp.tv_usec / 1000));
}

long long	timestamp_ms(t_table *av)
{
	struct timeval	tp;	

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000LL + (tp.tv_usec / 1000)) - av->st_time);
}

void	sleep_until(t_philo *ptr, int wait_time)
{
	long long	cur_time;
	long long	time_diff;

	cur_time = timestamp_ms(ptr->av);
	while (1)
	{
		time_diff = (timestamp_ms(ptr->av) - cur_time);
		if (time_diff >= wait_time)
			break ;
		usleep(1000);
	}
}

void	log_act(t_philo *p, char *s)
{
	if (!p->av->dinner_over)
	{
		pthread_mutex_lock(&p->av->log_mutex);
		printf("_________________________________\n");
		printf("%lldms P# %d %s\n", timestamp_ms(p->av), p->id, s);
		pthread_mutex_unlock(&p->av->log_mutex);
	}
}
