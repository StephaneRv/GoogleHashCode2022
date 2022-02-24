SRC	=	src/main.cpp \

OBJ		=	$(SRC:.cpp=.o)

NAME	=	a.out

RM		+=	-r

CC		=	g++ -std=c++17

CXXFLAGS		+=	 -Wall -Wextra -g

CPPFLAGS	+=	-I include/

LDFLAGS		+=

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.o
	$(RM) *~
	$(RM) */*~
	$(RM) *.gc*
	$(RM) vgcore.*

fclean: clean
	$(RM) $(NAME)

re:	fclean all
