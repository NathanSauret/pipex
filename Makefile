NAME 	= pipex
NAME_BONUS 	= pipex_bonus
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I $(INCLUDE)
include ./Src/Libft/Makefile

SRC =	Src/Mendatory/main.c	\
		Src/Mendatory/exit_error.c	\
		Src/Mendatory/pipex.c	\
		Src/Mendatory/verify_args.c
OBJ = $(SRC:.c=.o)

SRC_BONUS =	Src/Bonus/main_bonus.c	\
			Src/Bonus/exit_error_bonus.c	\
			Src/Bonus/pipex_bonus.c	\
			Src/Bonus/verify_args_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

bonus: fclean libft_all $(NAME_BONUS)
$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT_NAME) -o $(NAME_BONUS)
	@clear
	@echo "Bonus compilation done!"

clean: libft_clean
	@rm -f $(LIBFT_OBJ) $(OBJ) $(OBJ_BONUS)
	@clear
	@echo "cleaning done!"

fclean: libft_fclean
	@rm -f $(LIBFT_OBJ) $(OBJ) $(OBJ_BONUS)
	@rm -f $(NAME) $(NAME_BONUS)
	@rm -rf .vscode
	@clear
	@echo "full cleaning done!"

re:
	make fclean
	make all
	@clear
	@echo "Re:Zero - Re:Clean and compile again."

.PHONY: all tester clean fclean re
