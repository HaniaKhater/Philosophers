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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		nb *= -1;
	return (nb);
}

void	ft_parse(t_simu *d, char **av)
{
	d->nb = ft_atoi(av[1]);
	d->die = ft_atoi(av[2]);
	d->eat = ft_atoi(av[3]);
	d->sleep = ft_atoi(av[4]);
	if (av[5])
		d->meals = ft_atoi(av[5]); 
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		write(1, "(null)", 6);
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);
}

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
