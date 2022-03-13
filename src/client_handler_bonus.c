/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:38:45 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/13 20:38:45 by tmuramat         ###   ########.fr       */
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
	while (i < CHAR_BIT)
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
	while (1)
	{
		send_bit(svr_pid, *str);
		if (*str == '\0')
			break ;
		str++;
	}
	ft_putendl_fd(MSG_SUCCESS, 1);
}
