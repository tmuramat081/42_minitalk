/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:37:04 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:37:04 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "system_message.h"
#include "libft.h"

extern volatile sig_atomic_t	g_received_signal;

/* Wait signal from the client/server. By default,
   it times out in about 0.1 second or more. */
bool	is_timeout(int time_limit)
{
	while (time_limit--)
	{
		if (g_received_signal)
			return (false);
		usleep(10);
	}
	return (true);
}

/* Initialize signal_handler, masking all but SIGUER1 and SIGUSR2. */
void	set_signal_handler(t_sfunc signal_handler)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error_and_exit(MSG_SIG_ERR);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error_and_exit(MSG_SIG_ERR);
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	print_error_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, 1);
	exit(EXIT_FAILURE);
}

/* Validate an PID for secure transmission. */
pid_t	input_pid(char *nptr)
{
	char	*endptr;
	long	input_pid;

	errno = 0;
	input_pid = ft_strtol_d(nptr, &endptr);
	if (errno)
		print_error_and_exit(MSG_ARG_ERR);
	else if (*endptr || endptr == nptr)
		print_error_and_exit(MSG_ARG_ERR);
	else if (input_pid <= 0 || kill(input_pid, 0) == -1)
		print_error_and_exit(MSG_SIG_ERR);
	return ((pid_t)input_pid);
}
