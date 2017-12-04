# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 09:43:34 by rlossy       #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 13:16:40 by rlossy      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	fillit
LIB_DIR		=	./lib
HEADER		=	fillit.h
FILENAMES	=	main.c checker.c reader.c solve_uno.c solve_duo.c struct.c

SOURCES		=	$(addprefix ./, $(FILENAMES))
OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o)) 

L_FT		=	$(LIB_DIR)/libft
LIB_LNK		=	-L $(L_FT) -l ft
LIB_INC		=	-I $(L_FT)/libft.h


.PHONY: all clean fclean re


all: $(NAME)

clean:
	@echo "\033[31m"
	rm -rf build/
	@$(MAKE) -C $(L_FT) clean

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME)
	@$(MAKE) -C $(L_FT) fclean

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

build: 
	@echo "\033[35m"
	mkdir build/

$(NAME): $(OBJECTS)
	@$(MAKE) -C $(L_FT)
	@echo "\033[32m"
	gcc -Wall -Wextra -Werror -I $(HEADER) $(OBJECTS) $(LIB_LNK) -o $@

build/%.o: ./%.c | build
	gcc -Wall -Wextra -Werror $(LIB_INC) -I $(HEADER) -c $< -o $@
