NAME = ft_ls

FILES = 

LFTDIR = ./Libft/

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

SRC_PATH = Src/
O_PATH = Obj/
HEADER = -I./Includes/ -I$(LFTDIR)
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L $(LFTDIR) -lft

SRC = $(addprefix $(SRC_PATH), $(FILES))

OBJ =$(addprefix $(O_PATH),$(subst .c,.o,$(FILES)))

CHECK_O = .o_path_exists

all: $(NAME)

$(NAME): lib $(OBJ) $(OBJ)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	@gcc $(CFLAGS) $(SRC) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) " - OK" $(GREEN)

lib:
	@cd $(LFTDIR) && make

$(O_PATH)%.o: $(SRC_PATH)%.c | $(CHECK_O)
	@echo $(PURPLE) " - Compiling $< into $@" $(GREEN)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $@

$(CHECK_O):
	@mkdir $(O_PATH)
	@touch $(CHECK_O)
    
clean:
	@echo $(RED) " - Removing object files" $(EOC)
	@rm -rf $(O_PATH)
	@rm -rf $(CHECK_O)
	@cd $(LFTDIR) && make clean

fclean: clean
	@echo $(RED) " - Removing $(NAME)" $(EOC)
	@rm -rf $(NAME)
	@cd $(LFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
