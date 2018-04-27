# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brigoux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 15:07:41 by brigoux           #+#    #+#              #
#    Updated: 2016/06/24 16:25:25 by brigoux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, norme

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##

NAME = libft.a

SRC_PATH = srcs/
SRC_NAME = ft_atoi.c          \
		   ft_atolli.c        \
		   ft_bzero.c         \
		   ft_chartostr.c     \
		   ft_inrange.c       \
		   ft_isalnum.c       \
		   ft_isalpha.c       \
		   ft_isascii.c       \
		   ft_isdigit.c       \
		   ft_isprint.c       \
		   ft_itoa.c          \
		   ft_lstadd.c        \
		   ft_lstdel.c        \
		   ft_lstdelone.c     \
		   ft_lstiter.c       \
		   ft_lstlast.c       \
		   ft_lstlen.c        \
		   ft_lstmap.c        \
		   ft_lstnew.c        \
		   ft_lstriter.c      \
		   ft_memalloc.c      \
		   ft_memccpy.c       \
		   ft_memchr.c        \
		   ft_memcmp.c        \
		   ft_memcpy.c        \
		   ft_memdel.c        \
		   ft_memdump.c       \
		   ft_memmove.c       \
		   ft_memset.c        \
		   ft_putchar.c       \
		   ft_putchar_fd.c    \
		   ft_putendl.c       \
		   ft_putendl_fd.c    \
		   ft_putnchar.c      \
		   ft_putnbr.c        \
		   ft_putnbr_fd.c     \
		   ft_putstr.c        \
		   ft_putstr_fd.c     \
		   ft_strcat.c        \
		   ft_strccpy.c       \
		   ft_strcdup.c       \
		   ft_strchr.c        \
		   ft_strchrone.c     \
		   ft_strclen.c       \
		   ft_strclr.c        \
		   ft_strcmp.c        \
		   ft_strcpy.c        \
		   ft_strdel.c        \
		   ft_strdup.c        \
		   ft_strequ.c        \
		   ft_strfill.c       \
		   ft_strfreedef.c    \
		   ft_strinsert.c     \
		   ft_strisdigit.c    \
		   ft_striter.c       \
		   ft_striteri.c      \
		   ft_strjoin.c       \
		   ft_strjoinfree.c   \
		   ft_strlcat.c       \
		   ft_strlen.c        \
		   ft_strmap.c        \
		   ft_strmapi.c       \
		   ft_strncat.c       \
		   ft_strncmp.c       \
		   ft_strncpy.c       \
		   ft_strndup.c       \
		   ft_strnequ.c       \
		   ft_strnew.c        \
		   ft_strnewfilled.c  \
		   ft_strnstr.c       \
		   ft_strpad.c        \
		   ft_strrchr.c       \
		   ft_strsplit.c      \
		   ft_strstr.c        \
		   ft_strstrip.c      \
		   ft_strsub.c        \
		   ft_strtrim.c       \
		   ft_tolower.c       \
		   ft_toupper.c       \
		   ft_isspace.c       \
		   ft_strcount.c      \
		   ft_strreplace.c    \
		   ft_strrev.c        \
		   ft_tabfree.c       \
		   ft_tablen.c        \
		   ft_lstindex.c      \
		   get_next_line.c    \
		   ft_checkflags.c    \
		   ft_checkmodif.c    \
		   ft_checkprec.c     \
		   ft_checkwidth.c    \
		   ft_convert.c       \
		   ft_format.c        \
		   ft_getarg.c        \
		   ft_getfromsize.c   \
		   ft_lltoa_base.c    \
		   ft_parse.c         \
		   ft_printf.c        \
		   ft_printchar.c     \
		   ft_printls.c       \
		   ft_printwchar.c    \
		   ft_tronc.c         \
		   ft_ulltoa_base.c
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = includes/

CC = gcc
WFLAGS = -Wall -Werror -Wall
CPPFLAGS = -I$(INC_PATH)

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(WFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJ_PATH) $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)
	rm -fd $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	@$@ $(SRC_PATH)
	@echo
	@$@ $(INC_PATH)

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##
