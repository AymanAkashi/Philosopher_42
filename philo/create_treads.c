/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:00:11 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 21:17:17 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	check_philo_dead(t_philo *philo)
{
	time_t	now;
	int		time_death;

	time_death = philo->save_data->time_to_die;
	now = get_time(philo->save_data->init_time);
	if (now - philo->last_time_eat >= time_death + philo->last_time_eat)
	{
		ft_write_operation(philo, NULL, now);
		philo->save_data->set_someone_die = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_death_philo(t_philo *philo, int i, t_data *data)
{
	if (check_philo_dead(&philo[i]) == TRUE
		|| data->time_ate == data->num_philo)
		return (TRUE);
	return (FALSE);
}

t_bool	alloc_philo(t_philo **philo, t_data *data)
{
	*(philo) = ft_any_alloc(sizeof(t_philo), data->num_philo);
	if (*(philo) == NULL)
	{
		ft_free_all(NULL, data, 3);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	create_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->write_cmd, NULL);
	if (alloc_philo(&philo, data) == FALSE)
		return (FALSE);
	while (++i < data->num_philo)
	{
		init_philo(data, &philo[i], i);
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		pthread_detach(philo[i].thread);
		philo[i].last_time_eat = get_time(philo->save_data->init_time);
	}
	while (data->set_someone_die == FALSE)
	{
		if (i == data->num_philo)
			i = 0;
		if (check_philo_dead(&philo[i]) == TRUE
			|| data->time_ate == data->num_philo)
			return (ft_free_all(philo, data, 3), FALSE);
		i++;
	}
	return (FALSE);
}
