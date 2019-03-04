/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:41:08 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/02/03 23:09:00 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg g_msg;

void			get_bit_by_bit(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 7)
	{
		ft_putchar(g_msg.c);
		if (!g_msg.c)
			ft_putchar('\n');
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int				main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	ft_putstr("server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, get_bit_by_bit);
		signal(SIGUSR1, get_bit_by_bit);
		pause();
	}
}
