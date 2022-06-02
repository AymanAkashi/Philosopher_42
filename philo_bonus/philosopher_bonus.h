/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:35:50 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/06/02 18:10:58 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

typedef struct s_data
{
	int		num_philo;
	int		all_time_eat;
	int		time_ate;
	int		id_philo;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	t_bool	set_someone_die;
	sem_t	*fork;
	sem_t	*write_cmd;
	time_t	init_time;
	pid_t	*pid;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left_hand;
	int			right_hand;
	int			num_ate;
	pthread_t	thread;
	time_t		last_time_eat;
	time_t		currant_die_timer;
	time_t		currant_eat_time;
	t_data		*save_data;
	t_bool		is_dead;
}		t_philo;

int		check_arg(int ac, char **av);
int		ft_atoi(const char *str);
void	*ft_any_alloc(size_t size, size_t len);
t_bool	data_init(char **av, int ac, t_data *data);
void	init_philo(t_data *data, t_philo *philo, int i);
void	*ft_routine(void *data);
time_t	get_time(time_t start);

t_bool	ft_fork(t_philo *philo);
t_bool	ft_unfork(t_philo *philo);
t_bool	ft_eat(t_philo *philo);
t_bool	ft_sleep(t_philo *philo);
t_bool	ft_think(t_philo *philo);
void	ft_usleep(time_t time);

t_bool	parsing(int ac, char **av, t_data **data, t_philo **philo);

t_bool	ft_create_thread_philo(t_philo *philo);
t_bool	ft_death_philo(t_philo *philo);
t_bool	alloc_philo(t_philo **philo, t_data *data);

void	ft_free_all(t_philo *philo, t_data *data, int n);
t_bool	check_philo_dead(t_philo *philo);
t_bool	ft_write_operation(t_philo *philo, char *str, time_t time);
void	ft_putstr_fd(char *s, int fd);
void	kill_process(t_data *data);
int		run_process(t_philo *philo);

#endif