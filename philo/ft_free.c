/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:10:11 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/01 17:16:27 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_free_mutex(pthread_mutex_t *mutex, int id)
{
	int	i;

	i = 0;
	while (i < id)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
}

void	ft_free_all(t_philo *philo, t_data *data, int n)
{
	if (n == 0)
		free(data);
	if (n >= 1)
	{
		ft_free_mutex(data->fork, data->num_philo);
		pthread_mutex_destroy(&data->write_cmd);
	}
	if (n >= 2)
		free(data);
	if (n >= 3)
		free(philo);
}
