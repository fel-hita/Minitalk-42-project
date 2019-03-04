/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:52:12 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/03 23:22:28 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		send_bit_by_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((msg[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		pid = atoi(av[1]);
		send_bit_by_bit(pid, av[2], ft_strlen(av[2]));
	}
	else
		ft_putstr("usage: client server_pid msg_to_send\n");
	return (0);
}
