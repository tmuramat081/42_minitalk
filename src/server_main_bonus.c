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

int	main(void)
{
	pid_t	svr_pid;

	svr_pid = getpid();
	print_pid(svr_pid);
	set_signal_handler(&sig_handler_server);
	stand_by_for_message();
	return (0);
}
