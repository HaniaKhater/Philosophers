/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:18:21 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/08 00:18:24 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

t_simu	*init_simu(t_simu *simu, char **av)
{
	simu->nb = ft_atol(av[1]);
	simu->die = ft_atol(av[2]);
	simu->eat = ft_atol(av[3]);
	simu->sleep = ft_atol(av[4]);
	if (av[5])
		simu->meals = ft_atol(av[5]);
	else
		simu->meals = 0;
	simu->start = 0;
	simu->done_meals = 0;
	simu->end = 0;
	return (simu);
}

t_philo	*init_philo(t_philo *philo, t_simu *simu, char **av)
{
	pthread_t	*thread;
	int			nb;
	int			i;

	thread = malloc(sizeof(pthread_t) * nb);
	nb = ft_atol(av[1]);
	i = -1;
	while (++i < nb)
	{
		philo[i].simu = init_simu(simu, av);
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].eaten = 0;
		philo[i].thread = thread[i];
		pthread_mutex_init(&philo[i].l_fork, NULL);
		if (i == nb - 1)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
	}
	free(thread);
	return (philo);
}
