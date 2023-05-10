# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 15:21:46 by ide-albe          #+#    #+#              #
#    Updated: 2023/02/27 15:21:49 by ide-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC1= gcc -g
CC2= gcc -g
CLIENT=client
SERVER=server
LIBFTA=libft/libft.a
CFLAGS= -Wall -Werror -Wextra
SRC1= client.c
SRC2= server.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)


all: libft $(CLIENT) $(SERVER)


$(CLIENT): $(OBJ1)
	$(CC1) $(CFLAGS) $(OBJ1) $(LIBFTA) -o $(CLIENT)

$(SERVER): $(OBJ2)
	$(CC2) $(CFLAGS) $(OBJ2) $(LIBFTA) -o $(SERVER)

libft:
	make -C ./libft all

clean:
	rm -rf $(OBJ1) $(OBJ2)
	make -C libft clean

fclean:
	rm -rf $(CLIENT) $(SERVER)
	make -C libft fclean

re:

.PHONY: libft