/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:49:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/10 14:49:50 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define SIG_INTARVAL 50
# define SIG_TIME_LIMIT 2000
# define MSG_ARG_ERR "[Invalid argument.]"
# define MSG_SIG_ERR "Transmission failed..."
# define MSG_REC_ACK "\nTransmission succeeded!"
# define EOT 0x4

# include <sys/types.h>
# include <signal.h>

typedef void(*t_sfunc)(int, siginfo_t *, void *);

/*** client_bonus.c ***/
void	sig_handler_client(int signal, siginfo_t *info, void *ucontext);
void	check_ack_signal(int send_signal);
void	send_bit(pid_t svr_pid, char c);
void	send_message(pid_t svr_pid, const char *str);

/*** server_bonus.c ***/
void	sig_handler_server(int signal, siginfo_t *info, void *ucontext);
void	receive_bit(void);
void	receive_message(void);

/*** utils_bonus.c ***/
void	set_signal_handler(t_sfunc signal_handler);
void	print_error_and_exit(char *err_msg);

#endif