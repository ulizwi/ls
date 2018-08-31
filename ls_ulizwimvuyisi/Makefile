# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 09:54:51 by umvuyisi          #+#    #+#              #
#    Updated: 2018/08/29 17:02:11 by umvuyisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DIR_LIB = libs/
CFLAGS = -Wall -Werror -Wextra -O2
FLAGS = $(CFLAGS) -I ./include/

SRC = main.c \
	  getgrgid.c \
	  ls_stat.c \
	  stat.c \

SRC_DIR = srcs/

CC = gcc 

MODE = 

OBJET = $(SRC:.c=.o)

OBJ_DIR = objs/

.PHONY: all, clean, fclean, re, $(NAME), lft, start, end


all: $(NAME)

$(NAME): lib $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(OBJET)) $(INC_FILES)
	@$(CC) $(MODE) $(FLAGS) -I$(INC) $(addprefix $(OBJ_DIR), $(OBJET)) -L./$(DIR_LFT) -lft -L./ $(NAME)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c) $(INC_FILES)
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@($(CC) $(MODE) $(FLAGS)  -I./$(INC) -c -o $@ $<)

lib:
	@(cd $(DIR_LFT) && $(MAKE))
	@(cd $(MAKE))

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@(cd $(DIR_LFT) && make clean)

fclean: clean
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)

re: fclean all
