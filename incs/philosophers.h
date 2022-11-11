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
	int	nb;
	int	die;
	int	eat;
	int	sleep;
	int	meals;
	int	done_meals;
	int	start;
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
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;

void	ft_putstr(char *s);
void	print_update(int nb);

#endif
