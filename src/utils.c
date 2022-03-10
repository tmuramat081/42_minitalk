/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:37:04 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:37:04 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

/* Initialize signal_handler. */
void	set_signal_handler(t_sfunc signal_handler)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error_and_exit(MSG_SIG_ERR);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error_and_exit(MSG_SIG_ERR);
}

void	print_error_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, 1);
	exit(1);
}
