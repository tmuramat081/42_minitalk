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

volatile sig_atomic_t	g_receive_signal;

void	sig_handler_server(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_receive_signal == -1)
		g_receive_signal = info->si_pid;
	else
		g_receive_signal = signal;
}

/* Convert binary into a character. */
char	receive_bit(t_char *input)
{
	char		ret_c;

	if (g_receive_signal == SIGUSR2)
		input->c |= (1 << input->i);
	g_receive_signal = 0;
	input->i++;
	if (input->i == 8)
	{
		ret_c = input->c;
		ft_bzero(input, sizeof(t_char));
		return (ret_c);
	}
	return (0);
}

int	receive_client_pid()
{
	int 	cli_pid;

	cli_pid = g_receive_signal;
	kill(cli_pid, SIGUSR1);
	g_receive_signal = 0;
	return (cli_pid);
}

void	receive_message(t_char input)
{
	int 	cli_pid;
	char	output_c;

	cli_pid = receive_client_pid();
	while (is_timeout() == false)
	{
		output_c = receive_bit(&input);
		kill(cli_pid, SIGUSR1);
		if (output_c == EOT)
			break ;
		else if (output_c)
			write(1, &output_c, 1);
	}
}

int	main(void)
{
	int		svr_pid;
	t_char	input;

	svr_pid = (int)getpid();
	print_pid(svr_pid);
	set_signal_handler(&sig_handler_server);
	while (1)
	{
		ft_bzero(&input, sizeof(t_char));
		g_receive_signal = -1;
		pause();
		receive_message(input);
	}
	return (0);
}
