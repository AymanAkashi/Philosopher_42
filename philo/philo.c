/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:28:56 by akashi            #+#    #+#             */
/*   Updated: 2022/06/02 19:41:05 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	philo = NULL;
	if (!check_arg(ac, av))
		return (0);
	data = ft_any_alloc(sizeof(t_data), 1);
	if (data == NULL)
		return (1);
	if (data_init(av, ac, data) == FALSE)
		return (0);
	create_thread(data, philo);
	return (0);
}
