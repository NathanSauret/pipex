LIBFT_NAME = Src/Libft/libft.a
CC		= cc
CFLAGS	=  -Wall -Werror -Wextra -g3
INCLUDE = Libft
COUNTER = 0
N := 0

LIBFT_SRC =	./Src/Libft/ft_get_next_line/ft_get_next_line.c	\
			./Src/Libft/ft_get_next_line/ft_get_next_line_utils.c	\
			./Src/Libft/ft_printf/ft_printf.c	\
			./Src/Libft/ft_printf/ft_print_char.c	\
			./Src/Libft/ft_printf/ft_print_str.c	\
			./Src/Libft/ft_printf/ft_print_pointer.c	\
			./Src/Libft/ft_printf/ft_print_int.c	\
			./Src/Libft/ft_printf/ft_print_unsigned.c	\
			./Src/Libft/ft_printf/ft_print_hex.c	\
			./Src/Libft/ft_atoi.c	\
			./Src/Libft/ft_bzero.c	\
			./Src/Libft/ft_calloc.c	\
			./Src/Libft/ft_freetabstr.c	\
			./Src/Libft/ft_isalnum.c	\
			./Src/Libft/ft_isalpha.c	\
			./Src/Libft/ft_isascii.c	\
			./Src/Libft/ft_isdigit.c	\
			./Src/Libft/ft_isprint.c	\
			./Src/Libft/ft_itoa.c	\
			./Src/Libft/ft_lstadd_back_bonus.c	\
			./Src/Libft/ft_lstadd_front_bonus.c	\
			./Src/Libft/ft_lstclear_bonus.c	\
			./Src/Libft/ft_lstdelone_bonus.c	\
			./Src/Libft/ft_lstiter_bonus.c	\
			./Src/Libft/ft_lstlast_bonus.c	\
			./Src/Libft/ft_lstmap_bonus.c	\
			./Src/Libft/ft_lstnew_bonus.c	\
			./Src/Libft/ft_lstpop.c	\
			./Src/Libft/ft_lstsize_bonus.c	\
			./Src/Libft/ft_memchr.c	\
			./Src/Libft/ft_memcmp.c	\
			./Src/Libft/ft_memcpy.c	\
			./Src/Libft/ft_memmove.c	\
			./Src/Libft/ft_memset.c	\
			./Src/Libft/ft_putchar_fd.c	\
			./Src/Libft/ft_putendl_fd.c	\
			./Src/Libft/ft_putnbr_fd.c	\
			./Src/Libft/ft_putstr_fd.c	\
			./Src/Libft/ft_split.c	\
			./Src/Libft/ft_strchr.c	\
			./Src/Libft/ft_strdup.c	\
			./Src/Libft/ft_striteri.c	\
			./Src/Libft/ft_strjoin.c	\
			./Src/Libft/ft_strlcat.c	\
			./Src/Libft/ft_strlcpy.c	\
			./Src/Libft/ft_strlen.c	\
			./Src/Libft/ft_strmapi.c	\
			./Src/Libft/ft_strncmp.c	\
			./Src/Libft/ft_strnstr.c	\
			./Src/Libft/ft_strrchr.c	\
			./Src/Libft/ft_strtrim.c	\
			./Src/Libft/ft_substr.c	\
			./Src/Libft/ft_tolower.c	\
			./Src/Libft/ft_toupper.c	\
			./Src/Libft/ft_uitoa.c	\

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all:

libft_all: $(LIBFT_NAME)

$(LIBFT_NAME): $(LIBFT_OBJ)
	@ar rcs $(LIBFT_NAME) $(LIBFT_OBJ)
	@clear
	@echo "compiling project files..."

$(LIBFT_OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	$(eval N=$(shell echo $$(($(COUNTER)%9))))
	@clear
	@if [ "$(N)" -lt 3 ]; then \
		echo "Libft compiling."; \
	else \
		if [ "$(N)" -lt 6 ]; then \
			echo "Libft compiling.."; \
		else \
			if [ "$(N)" -lt 9 ]; then \
				echo "Libft compiling..."; \
			fi \
		fi \
	fi
	@echo "[$(COUNTER) / 55]"

libft_clean:
	@rm -f $(LIBFT_OBJ)

libft_fclean: libft_clean
	@rm -f $(LIBFT_NAME)

libft_re: libft_fclean libft_all

coffee:
	while [ true ]; do \
		clear; \
		echo ""; \
		echo "                   ("; \
		echo "	                     )     ("; \
		echo "               ___...(-------)-....___"; \
		echo '           .-""       )    (          ""-.'; \
		echo "      .-''''|-._             )         _.-|"; \
		echo '     /  .--.|   `""---...........---""`   |'; \
		echo "    /  /    |                             |"; \
		echo "    |  |    |                             |"; \
		echo "     \  \   |       MY CODE IS LAME       |"; \
		echo "      '\ '\ |                             |"; \
		echo "        '\ '|    BUT MY COFFEE IS GOOD    |"; \
		echo "        _/ /\                             /"; \
		echo "       (__/  \                           /"; \
		echo '    _..---""` \                         /`""---.._'; \
		echo " .-'           \                       /          '-."; \
		echo ":               '-.__             __.-'              :"; \
		echo ':                  ) ""---...---"" (                :'; \
		echo "\'._                '"--...___...--"'              _.'"; \
		echo '   \""--..__                              __..--""/'; \
		echo "     '._     """----.....______.....----"""         _.'"; \
		echo '         ""--..,,_____            _____,,..--"""'''; \
		echo '                      """------"""'; \
		sleep 0.3; \
		one; \
		clear; \
		echo ""; \
		echo "                 ("; \
		echo "	                  )      ("; \
		echo "               ___..(.------)--....___"; \
		echo '           .-""       )   (           ""-.'; \
		echo "      .-''''|-._      (       )        _.-|"; \
		echo '     /  .--.|   `""---...........---""`   |'; \
		echo "    /  /    |                             |"; \
		echo "    |  |    |                             |"; \
		echo "     \  \   |       MY CODE IS LAME       |"; \
		echo "      '\ '\ |                             |"; \
		echo "        '\ '|    BUT MY COFFEE IS GOOD    |"; \
		echo "        _/ /\                             /"; \
		echo "       (__/  \                           /"; \
		echo '    _..---""` \                         /`""---.._'; \
		echo " .-'           \                       /          '-."; \
		echo ":               '-.__             __.-'              :"; \
		echo ':                  ) ""---...---"" (                :'; \
		echo "\'._                '"--...___...--"'              _.'"; \
		echo '   \""--..__                              __..--""/'; \
		echo "     '._     """----.....______.....----"""         _.'"; \
		echo '         ""--..,,_____            _____,,..--"""'''; \
		echo '                      """------"""'; \
		sleep 0.3; \
		clear; \
		echo ""; \
		echo "               ("; \
		echo "	                  )     ("; \
		echo "               ___..(.------)--....___"; \
		echo '           .-""      )    (           ""-.'; \
		echo "      .-''''|-._      (       )        _.-|"; \
		echo '     /  .--.|   `""---...........---""`   |'; \
		echo "    /  /    |                             |"; \
		echo "    |  |    |                             |"; \
		echo "     \  \   |       MY CODE IS LAME       |"; \
		echo "      '\ '\ |                             |"; \
		echo "        '\ '|    BUT MY COFFEE IS GOOD    |"; \
		echo "        _/ /\                             /"; \
		echo "       (__/  \                           /"; \
		echo '    _..---""` \                         /`""---.._'; \
		echo " .-'           \                       /          '-."; \
		echo ":               '-.__             __.-'              :"; \
		echo ':                  ) ""---...---"" (                :'; \
		echo "\'._                '"--...___...--"'              _.'"; \
		echo '   \""--..__                              __..--""/'; \
		echo "     '._     """----.....______.....----"""         _.'"; \
		echo '         ""--..,,_____            _____,,..--"""'''; \
		echo '                      """------"""'; \
		sleep 0.3; \
		clear; \
		echo ""; \
		echo "             (         ) "; \
		echo "	              )        ("; \
		echo "               ___)...----)----....___"; \
		echo '           .-""      )    (           ""-.'; \
		echo "      .-''''|-._      (       )        _.-|"; \
		echo '     /  .--.|   `""---...........---""`   |'; \
		echo "    /  /    |                             |"; \
		echo "    |  |    |                             |"; \
		echo "     \  \   |       MY CODE IS LAME       |"; \
		echo "      '\ '\ |                             |"; \
		echo "        '\ '|    BUT MY COFFEE IS GOOD    |"; \
		echo "        _/ /\                             /"; \
		echo "       (__/  \                           /"; \
		echo '    _..---""` \                         /`""---.._'; \
		echo " .-'           \                       /          '-."; \
		echo ":               '-.__             __.-'              :"; \
		echo ':                  ) ""---...---"" (                :'; \
		echo "\'._                '"--...___...--"'              _.'"; \
		echo '   \""--..__                              __..--""/'; \
		echo "     '._     """----.....______.....----"""         _.'"; \
		echo '         ""--..,,_____            _____,,..--"""'''; \
		echo '                      """------"""'; \
		sleep 0.3; \
	done

.PHONY: all libft_all libft_clean libft_fclean libft_re coffee
