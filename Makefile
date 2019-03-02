# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osloboda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:50:16 by osloboda          #+#    #+#              #
#    Updated: 2018/12/13 14:47:12 by osloboda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft.a

NAME = fillit

LSRC = ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memset.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_fprime.c ft_rev_wstr.c ft_search_and_replace.c ft_print_bits.c ft_reverse_bits.c ft_swap.c

FSRC = main_function.c touch_desk.c fillit.c dop_f.c

INCL = fillit.h libft.h

LOBJ = $(LSRC:.c=.o)

FOBJ = $(FSRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(LSRC)
	ar rc $(LIBNAME) $(LOBJ)
	ranlib $(LIBNAME)
	gcc $(FLAGS) $(FSRC) $(INCL)
	gcc -o $(NAME) $(FOBJ) $(LIBNAME)

clean:
	rm -f $(LOBJ) $(FOBJ) *h.gch

fclean: clean
	rm -f $(LIBNAME) $(NAME)

re: fclean all
