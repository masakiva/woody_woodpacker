# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:11:10 by mvidal-a          #+#    #+#              #
#    Updated: 2022/12/10 17:18:25 by mvidal-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------#
################# PROG_NAME #####################
#-----------------------------------------------#
NAME = woody_woodpacker

#-----------------------------------------------#
################## COMPILO ######################
#-----------------------------------------------#
CC = clang

#-----------------------------------------------#
################### PATHS #######################
#-----------------------------------------------#
HDRS_PATH		+= headers/
SRCS_PATH		+= sources/
OBJS_PATH		+= objects/

#-----------------------------------------------#
################## SOURCES ######################
#-----------------------------------------------#
SRCS		+= main.c
#SRCS		+= error.c

vpath %.c $(SRCS_PATH)

#-----------------------------------------------#
################## HEADERS ######################
#-----------------------------------------------#
#HDRS		+= error.h

vpath %.h $(HDRS_PATH)

#-----------------------------------------------#
################## OBJECTS ######################
#-----------------------------------------------#
OBJS		+= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

#-----------------------------------------------#
################### FLAGS #######################
#-----------------------------------------------#
CFLAGS		+= -Wall
CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	+= -I $(HDRS_PATH)

# Multiple header directories
#CPPFLAGS	+= $(foreach DIR, $(HDRS_DIRS), $(addprefix -I , $(DIR)))

#-----------------------------------------------#
################# LIBRARIES #####################
#-----------------------------------------------#
LIBFT_PATH	+= libft/

LIBFT_NAME	+= libft.a

CPPFLAGS		+= -I $(LIBFT_PATH)

LDFLAGS			+= -L $(LIBFT_PATH)

LDLIBS			+= -lft

#-----------------------------------------------#
################### DEBUG #######################
#-----------------------------------------------#
ifeq ($(d), 0)
	CFLAGS	+= -g3
	CFLAGS	+= -Wpadded
	CFLAGS	+= -fsanitize=address,undefined
	LDFLAGS	+= -fsanitize=address,undefined
endif


#-----------------------------------------------#
################### RULES #######################
#-----------------------------------------------#
all:				$(NAME)

$(NAME):			$(LIBFT_PATH)$(LIBFT_NAME) $(OBJS)
					$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(OBJS_PATH)%.o:	%.c
					$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJS):			Makefile $(HDRS) | $(OBJS_PATH)

$(OBJS_PATH):
					mkdir -p $@

$(LIBFT_PATH)$(LIBFT_NAME):
					$(MAKE) -C $(LIBFT_PATH) bonus custom

lib:
					$(MAKE) -C $(LIBFT_PATH) bonus custom
					$(MAKE) $(NAME)

clean:
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) -r $(OBJS_PATH)

fclean:				clean
					$(MAKE) -C $(MLX_PATH) clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
