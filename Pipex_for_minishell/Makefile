NAME 	= pipex
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I $(INCLUDE)

SRC =	Src/Utils/ft_get_next_line/ft_get_next_line.c	\
		Src/Utils/ft_get_next_line/ft_get_next_line_utils.c	\
		Src/Utils/ft_printf/ft_printf.c	\
		Src/Utils/ft_printf/ft_print_char.c	\
		Src/Utils/ft_printf/ft_print_str.c	\
		Src/Utils/ft_printf/ft_print_pointer.c	\
		Src/Utils/ft_printf/ft_print_int.c	\
		Src/Utils/ft_printf/ft_print_unsigned.c	\
		Src/Utils/ft_printf/ft_print_hex.c	\
		Src/Utils/ft_atoi.c	\
		Src/Utils/ft_freetabstr.c	\
		Src/Utils/ft_itoa.c	\
		Src/Utils/ft_split.c	\
		Src/Utils/ft_strjoin.c	\
		Src/Utils/ft_strncmp.c	\
		Src/Utils/ft_uitoa.c	\
		Src/check_args.c	\
		Src/exit_error.c	\
		Src/free.c	\
		Src/get_files.c	\
		Src/get_path.c	\
		Src/here_doc.c	\
		Src/main.c	\
		Src/pipes_utils.c	\
		Src/pipex.c	\
		Src/sleep_case.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@clear
	@echo "Compilation done!"

clean:
	@rm -f $(OBJ)
	@clear
	@echo "cleaning done!"

fclean:
	@rm -f $(OBJ)
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
