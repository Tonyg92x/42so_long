# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguay <aguay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2022/03/16 12:58:07 by aguay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*#######################################################
##*          ERASE COMMENTS FOR BONUS PARTS            ##
#*#######################################################

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= so_long

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIBFT_DIR		= libft

LIBFT_OBJ		= libft/obj/

LIBFT_INC		= libft/includes/

MINILIBX_DIR	= MLX42

## ----- SOURCE FILES ----- ##
SRCS_FILES		=						\
			main.c						\

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
MINILIBX		= make -C $(MINILIBX_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)
	clear
	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I $(LIBFT_OBJ) -I $(INCLUDE_DIR) -I $(LIBFT_INC) -o $@ -c $<

$(NAME): $(OBJS)
	$(LIBFT)
	$(MINILIBX)
	$(CC) $(OBJS) libft/libft.a MLX42/libmlx42.a -I ./MLX42/include MLX42/libglfw.3.3.dylib -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	clear

fclean: clean
	@rm -f $(NAME)
##	@rm -f so_long_bonus
	@make -C $(LIBFT_DIR) fclean
	clear

re: fclean all

.PHONY: all clean fclean re
