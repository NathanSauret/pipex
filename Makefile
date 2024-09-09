NAME 	= pipex
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I $(INCLUDE)
include ./Src/Libft/Makefile

SRC =	Src/Mendatory/main.c	\
		Src/Mendatory/exit_error.c	\
		Src/Mendatory/pipex.c	\
		Src/Mendatory/get_path.c
OBJ = $(SRC:.c=.o)

SRC_BONUS =	Src/Bonus/main_bonus.c	\
			Src/Bonus/exit_error_bonus.c	\
			Src/Bonus/pipex_bonus.c	\
			Src/Bonus/get_path_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

bonus: libft_all
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT_NAME) -o $(NAME)
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
