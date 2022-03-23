# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguay <aguay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2022/03/23 13:54:22 by aguay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*#######################################################
##*          ERASE COMMENTS FOR BONUS PARTS            ##
#*#######################################################

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= so_long

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIBFT_DIR		= libft

LIBFT_OBJ		= libft/obj/

LIBFT_INC		= libft/includes/

## ----- SOURCE FILES ----- ##
SRCS_FILES		=						\
			main.c						\
			map_validation.c			\

##SCRS_B			=						\

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		= $(SRCS_FILES:.c=.o)
##OBJ_FILES_B		= $(SCRS_B:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
##OBJS_B			= $(addprefix $(OBJ_DIR), $(OBJ_FILES_B))
VPATH			= $(SRCS_DIR) 

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM				= rm -Rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

LIBFT			= make -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I $(LIBFT_OBJ) -I $(INCLUDE_DIR) -I $(LIBFT_INC) -o $@ -c $<

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
