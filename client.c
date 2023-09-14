/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:16:24 by fatturan          #+#    #+#             */
/*   Updated: 2023/08/17 14:27:01 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		{
			sign *= -1;
			i++;
		}
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + s[i] - 48; 
		i++;
	}
	return (res * sign);
}

void	send_bits(int pid, char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		j = 7;
		while (j >= 0)
		{
			if (((c >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bits(pid, av[2]);
	}
	return (0);
}
