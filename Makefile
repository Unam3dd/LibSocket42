NAME = libsocket
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -fPIC

DIST = dist

ifdef OPTI
	CXXFLAGS += -Ofast -O1
endif

ifdef FAST
	CXXFLAGS += -Ofast
endif

ifdef SIZE
	CXXFLAGS += -Os
endif

ifdef DEBUG
	CXXFLAGS += -g
endif

OBJDIR = obj

SRCS = $(shell find src -iname "*.cpp" -type f -print)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME).a $(NAME).so

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME).a: $(DIST) $(OBJS)
	ar rcs $(NAME).a $(OBJS)
	mv $(NAME).a $(DIST)

$(NAME).so: $(DIST) $(OBJS)
	$(CC) $(CXXFLAGS) -shared $(OBJS) -o $(NAME).so
	mv $(NAME).so $(DIST)

$(DIST):
	mkdir -p $(DIST)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a $(NAME).so

re: fclean $(NAME).a $(NAME).so

.PHONY: all clean fclean re
