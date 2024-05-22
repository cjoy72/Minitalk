# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 20:32:13 by cbaroi            #+#    #+#              #
#    Updated: 2024/05/22 12:20:11 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS_DIR = Headers
SRCS_DIR = srcs
OBJS_DIR = objs
UTILS_DIR = utils

SRCS_FILES =	server.c client.c
BONUS_FILES =	server_bonus.c client_bonus.c
UTILS_FILES =	ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_error.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES)) $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o)) $(addprefix $(OBJS_DIR)/, $(UTILS_FILES:.c=.o))

BONUS_SRCS = $(addprefix $(SRCS_DIR)/, $(BONUS_FILES))
BONUS_OBJS = $(addprefix $(OBJS_DIR)/, $(BONUS_FILES:.c=.o))

CLIENT_OBJS = $(filter-out $(OBJS_DIR)/server.o, $(OBJS))
SERVER_OBJS = $(filter-out $(OBJS_DIR)/client.o, $(OBJS))

CLIENT_BONUS_OBJS = $(filter-out $(OBJS_DIR)/server_bonus.o, $(BONUS_OBJS)) $(filter $(OBJS_DIR)/ft_%.o, $(OBJS))
SERVER_BONUS_OBJS = $(filter-out $(OBJS_DIR)/client_bonus.o, $(BONUS_OBJS)) $(filter $(OBJS_DIR)/ft_%.o, $(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)
	@echo "Client compilation Succed!"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)
	@echo "Server compilation Succed!"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJS)
	@echo "Client bonus compilation Succed!"

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJS)
	@echo "Server bonus compilation Succed!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS_DIR)/$(NAME).h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

$(OBJS_DIR)/%.o: $(UTILS_DIR)/%.c $(HEADERS_DIR)/$(NAME).h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	echo "Objects deleted!"
	@rmdir $(OBJS_DIR) 2> /dev/null || true

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "Programs deleted!"

re: fclean all

.PHONY: all clean fclean re bonus
