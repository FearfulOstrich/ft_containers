#==============================================================================#
#..............................................................................#
#...............................DECLARATIONS...................................#
#..............................................................................#
#==============================================================================#

## Compilation

NAME	=	containers

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -g3 -std=c++98 -g3

## Sources

SRCDIR	=	src/

SRCFILE	=	main_map.cpp

SRC		=	$(addprefix $(SRCDIR), $(SRCFILE))

INCL_DIR	=	includes/

DEPS		=	$(wildcard $(INCL_DIR)*.*pp)

## Objects

OBJDIR		=	obj/

OBJ			=	$(subst $(SRCDIR), $(OBJDIR), $(SRC:.cpp=.o))

OBJSTLDIR	=	obj_stl/

OBJSTL		=	$(subst $(SRCDIR), $(OBJSTLDIR), $(SRC:.cpp=.o))

#==============================================================================#
#..............................................................................#
#....................................RULES.....................................#
#..............................................................................#
#==============================================================================#

all			:	$(NAME) $(NAME)_STL

$(OBJDIR)%.o:	$(SRCDIR)%.cpp Makefile $(DEPS)
				mkdir -p $(OBJDIR)
				$(CC) $(FLAGS) -c $< -o $@ -D STL=0 -I $(INCL_DIR)

$(NAME)		:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME)_FT

$(OBJSTLDIR)%.o:	$(SRCDIR)%.cpp Makefile $(DEPS)
					mkdir -p $(OBJSTLDIR)
					$(CC) $(FLAGS) -c $< -o $@ -D STL=1 -I $(INCL_DIR)

$(NAME)_STL	:	$(OBJSTL)
				$(CC) $(OBJSTL) -o $(NAME)_STL

clean		:
				rm -rf $(OBJ)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re