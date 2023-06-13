# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:25:44 by nkietwee          #+#    #+#              #
#    Updated: 2023/06/14 01:50:48 by nkietwee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread #-g -fsanitize=address


SRCS = ft_checkerr.c \
		ft_init.c \
		ft_philo.c \
		ft_philo_util.c \
		ft_crtpthread.c\
		ft_time.c\
		ft_print.c\
		ft_checkdie.c\
		ft_clear.c\

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

a: re
	./philo 1 800 200 200

b: re
	./philo 5 800 200 200

c: re
	./philo 5 800 200 200 7

d: re
	./philo 4 410 200 200

e: re
	./philo 4 310 200 100
.PHONY: all clean fclean re a b c d e