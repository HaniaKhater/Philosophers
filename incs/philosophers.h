/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:31:09 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/16 06:51:01 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define DIED		"died\n"
# define FORK		"has taken a fork\n"
# define ATE		"is eating\n"
# define SLEPT		"is sleeping\n"
# define THOUGHT	"is thinking\n"

typedef struct	s_simu
{
	int			nb;
	long int	die;
	long int	eat;
	long int	sleep;
	int			meals;
	int			done_meals;
	long int	start;
	pthread_mutex_t	update_mtx;
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	end_mtx;
	int				end;
}	t_simu;

typedef struct	s_philo
{
	struct s_simu	*simu;

	int	id;
	int	last_meal;
	int	to_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;

int			check_arg(char **av);
int			ft_strlen(char *str);
t_philo		*init_philo(t_philo *philo, t_simu *simu, char **av);
long		ft_atol(const char *s);
long int	ft_time(void);
void		start_philo(t_philo *philo);
void		create_thread(t_philo *philo);
void		take_fork(t_philo *philo);
void		print_update(t_philo *philo, char *msg, int check_die);
void		ft_usleep(long int time_in_ms, t_simu *simu);
int			check_end(t_simu *simu);
int			check_dead(t_philo *philo);
int			check_eat(t_philo *philo);

#endif
