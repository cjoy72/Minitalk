# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 15:38:07 by cbaroi            #+#    #+#              #
#    Updated: 2024/05/18 16:08:07 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler
CC = gcc

# Define the flags
CFLAGS = -Wall -Wextra -Werror

# Define the source files
SRCS = client.c server.c utils.c
BONUS_SRCS = client_bonus.c server_bonus.c utils.c

# Define the object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Define the executables
TARGETS = client server

BONUS_TARGETS = client_bonus server_bonus

# Default rule to build all targets
all: $(TARGETS)

bonus: $(BONUS_TARGETS)

# Rule to build client
client: client.o utils.o
	$(CC) $(CFLAGS) -o client client.o utils.o

client_bonus: client_bonus.o utils.o
	$(CC) $(CFLAGS) -o client_bonus client_bonus.o utils.o

# Rule to build server
server: server.o utils.o
	$(CC) $(CFLAGS) -o server server.o utils.o

server_bonus: server_bonus.o utils.o
	$(CC) $(CFLAGS) -o server_bonus server_bonus.o utils.o

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(TARGETS) $(BONUS_TARGETS)
# Phony targets
.PHONY: all clean
