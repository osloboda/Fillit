#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osloboda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:50:16 by osloboda          #+#    #+#              #
#    Updated: 2019/03/02 16:45:50 by osloboda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBDIR = libft/

NAME = fillit

FSRC = main_function.c touch_desk.c fillit.c dop_f.c

INCL = fillit.h

FOBJ = $(FSRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	gcc $(FLAGS) $(FSRC) $(INCL)
	gcc -o $(NAME) $(FOBJ) $(LIBDIR)libft.a

clean:
	rm -f $(FOBJ) *h.gch
	@make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
