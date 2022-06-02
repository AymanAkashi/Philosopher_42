/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:33:42 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 20:06:34 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	ft_fork(t_philo *philo, char c)
{
	time_t	time;

	if (c == 'L')
		pthread_mutex_lock(&philo->save_data->fork[philo->left_hand]);
	if (c == 'R')
		pthread_mutex_lock(&philo->save_data->fork[philo->right_hand]);
	time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "has taken a fork\n", time);
	return (TRUE);
}

t_bool	ft_unfork(t_philo *philo, char c)
{
	if (c == 'R')
		pthread_mutex_unlock(&philo->save_data->fork[philo->right_hand]);
	if (c == 'L')
		pthread_mutex_unlock(&philo->save_data->fork[philo->left_hand]);
	return (TRUE);
}

t_bool	ft_eat(t_philo *philo)
{
	philo->currant_eat_time = get_time(philo->save_data->init_time);
	philo->last_time_eat = philo->currant_eat_time;
	ft_write_operation(philo, "is eating\n", philo->currant_eat_time);
	if (philo->last_time_eat == -1 || philo->currant_eat_time == -1)
		return (FALSE);
	usleep(philo->save_data->time_to_eat * 1000);
	philo->num_ate++;
	if (philo->num_ate == philo->save_data->all_time_eat)
		philo->save_data->time_ate++;
	return (TRUE);
}

t_bool	ft_sleep(t_philo *philo)
{
	time_t	time;

	time = get_time(philo->save_data->init_time);
	ft_write_operation(philo, "is sleeping\n", time);
	usleep(philo->save_data->time_to_sleep * 1000);
	return (TRUE);
}

t_bool	ft_think(t_philo *philo)
{
	time_t	time;

	time = get_time(philo->save_data->init_time);
	if (time == -1)
		return (FALSE);
	ft_write_operation(philo, "is thinking\n", time);
	return (TRUE);
}
