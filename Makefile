# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/30 14:11:47 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB     = libft/
NAME    = lem-in
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = lem_in.c parse_input.c add_element.c additional.c check_data.c    \
find_ways.c free_memory.c matrix.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[CC] libft.a start:\n"
	@make -C $(LIB)
	@printf "[CC] libft.a finished successfull!\n"
	@$(CC) $(SRCS) $(LIB)libft.a -o $(NAME)
	@printf "[CC] %s\n" $(NAME)

.c.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@printf "[RM] %s libft/libft.a\n" $(NAME)
	@rm -rf $(NAME)
	@make -C $(LIB) fclean

re: fclean all
