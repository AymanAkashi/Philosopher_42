/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:10:11 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 17:40:45 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	ft_free_all(t_philo *philo, t_data *data, int n)
{
	if (n >= 0)
		free(data->pid);
	if (n >= 1)
		free(data);
	if (n >= 2)
		free(philo);
}

void	kill_process(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		kill(data->pid[i], SIGINT);
}
