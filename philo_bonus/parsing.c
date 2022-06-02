/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:10:37 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 19:00:30 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_bool	parsing(int ac, char **av, t_data **data, t_philo **philo)
{
	int	n;

	if (!check_arg(ac, av))
		return (FALSE);
	*data = ft_any_alloc(sizeof(t_data), 1);
	if (*data == NULL)
		return (FALSE);
	if (data_init(av, ac, *data) == FALSE)
	{
		ft_free_all(NULL, *data, 1);
		return (FALSE);
	}
	*philo = malloc(sizeof(t_philo) * (*data)->num_philo);
	if (*philo == NULL)
		return (free(*data), FALSE);
	n = -1;
	while (++n < (*data)->num_philo)
		init_philo((*data), &(*philo)[n], n);
	(*data)->pid = malloc(sizeof(pid_t) * (*data)->num_philo);
	if ((*data)->pid == NULL)
		return (ft_free_all(*philo, *data, 3), FALSE);
	return (TRUE);
}
