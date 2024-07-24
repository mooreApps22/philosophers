/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:51:05 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <memory.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>

// USAGE:		./philo num dietime eattime sleeptime [meal_ct]
// Timestamp	<ms> <id> <message>
// Death:		announce in less than 10 ms

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				phil_ct;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				max_meal_ct;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	died_mutex;
	t_philo			*p;
	int				error;
	int				dinner_over;
	int				goodnight;
	long long		st_time;
}				t_table;

typedef struct s_philo
{
	pthread_t	tid;
	int			id;
	int			meal_ct;
	long long	meal_time;
	int			r_fork;
	int			l_fork;
	t_table		*av;
}				t_philo;

// main
int			main(int ac, char **av);
//static void	free_data(t_table *t);
//static int	valid_args(int ac, char **av);

// init utils
int			is_space(char c);
int			ft_atoi(const char *s);
void		*ft_calloc(int n, size_t size);

// init data structions
void		init_table(char **av, t_table *t);
void		init_philo(t_table *t);

// philo acts
void		*philo_acts(void *p);
void		philo_eat(t_philo *ptr);
void		philo_sleep(t_philo *ptr);
void		philo_think(t_philo *ptr);
void		log_act(t_philo *p, char *s);

// seat table
void		seat_table(t_table *t);
//static void	medic(t_table *t);
//static void	check_pulse(t_philo *p);

// signal philo starves
void		*single_philo_starves(t_philo *p);

// time utils 
long long	start_timer_ms(void);
long long	timestamp_ms(t_table *av);
void		sleep_until(t_philo *ptr, int wait);
void		log_act(t_philo *p, char *s);

#endif
