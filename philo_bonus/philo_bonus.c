/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:40:57 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 18:54:05 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	ft_end_processes(t_data *data, t_philo *philo)
{
	int	n;
	int	status;

	(void)philo;
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 1)
		kill_process(data);
	if (WEXITSTATUS(status) == 2)
	{
		n = 0;
		while (++n < data->num_philo)
			waitpid(-1, &status, 0);
	}
}

void	ft_end(t_data *data, t_philo *philo)
{
	(void)philo;
	sem_close(data->fork);
	sem_close(data->write_cmd);
	sem_unlink("fork");
	sem_unlink("cmd");
	ft_free_all(philo, data, 3);
}

void	starting(t_data *data)
{
	sem_unlink("fork");
	sem_unlink("cmd");
	data->fork = sem_open("fork", O_CREAT, 0644, data->num_philo);
	data->write_cmd = sem_open("cmd", O_CREAT, 0644, 1);
}

void	child_process(t_data *data, t_philo *philo, int n)
{
	if (run_process(&philo[n]) == 1)
	{
		ft_free_all(philo, data, 3);
		exit(1);
	}
	else
	{
		ft_free_all(philo, data, 3);
		exit(2);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		n;

	n = -1;
	data = NULL;
	if (parsing(ac, av, &data, &philo) == FALSE)
		return (0);
	starting(data);
	while (++n < data->num_philo)
	{
		data->pid[n] = fork();
		if (data->pid[n] == -1)
			exit(0);
		if (data->pid[n] == 0)
			child_process(data, philo, n);
	}
	ft_end_processes(data, philo);
	ft_end(data, philo);
	return (0);
}
