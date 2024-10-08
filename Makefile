NAME 	= pipex
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I $(INCLUDE)
include ./Src/Libft/Makefile

SRC =	Src/check_args.c	\
		Src/exit_error.c	\
		Src/free.c	\
		Src/get_files.c	\
		Src/get_path.c	\
		Src/here_doc.c	\
		Src/main.c	\
		Src/pipes_utils.c	\
		Src/pipex.c
OBJ = $(SRC:.c=.o)

all: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

clean: libft_clean
	@rm -f $(LIBFT_OBJ) $(OBJ)
	@clear
	@echo "cleaning done!"

fclean: libft_fclean
	@rm -f $(LIBFT_OBJ) $(OBJ)
	@rm -f $(NAME)
	@rm -rf .vscode
	@clear
	@echo "full cleaning done!"

re:
	make fclean
	make all
	@clear
	@echo "Re:Zero - Re:Clean and compile again."

.PHONY: all tester clean fclean re
