/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:10:03 by ide-albe          #+#    #+#             */
/*   Updated: 2023/05/05 14:10:31 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    MINI_TALK_H
# define    MINI_TALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

void		mysignal(int pid, char str);
void		handler(int sig);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);

#endif