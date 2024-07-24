/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/07/24 16:24:44 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(int n, size_t size);
int		ft_atoi(const char *s);
int		is_space(char c);

void	*ft_calloc(int n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, (n * size));
	return (ptr);
}

int	ft_atoi(const char *s)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = (n * 10) + (*s - '0');
		s++;
	}
	return (sign * n);
}

int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}
