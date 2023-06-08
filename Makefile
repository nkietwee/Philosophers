# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:25:44 by nkietwee          #+#    #+#              #
#    Updated: 2023/06/09 03:44:20 by nkietwee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=address


SRCS = ft_checkerr.c \
		ft_init.c \
		ft_philo.c \
		ft_philo_util.c \
		ft_crtpthread.c\
		ft_time.c\
		ft_print.c\
		ft_checkdie.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re