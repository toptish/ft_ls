# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:13:07 by gdorcas           #+#    #+##   Updated: 2020/08/04 11:27:37 by akimovdo         ###   ########lyon.fr   #######.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME_SH = libft

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	  ft_strjoin.c ft_isspace.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_power.c\
	  ft_sqrt.c ft_lstsize.c get_next_line.c ft_initial.c ft_parser.c ft_print_d.c \
      ft_print_float.c ft_print_ou.c ft_print_s.c ft_options.c\
      ft_print_xxxp.c ft_printf.c ft_switch_print.c \
      ft_atoi.c ft_strlen.c ft_display.c ft_itoa.c \
      ft_check_float.c ft_print_float_add.c ft_parser_add.c
	  
HEADER = libft.h
OFILES = $(subst .c,.o,$(SRC))
FLAGS = -Wall -Wextra -Werror

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

all: $(NAME)

$(NAME): $(OFILES)
	@echo $(CYAN) " - Compiling $(NAME_SH)" $(EOC)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo $(GREEN) " - OK" $(GREEN)

%.o: %.c
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@gcc $(FLAGS) $< -c -o $@

clean:
	@echo $(RED) " - Removing $(NAME_SH) object files" $(EOC)
	@rm -f $(OFILES)

fclean: clean
	@echo $(RED) " - Removing $(NAME_SH)" $(EOC)
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean make re
