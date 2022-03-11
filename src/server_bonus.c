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
char	receive_bit(t_char *input)
{
	char		ret_c;

	if (g_rsignal == SIGUSR2)
		input->c |= (1 << input->i);
	input->i++;
	if (input->i == 8)
	{
		ret_c = input->c;
		input->c = 0;
		input->i = 0;
		return (ret_c);
	}
	return ('\0');
}

bool	is_timeout_sig(void)
{
	sleep(SIG_TIME_LIMIT);
	if (g_rsignal)
		return (false);
	return (true);
}

void	receive_message(void)
{
	t_char	input;
	char 	output_c;

	while (1)
	{
		ft_bzero(&input, sizeof(t_char));
		pause();
		while (1)
		{
			output_c = receive_bit(&input);
			if (output_c)
				write(1, &output_c, 1);
			g_rsignal = 0;
			if (output_c == EOT || is_timeout_sig() == true)
				break;
		}
	}
}

int	main(void)
{
	int	svr_pid;

	svr_pid = (int)getpid();
	print_pid(svr_pid);
	set_signal_handler(&sig_handler_server);
	receive_message();
	return (0);
}
