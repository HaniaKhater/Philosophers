/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:15:54 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/08 00:15:57 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	check_end(t_simu *simu)
{
	int	end;

	pthread_mutex_lock(&simu->end_mtx);
	end = simu->end;
	pthread_mutex_unlock(&simu->end_mtx);
	return (end);
}

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->death_mtx);
	if (((ft_time() - philo->simu->start) - philo->last_meal) >= philo->simu->die)
	{
		print_update(philo, DIED, 1);
		pthread_mutex_lock(&philo->simu->end_mtx);
		philo->simu->end = 1;
		pthread_mutex_unlock(&philo->simu->end_mtx);
		pthread_mutex_unlock(&philo->simu->death_mtx);
		return (0);
	}
	pthread_mutex_unlock(&philo->simu->death_mtx);
	return (1);
}

int	check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->meal_mtx);
	if (philo->simu->done_meals == philo->simu->meals
		&& philo->simu->meals != 0)
	{
		pthread_mutex_lock(&philo->simu->end_mtx);
		philo->simu->end = 1;
		pthread_mutex_unlock(&philo->simu->end_mtx);
		pthread_mutex_unlock(&philo->simu->meal_mtx);
		return (0);
	}
	pthread_mutex_unlock(&philo->simu->meal_mtx);
	return (1);
}
