#==============================================================================#
#..............................................................................#
#...............................DECLARATIONS...................................#
#..............................................................................#
#==============================================================================#

## Compilation

NAME	=	containers

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

## Sources

SRCDIR	=	src/

SRCFILE	=	main_pair.cpp

SRC		=	$(addprefix $(SRCDIR), $(SRCFILE))

INCL_DIR	=	includes/

DEPS		=	$(wildcard $(INCL_DIR)*.*pp)

## Objects

OBJDIR	=	obj/

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

#==============================================================================#
#..............................................................................#
#....................................RULES.....................................#
#..............................................................................#
#==============================================================================#

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp Makefile $(DEPS)
				mkdir -p $(OBJDIR)
				$(CC) $(FLAGS) -c $< -o $@ -D STL=1

clean		:
				rm -rf $(OBJ)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re