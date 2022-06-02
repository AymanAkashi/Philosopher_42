/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:33:42 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 17:41:03 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	ft_fork(t_philo *philo)
{
	time_t	time;

	sem_wait(philo->save_data->fork);
	time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "has taken a fork\n", time);
	return (TRUE);
}

t_bool	ft_eat(t_philo *philo)
{
	philo->currant_eat_time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "is eating\n", philo->currant_eat_time);
	philo->last_time_eat = get_time(philo->save_data->init_time);
	ft_usleep(philo->save_data->time_to_eat);
	philo->num_ate++;
	if (philo->num_ate == philo->save_data->all_time_eat)
		philo->save_data->time_ate++;
	sem_post(philo->save_data->fork);
	sem_post(philo->save_data->fork);
	return (TRUE);
}

t_bool	ft_sleep(t_philo *philo)
{
	time_t	time;

	time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "is sleeping\n", time);
	ft_usleep(philo->save_data->time_to_sleep);
	return (TRUE);
}

t_bool	ft_think(t_philo *philo)
{
	time_t	time;

	time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "is thinking\n", time);
	return (TRUE);
}
