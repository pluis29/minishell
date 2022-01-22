/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:00 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/01/22 15:42:28 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Add a specific handler to struct sigaction and send to sigaction function */
void	jump_sig(int sig, void (*handler)(int), struct sigaction *sa)
{
	sa->sa_handler = handler;
	sigaction(sig, sa, NULL);
}

/* Deal with C+c and redisplay the prompt */
void	handle_sigint(int num)
{
	(void)num;
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_exec(int num)
{
	(void)num;
	ft_putendl_fd("", 1);
}
