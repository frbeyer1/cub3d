# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 11:11:26 by frbeyer           #+#    #+#              #
#    Updated: 2024/05/07 20:59:09 by frbeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	./ft_atoi.c	\
		./ft_isalpha.c		\
      	./ft_isalnum.c		\
		./ft_isascii.c		\
		./ft_isdigit.c		\
		./ft_isprint.c		\
		./ft_memset.c		\
		./ft_bzero.c		\
		./ft_memcpy.c		\
		./ft_strlen.c		\
		./ft_strlcat.c		\
		./ft_strlcpy.c		\
		./ft_strncmp.c 		\
		./ft_putchar_fd.c 		\
		./ft_toupper.c 		\
		./ft_tolower.c 		\
		./ft_substr.c 		\
		./ft_strrchr.c 		\
		./ft_strnstr.c 		\
		./ft_strdup.c 		\
		./ft_strchr.c 		\
		./ft_putnbr_fd.c 		\
		./ft_putendl_fd.c 		\
		./ft_putstr_fd.c 		\
		./ft_memmove.c 		\
		./ft_memcmp.c 		\
		./ft_memchr.c 		\
		./ft_isascii.c 		\
		./ft_calloc.c 		\
		./ft_strjoin.c 		\
		./ft_strtrim.c 		\
		./ft_itoa.c			\
		./ft_striteri.c		\
		./ft_strmapi.c		\
		./ft_split.c		\
		./get_next_line.c 		\
		./get_next_line_utils.c 		\

BONUS_SRC =	./ft_lstnew.c 		\
		./ft_lstadd_front.c 		\
		./ft_lstsize.c 		\
		./ft_lstlast.c 		\
		./ft_lstadd_back.c 		\
		./ft_lstdelone.c 		\
		./ft_lstclear.c 		\
		./ft_lstiter.c			\
		./ft_lstmap.c		\

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

HDRS = libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus:
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(BONUS_SRC)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)
	
clean:
	/bin/rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re bonus