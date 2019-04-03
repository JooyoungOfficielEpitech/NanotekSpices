##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project: NanotekSpices
##

CC		=	g++

NAME		=	nanotekspice

RM		=	rm -rf

CPPFLAGS	+=	-I./include/

SRC		=	src/main.cpp			\
			src/NanotekSpice.cpp		\
			src/Circuit.cpp			\
			src/Parser.cpp			\
			src/Output.cpp			\
			src/Input.cpp			\
			src/True.cpp			\
			src/False.cpp			\
			src/Clock.cpp			\
			src/MainComponent.cpp		\
			src/Port4018.cpp		\
			src/Port4001.cpp		\
			src/Port4008.cpp		\
			src/Port4011.cpp		\
			src/Port4013.cpp		\
			src/Port4071.cpp		\
			src/Port4030.cpp		\
			src/Port4069.cpp		\
			src/Exception.cpp		\

OBJS		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CPPFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
