/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:16:04 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/11 07:16:41 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (check_end(philo->simu) == 0)
		take_fork(philo);
	return (NULL);
}

void	end_prog(t_philo *philo)
{
	int	j;

	j = 0;
	while (check_end(philo->simu) == 0)
	{
		if (check_dead(&philo[j]) == 0 || check_eat(philo) == 0)
		{
			j = 0;
			while (j < philo->simu->nb)
			{
				pthread_join(philo[j].thread, NULL);
				j++;
			}
			j = -1;
			while (++j < philo->simu->nb)
				pthread_mutex_destroy(&philo[j].l_fork);
			pthread_mutex_destroy(&philo->simu->meal_mtx);
			pthread_mutex_destroy(&philo->simu->update_mtx);
			pthread_mutex_destroy(&philo->simu->death_mtx);
			pthread_mutex_destroy(&philo->simu->end_mtx);
			return ;
		}
	}
}

void	create_thread(t_philo *philo)
{
	int	j;

	j = 0;
	while (j < philo->simu->nb)
	{
		pthread_create(&philo[j].thread, NULL, &routine, &philo[j]);
		usleep(2000);
		j++;
	}
	end_prog(philo);
}

void	start_philo(t_philo *philo)
{
	philo->simu->start = ft_time();
	pthread_mutex_init(&philo->simu->update_mtx, NULL);
	pthread_mutex_init(&philo->simu->death_mtx, NULL);
	pthread_mutex_init(&philo->simu->meal_mtx, NULL);
	pthread_mutex_init(&philo->simu->end_mtx, NULL);
	create_thread(philo);
}
