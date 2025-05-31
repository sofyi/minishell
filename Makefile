NAME = minishell
SRC = small_libft.c exc.c helper.c free_fun.c linkd_list.c all_env.c ./bilt_in/pwd.c ./bilt_in/env.c ./bilt_in/cd.c ./bilt_in/unset.c ./bilt_in/export.c ./bilt_in/exit.c \
 main.c 
OBJ = $(SRC:.c=.o)
READLINE_DIR = /Users/slamhaou/.brew/opt/readline

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(OBJS)  -L$(READLINE_DIR)/lib -lreadline -o $(NAME)

%.o : %.c
	cc -Wall -Wextra -Werror -c -I$(READLINE_DIR)/include   $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
