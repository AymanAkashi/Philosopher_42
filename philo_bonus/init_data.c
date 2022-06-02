/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:35:19 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 16:10:08 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	data_init(char **av, int ac, t_data *data)
{
	int	i;

	i = 0;
	if (ac == 6)
	{
		data->all_time_eat = ft_atoi(av[ac - 1]);
		if (data->all_time_eat == 0)
			return (FALSE);
	}
	else
		data->all_time_eat = -1;
	data->id_philo = 0;
	data->time_ate = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->init_time = get_time(0);
	return (TRUE);
}

void	init_philo(t_data *data, t_philo *philo, int i)
{
	philo->last_time_eat = 0;
	philo->currant_eat_time = 0;
	philo->currant_die_timer = 0;
	philo->num_ate = 0;
	philo->id = i;
	philo->right_hand = i;
	philo->left_hand = (i + 1) % data->num_philo;
	philo->is_dead = (FALSE);
	philo->save_data = data;
}
