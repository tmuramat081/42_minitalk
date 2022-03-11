/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:49:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:49:50 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIG_INTARVAL 400
# define MSG_ARG_ERR "Invalid argument."
# define MSG_SIG_ERR "Transmission failed..."

# include <sys/types.h>
# include <signal.h>

typedef void(*t_sfunc)(int);

/*** client.c ***/
void	send_message(pid_t svr_pid, const char *str);
void	send_bit(pid_t svr_pid, char c);

/*** server.c ***/
void	sig_handler(int signal);
void	receive_message(void);
void	receive_bit(void);

/*** utils.c ***/
void	set_signal_handler(t_sfunc signal_handler);
void	print_error_and_exit(char *err_msg);
void	print_pid(int pid);
#endif