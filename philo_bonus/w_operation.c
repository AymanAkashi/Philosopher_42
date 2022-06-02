/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:51:41 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/01 18:43:33 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	ft_write_operation(t_philo *philo, char *str, time_t time)
{
	sem_wait(philo->save_data->write_cmd);
	if (str == NULL)
	{
		printf("%ld  %d died\n", time, philo->id + 1);
		return (TRUE);
	}
	printf("%ld  %d %s", time, philo->id + 1, str);
	sem_post(philo->save_data->write_cmd);
	return (TRUE);
}
