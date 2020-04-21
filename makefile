
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 18:25:03 by pmontese          #+#    #+#              #
#    Updated: 2020/01/30 20:41:57 by pmontese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC             = c.c convertion_parser.c d.c flags.c ft_printf.c \
					p.c percent.c s.c u.c utils.c x.c
SRC_LIB_PATH    = ./libft/
SRC_LIB_NAME    = ft_strnew.c ft_memset.c ft_iscontained.c ft_strdup.c \
					ft_strlen.c ft_strjoin.c ft_putchar_fd.c ft_strncpy.c \
					ft_rev_str.c ft_atoi.c ft_isspace.c
SRC_LIB         = $(addprefix $(SRC_LIB_PATH), $(SRC_LIB_NAME))
OBJ             = $(SRC:.c=.o)
OBJ_LIB         = $(SRC_LIB:.c=.o)
CFLAGS          = 
#CFLAGS			= -g
CC              = gcc
INCLUDES        = ./
INCLUDES_LIB    = ./libft
NAME            = libftprintf.a

all: $(NAME)
$(NAME):   $(OBJ) $(OBJ_LIB)
	cd $(SRC_LIB_PATH) && $(MAKE)
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)
#	$(CC) $(CFLAGS) -o a.out $(OBJ) libft/libft.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)
%.o: $(SRC_LIB_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES_LIB)
clean:
	rm -f *.o
	rm -f $(SRC_LIB_PATH)*.o
fclean: clean
	rm -f $(NAME)
	rm -f $(SRC_LIB_PATH)libft.a
re:         fclean all
.PHONY:     clean fclean
