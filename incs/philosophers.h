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

typedef struct	s_simu
{
	int	nb;
	int	die;
	int	eat;
	int	sleep;
	int	meals;
}	t_simu;

typedef struct	s_philo
{
	int	nb;
	int	meal;
	int	rest;
	int	death;
	// int state? thought?
}
void	ft_putstr(char *str);
void	print_update(int nb);

#endif
