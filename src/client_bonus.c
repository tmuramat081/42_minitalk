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
#include "libft.h"

volatile sig_atomic_t	g_receive_signal;

void	sig_handler_client(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_receive_signal = signal;
}

/* Wait an ACK signal from the server. */
bool	is_timeout_ack(int send_signal)
{
	int time_limit;
	time_limit =SIG_C_TIME_LIMIT;
	
	while (time_limit--)
	{
		if (send_signal == SIGUSR1 && g_receive_signal == SIGUSR1)
			return (false);
		else if (send_signal == SIGUSR2 && g_receive_signal == SIGUSR2)
			return (false);
		usleep(10);
	}
	return (true);
}

/* Send signals with SIGUSR1(bit off) and SIGUSR2(bit on). */
void	send_bit(pid_t svr_pid, char c)
{
	int	i;
	int	send_signal;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 0)
			send_signal = SIGUSR1;
		else
			send_signal = SIGUSR2;
		kill(svr_pid, send_signal);
		if (is_timeout_ack(send_signal) == true)
			print_error_and_exit(MSG_SIG_ERR);
		usleep(SIG_INTARVAL);
		g_receive_signal = 0;
		i++;
	}
}

/* After sendng all the characters, send EOT(End Of Transmission) signal. */
void	send_message(pid_t svr_pid, const char *str)
{
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
	int	svr_pid;

	if (argc != 3 || argv[2] == NULL)
		print_error_and_exit(MSG_ARG_ERR);
	svr_pid = ft_atoi(argv[1]);
	if (svr_pid <= 0)
		print_error_and_exit(MSG_ARG_ERR);
	if (kill(svr_pid, 0) == -1)
		print_error_and_exit(MSG_SIG_ERR);
	set_signal_handler(&sig_handler_client);
	send_message(svr_pid, argv[2]);
	return (0);
}
