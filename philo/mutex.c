/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:23:57 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 19:01:30 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	ft_mutex_init(pthread_mutex_t *mutex)
{
	int	error;

	error = pthread_mutex_init(mutex, NULL);
	if (error)
		return (FALSE);
	return (TRUE);
}

pthread_mutex_t	*ft_allocation_mutex(int num_philo)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = ft_any_alloc(sizeof(pthread_mutex_t), num_philo);
	if (mutex == NULL)
		return (NULL);
	while (i < num_philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (mutex);
}
