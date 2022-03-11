/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:36:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:36:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft.h"

volatile sig_atomic_t	g_rsignal;

void	sig_handler_server(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	g_rsignal = signal;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
}

/* Convert binary into a character. */
void	receive_bit(void)
{
	static int	c;
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
}

void	receive_message(void)
{
	while (1)
	{
		pause();
		receive_bit();
		g_rsignal = 0;
	}
}

int	main(void)
{
	int	svr_pid;

	svr_pid = (int)getpid();
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(svr_pid, 1);
	ft_putchar_fd('\n', 1);
	set_signal_handler(&sig_handler_server);
	receive_message();
	return (0);
}
