/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:30:50 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/16 06:30:54 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	ft_usleep(long int time_in_ms, t_simu *simu)
{
	long int	start;

	start = 0;
	start = ft_time();
	(void)simu;
	while ((ft_time() - start) < time_in_ms)
	{
		if (check_end(simu) == 1)
			break ;
		usleep(50);
	}
}

long int	ft_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_simu		simu;

	if (ac < 5 || ac > 6)
	{
		if (av < 5)
			printf("not enough arguments\n");
		if (av > 6)
			printf("too many arguments\n");
		return (1);
	}
	if (check_arg(av) == 1)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	if (!philo)
		return (-1);
	philo = file_struc(philo, &simu, av);
	start_philo(philo);
	free(philo);
	return (0);
}
