/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:00:11 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 17:40:34 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	ft_death_philo(t_philo *philo)
{
	if (check_philo_dead(philo) == TRUE
		|| philo->save_data->time_ate == philo->save_data->num_philo)
	{
		philo->save_data->set_someone_die = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	alloc_philo(t_philo **philo, t_data *data)
{
	*(philo) = ft_any_alloc(sizeof(t_philo), -data->num_philo);
	if (*(philo) == NULL)
	{
		ft_free_all(NULL, data, 3);
		return (FALSE);
	}
	return (TRUE);
}

int	run_process(t_philo *philo)
{
	pthread_create(&philo->thread, NULL, ft_routine, (void *)philo);
	pthread_detach(philo->thread);
	while (1)
	{
		if (check_philo_dead(philo) == TRUE)
			return (1);
		if (philo->save_data->time_ate == 1)
			return (2);
	}
	return (2);
}
