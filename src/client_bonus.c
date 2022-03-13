/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:36:48 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:36:48 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "system_message.h"
#include "libft.h"

volatile sig_atomic_t	g_received_signal;

void	sig_handler_client(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_received_signal = signal;
}

/* Send signals with SIGUSR1(bit off) and SIGUSR2(bit on). */
void	send_bit(pid_t svr_pid, char c)
{
	unsigned int	i;

	i = 0;
	while (i < 8)
	{
		g_received_signal = 0;
		if (((c >> i) & 1) == 0)
			kill(svr_pid, SIGUSR1);
		else
			kill(svr_pid, SIGUSR2);
		if (is_timeout(SIG_TIME_LIMIT) == true)
			print_error_and_exit(MSG_SIG_ERR);
		i++;
	}
}

void	send_client_pid(pid_t svr_pid)
{
	kill(svr_pid, SIGUSR1);
	if (is_timeout(SIG_TIME_LIMIT) == true)
		print_error_and_exit(MSG_SIG_ERR);
}

/* After sendng all the characters, send EOT(End Of Transmission) signal. */
void	send_message(pid_t svr_pid, const char *str)
{
	send_client_pid(svr_pid);
	while (*str != '\0')
	{
		send_bit(svr_pid, *str);
		str++;
	}
	send_bit(svr_pid, EOT);
	ft_putendl_fd(MSG_REC_ACK, 1);
}

int	main(int argc, char **argv)
{
	pid_t	svr_pid;

	if (argc != 3)
		print_error_and_exit(MSG_ARG_ERR);
	svr_pid = input_pid(argv[1]);
	set_signal_handler(&sig_handler_client);
	send_message(svr_pid, argv[2]);
	return (0);
}
