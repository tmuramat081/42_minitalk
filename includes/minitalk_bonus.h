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

/* By default, client/server wait about 1 second for a signal */
# define SIG_INTARVAL 100
# define SIG_TIME_LIMIT 1000
# define MSG_ARG_ERR "Invalid argument."
# define MSG_SIG_ERR "Transmission failed..."
# define MSG_REC_ACK "\nTransmission succeeded!"
# define EOT 0x4

# include <sys/types.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_char {
	char	c;
	int		i;
}	t_char;

typedef void(*t_sfunc)(int, siginfo_t *, void *);

/*** client_bonus.c ***/
void	sig_handler_client(int signal, siginfo_t *info, void *ucontext);
void	send_bit(pid_t svr_pid, char c);
void	send_message(pid_t svr_pid, const char *str);

/*** server_bonus.c ***/
void	sig_handler_server(int signal, siginfo_t *info, void *ucontext);
char	receive_bit(t_char *input);
void	receive_message(t_char input);

/*** utils_bonus.c ***/
bool	is_timeout(void);
void	set_signal_handler(t_sfunc signal_handler);
void	print_error_and_exit(char *err_msg);
void	print_pid(int pid);

#endif