/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:51:41 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/01 17:45:44 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	ft_write_operation(t_philo *philo, char *str, time_t time)
{
	pthread_mutex_lock(&philo->save_data->write_cmd);
	if (str == NULL)
	{
		printf("%ld  %d died\n", time, philo->id + 1);
		return (TRUE);
	}
	printf("%ld  %d %s", time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->save_data->write_cmd);
	return (TRUE);
}
