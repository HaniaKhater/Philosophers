/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:19:06 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/08 00:19:24 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	ft_print_simulation(t_simu *d)
{
	ft_putstr("Number of philos + forks: ");
	ft_putnbr(d->nb);
	ft_putstr("\nTime to die: ");
	ft_putnbr(d->die);
	ft_putstr("\nTime to eat: ");
	ft_putnbr(d->eat);
	ft_putstr("\nTime to sleep: ");
	ft_putnbr(d->sleep);
	ft_putstr("\nNumber of meals: ");
	ft_putnbr(d->die);
	ft_putstr("\n");
}
