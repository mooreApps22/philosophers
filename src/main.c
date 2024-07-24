/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:43:26 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int			main(int ac, char **av);
static int	valid_args(int ac, char **av);
static void	free_data(t_table *t);

int	main(int ac, char **av)
{
	t_table	*t;

	if (valid_args(ac, av) != 0)
		return (-1);
	t = ft_calloc(1, sizeof(t_table));
	if (!t)
		return (-1);
	init_table(av, t);
	seat_table(t);
	free_data(t);
	return (0);
}

static int	valid_args(int ac, char **av)
{
	int	n;

	if (ac != 5 && ac != 6)
	{
		printf("Usage: <phil_ct> <die> <eat> <sleep> <optional: max>\n");
		return (-1);
	}
	n = ft_atoi(av[1]);
	if (n > 200)
	{
		printf("The max number of philosophers is 200\n");
		return (-1);
	}
	return (0);
}

static void	free_data(t_table *t)
{
	int	i;

	i = t->phil_ct;
	while (--i >= 0)
		pthread_join(t->p[i].tid, NULL);
	while (++i < t->phil_ct)
		pthread_mutex_destroy(&t->fork_mutex[i]);
	pthread_mutex_destroy(&t->log_mutex);
	pthread_mutex_destroy(&t->died_mutex);
	free(t->p);
	free(t->fork_mutex);
	free(t);
}
