/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:06:16 by ide-albe          #+#    #+#             */
/*   Updated: 2023/05/05 13:11:31 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int sig)
{
	static int	bits;
	static int	msg;

	if (sig == SIGUSR1)
		msg |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", msg);
		bits = 0;
		msg = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_printf("\nBIENVENIDO A MI SERVER\n");
	ft_printf("MI PID: %d\n\n", getpid());
	while (argc == 1)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pause();
	}
	return (0);
}
