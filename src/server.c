/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:57:53 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:57:53 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

volatile sig_atomic_t	g_rsignal;

void	signal_handler(int signal)
{
	g_rsignal = signal;
}

/* Convert binary into a character. */
void	receive_bit(void)
{
	static char	c;
	static int	i;

	if (g_rsignal == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	return ;
}

void	receive_message(void)
{
	while (1)
	{
		pause();
		receive_bit();
	}
}

int	main(void)
{
	pid_t	svr_pid;

	svr_pid = getpid();
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(svr_pid, 1);
	ft_putchar_fd('\n', 1);
	set_signal_handler(&signal_handler);
	receive_message();
	return (0);
}
