/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:06:16 by ide-albe          #+#    #+#             */
/*   Updated: 2023/05/05 13:12:37 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	howtouse(void)
{
	write(1, "ERROR DE ARGUMENTOS\n", 21);
	write(1, "Intentelo asi: ./client PID 'mensaje'.\n", 40);
	write(1, "Mas de una palabra, escribir entre comillas dobles.\n", 51);
	exit(EXIT_FAILURE);
}

void	mysignal(int pid, char str)
{
	int		bits;

	bits = 0;
	while (bits < 8)
	{
		if ((str >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			mysignal(pid, argv[2][i]);
			i++;
		}
		mysignal(pid, '\n');
		system("leaks -q client");
	}
	else
		howtouse();
}
