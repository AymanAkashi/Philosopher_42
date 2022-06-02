/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:04:24 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 21:26:43 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	ft_usleep(time_t time)
{
	time_t	start;

	start = get_time(0);
	while (get_time(0) - start < time)
		usleep(50);
}

time_t	get_time(time_t start)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (((1000 * tm.tv_sec) + (tm.tv_usec / 1000)) - start);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 1)
		ft_usleep(500);
	while (1)
	{
		ft_fork(philo);
		ft_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
