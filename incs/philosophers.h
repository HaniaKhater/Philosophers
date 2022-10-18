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

typedef struct	s_simu
{
	int	nb;
	int	die;
	int	eat;
	int	sleep;
	int	meals;
}	t_simu;

void	ft_putstr(char *str);
void	print_update(int nb);

#endif
