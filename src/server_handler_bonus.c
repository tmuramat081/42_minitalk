/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:43:32 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:32 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft.h"

#define SIG_INITIAL -1

volatile sig_atomic_t	g_received_signal;

void	sig_handler_server(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_received_signal == SIG_INITIAL)
		g_received_signal = info->si_pid;
	else
		g_received_signal = signal;
}

/* Convert binary into a character. */
void	receive_bit(t_char *input)
{
	if (g_received_signal == SIGUSR2)
		input->c |= (1 << input->i);
	input->i++;
	if (input->i == CHAR_BIT)
	{
		if (!input->c)
		{
			input->is_null = true;
			return ;
		}
		write(1, &input->c, 1);
		input->c = 0;
		input->i = 0;
	}
}

int	receive_client_pid(void)
{
	int	cli_pid;

	cli_pid = g_received_signal;
	kill(cli_pid, SIGUSR1);
	g_received_signal = 0;
	return (cli_pid);
}

void	receive_message(t_char input)
{
	int		cli_pid;

	cli_pid = receive_client_pid();
	while (is_timeout(SIG_TIME_LIMIT) == false)
	{
		receive_bit(&input);
		g_received_signal = 0;
		kill(cli_pid, SIGUSR1);
		if (input.is_null == true)
			return ;
	}
}

void	stand_by_for_message(void)
{
	t_char	input;

	while (1)
	{
		ft_bzero(&input, sizeof(t_char));
		g_received_signal = SIG_INITIAL;
		pause();
		receive_message(input);
	}
}
