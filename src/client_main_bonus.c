/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:43:17 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:17 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "system_message.h"

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
