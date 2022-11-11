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

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_simu		simu;

	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("not enough arguments\n");
		if (ac > 6)
			printf("too many arguments\n");
		return (1);
	}
	if (check_arg(av) == 1)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	if (!philo)
		return (-1);
	philo = init_philo(philo, &simu, av);
	start_philo(philo);
	free(philo);
	return (0);
}
