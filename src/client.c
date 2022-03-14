/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:00:20 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 15:00:20 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "system_message.h"
#include "libft.h"

/* Send signals with SIGUSR1(as 0 bit) and SIGUSR2(as 1 bit). */
void	send_bit(pid_t svr_pid, char c)
{
	unsigned int	i;

	i = 0;
	while (i < CHAR_BIT)
	{
		if (((c >> i) & 1) == 0)
			kill(svr_pid, SIGUSR1);
		else
			kill(svr_pid, SIGUSR2);
		usleep(SIG_INTARVAL);
		i++;
	}
}

void	send_message(pid_t svr_pid, const char *str)
{
	while (*str != '\0')
	{
		send_bit(svr_pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	svr_pid;

	if (argc != 3)
		print_error_and_exit(MSG_ARG_ERR);
	svr_pid = input_pid(argv[1]);
	send_message(svr_pid, argv[2]);
	return (0);
}
