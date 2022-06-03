/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:04:24 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/03 21:13:40 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
		usleep(50);
	while (1)
	{
		ft_fork(philo, 'R');
		ft_fork(philo, 'L');
		ft_eat(philo);
		ft_unfork(philo, 'R');
		ft_unfork(philo, 'L');
		ft_sleep(philo);
		ft_think(philo);
	}
}
