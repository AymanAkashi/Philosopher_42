/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:08:00 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/03 21:15:44 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	check_philo_dead(t_philo *philo)
{
	time_t	now;
	int		time_death;

	time_death = philo->save_data->time_to_die;
	now = get_time(philo->save_data->init_time);
	if (now - philo->last_time_eat >= time_death)
	{
		ft_write_operation(philo, NULL, now);
		philo->save_data->set_someone_die = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
