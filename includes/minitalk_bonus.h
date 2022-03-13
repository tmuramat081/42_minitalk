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

/* By default, client/server wait about 0.1 second for a signal */
# define SIG_TIME_LIMIT 10000

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

typedef struct s_char {
	char			c;
	unsigned int	i;
	bool			is_null;
}	t_char;

typedef void(*t_sfunc)(int, siginfo_t *, void *);

/*** client_handler_bonus.c ***/
void	sig_handler_client(int signal, siginfo_t *info, void *ucontext);
void	send_message(pid_t svr_pid, const char *str);
void	send_client_pid(pid_t svr_pid);
void	send_bit(pid_t svr_pid, char c);

/*** server_handler_bonus.c ***/
void	sig_handler_server(int signal, siginfo_t *info, void *ucontext);
void	stand_by_for_message(void);
void	receive_message(t_char input);
int		receive_client_pid(void);
void	receive_bit(t_char *input);

/*** utils_bonus.c ***/
bool	is_timeout(int time_limit);
void	set_signal_handler(t_sfunc signal_handler);
void	print_error_and_exit(char *err_msg);
void	print_pid(int pid);
pid_t	input_pid(char *nptr);

#endif