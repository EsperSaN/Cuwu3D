# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 20:55:46 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/27 09:42:54 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GNL_DIR = ./get_next_line/
GNL = get_next_line_utils.c get_next_line.c
GNL_FILE = $(addprefix $(GNL_DIR), $(GNL))

SRC = ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_isalnum.c\
ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_memcmp.c\
ft_strchr.c ft_strncmp.c ft_isascii.c ft_strrchr.c ft_strdup.c ft_calloc.c\
ft_memmove.c ft_atoi.c ft_strnstr.c ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c $(GNL_FILE)

HEADER_FILE = ./libft.h ./get_next_line/get_next_line.h

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

B_OBJ = $(BONUS:.c=.o)
OBJ = $(SRC:.c=.o)


CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(B_OBJ)
	ar -rcs $(NAME) $(OBJ) $(B_OBJ)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: clean fclean all re bonus 
