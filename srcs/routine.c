/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:16:50 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/08 00:16:54 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	print_update(t_philo *philo, char *msg, int death_check)
{
	int	dead;

	pthread_mutex_lock(&philo->simu->update_mtx);
	dead = 0;
	if (dead == 0)
	{
		if (death_check == 1)
			dead = 1;
		if (check_end(philo->simu) != 1)
			printf("%ld %d %s",
				ft_time() - philo->simu->start, philo->id, msg);
		pthread_mutex_unlock(&philo->simu->update_mtx);
	}
	else
		pthread_mutex_unlock(&philo->simu->update_mtx);
}

void
	mutex_fork(t_philo *philo, pthread_mutex_t *rf, pthread_mutex_t *lf)
{
	pthread_mutex_lock(lf);
	print_update(philo, FORK, 0);
	pthread_mutex_lock(rf);
	print_update(philo, FORK, 0);
	print_update(philo, ATE, 0);
	pthread_mutex_lock(&philo->simu->death_mtx);
	philo->last_meal = ft_time() - philo->simu->start;
	pthread_mutex_unlock(&philo->simu->death_mtx);
	pthread_mutex_lock(&philo->simu->meal_mtx);
	if (philo->eaten < philo->simu->meals)
		philo->eaten++;
	if (philo->eaten == philo->simu->meals && philo->simu->meals != 0)
		philo->simu->done_meals++;
	pthread_mutex_unlock(&philo->simu->meal_mtx);
	ft_usleep(philo->simu->eat, philo->simu);
	pthread_mutex_unlock(rf);
	pthread_mutex_unlock(lf);
	print_update(philo, SLEPT, 0);
	ft_usleep(philo->simu->sleep, philo->simu);
	print_update(philo, THOUGHT, 0);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;

	l_fork = &philo->l_fork;
	r_fork = philo->r_fork;
	if (philo->simu->nb == 1)
	{
		pthread_mutex_lock(&philo->l_fork);
		print_update(philo, FORK, 0);
		ft_usleep(philo->simu->die, philo->simu);
		pthread_mutex_unlock(&philo->l_fork);
		return ;
	}
	if (philo->id == philo->simu->nb)
	{
		l_fork = philo->r_fork;
		r_fork = &philo->l_fork;
	}
	mutex_fork(philo, r_fork, l_fork);
}
