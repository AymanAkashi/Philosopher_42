/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:50:43 by akashi            #+#    #+#             */
/*   Updated: 2022/06/02 16:23:28 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0,
}		t_bool;

typedef struct s_data
{
	int				num_philo;
	int				all_time_eat;
	int				time_ate;
	int				id_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	t_bool			set_someone_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_cmd;
	time_t			init_time;
}		t_data;
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
}	t_philo;

//********write_cmd******************************/

void			time_to_x(time_t timestamp, int num_philo, char *str);

//****************************************************************
int				ft_atoi(const char *str);
int				check_arg(int ac, char **av);
t_bool			check_philo_dead(t_philo *philo);

t_bool			ft_fork(t_philo *philo, char c);
t_bool			ft_eat(t_philo *philo);
t_bool			ft_sleep(t_philo *philo);
t_bool			ft_unfork(t_philo *philo, char c);
t_bool			ft_think(t_philo *philo);
void			set_someone_die(time_t time, t_philo *philo);

void			*ft_any_alloc(size_t size, size_t len);
t_bool			ft_alloc_philo(t_philo *philo, t_data *data, int id);

t_bool			data_init(char **av, int ac, t_data *data);
void			init_philo(t_data *data, t_philo *philo, int i);
t_bool			create_thread(t_data *data, t_philo *philo);
void			*ft_routine(void *data);

time_t			get_time(time_t start);
pthread_mutex_t	*ft_allocation_mutex(int num_philo);
t_bool			ft_write_operation(t_philo *philo, char *str, time_t time);
void			ft_free_all(t_philo *philo, t_data *data, int n);
void			ft_usleep(time_t time);

#endif