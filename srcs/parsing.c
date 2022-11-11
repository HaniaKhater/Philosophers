/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:15:25 by hkhater           #+#    #+#             */
/*   Updated: 2022/11/08 00:15:29 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;

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
	return (nb * sign);
}

int	ft_isdigit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	else
		return (0);
}

int	check_value(char *av)
{
	if (ft_atol(av) < INT_MIN || ft_atol(av) > INT_MAX
		|| ft_atol(av) == 0 || ft_strlen(av) == 0)
	{
		printf("incorrect input\n");
		return (1);
	}
	return (0);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (check_value(av[i]) == 1)
			return (1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || av[i][j] == '-')
			{
				printf("incorrect input\n");
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
