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

void	ft_usleep(long int time_in_ms, t_utils_arg *info)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	(void)info;
	while ((actual_time() - start_time) < time_in_ms)
	{
		if (check_stop(info) == 1)
			break ;
		usleep(50);
	}
}

long int	actual_time(void)
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
	t_utils_philo	*philo;
	t_utils_arg		info;

	if (ac > 6 || ac < 5)
	{
		printf("wrong argument\n");
		return (1);
	}
	if (check_arg(av) == 1)
		return (1);
	philo = malloc(sizeof(t_utils_philo) * ft_atol(av[1]));
	if (!philo)
		return (-1);
	philo = file_struc(philo, &info, av);
	start_philo(philo);
	free(philo);
	return (0);
}
