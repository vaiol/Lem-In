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

H       = lemin.h

OUT     = output/output_
ADD     = additional/
VISU    = visu/visu_
SRCS    = lemin.c parse_input.c find_all_ways.c remove_all.c build_matrix.c \
            get_best_ways.c find_diffs.c create_ants.c parse_commands.c \
            $(ADD)add_command.c $(ADD)add_diff.c $(ADD)add_link.c \
            $(ADD)add_room.c $(ADD)add_way.c $(ADD)check_data.c \
            $(ADD)create_info.c $(ADD)read_file.c \
            $(OUT)all_ways.c $(OUT)file.c $(OUT)result.c $(OUT)ways.c \
            $(OUT)ant_moves.c $(OUT)ant_moves_add.c \
            $(VISU)diagonal.c $(VISU)diagonal_checks.c $(VISU)put_link.c \
            $(VISU)put_map.c $(VISU)line.c $(VISU)add_diagonal.c

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
	@$(CC) $(CFLAGS) -I $(H) -c $<  -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@printf "[RM] %s libft/libft.a\n" $(NAME)
	@rm -rf $(NAME)
	@make -C $(LIB) fclean

re: fclean all
