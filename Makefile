NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC := ft_printf.c print_and_count_in_base_x.c handler.c parser.c handler_cont.c handler_assist.c\
handler_helper.c#utils_handle.c handlef.c \
#utils_handlef.c utils_handlef_2.c utils_handlef_3.c utils.c utils_parse.c
SRC_DIR = ./src
OBJECTS := $(SRC:.c=.o)
LIBRARIES = libftprintf.a ./libft/libft.a
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
INC_DIR = ./includes/
LIB_DIR = ./libft/

$(NAME):
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)
	@echo "creating ft_printf objects..."
	@gcc $(FLAGS) -c $(SRC) -I$(INC_DIR) -I$(LIB_DIR)
	@echo "\033[92mdone!\033[0m"
	@echo "creating libftprintf.a library..."
	@ar -rc $(NAME) $(OBJECTS)
	@echo "\033[92mdone!\033[0m"
all: $(NAME)
test: $(NAME)
	rm -f ./printf_tester
	gcc -o printf_tester -g ft_printf_tester.c $(SRC) ./libft/libft.a
	./printf_tester
	
clean:
	@echo "cleaning..."
	@make clean -C ./libft
	@echo "libft objects removed!"
	@rm -f $(OBJECTS)
	@echo "ft_printf objects removed!"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "libftprintf.a removed!"
re: fclean all
