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

all: $(DIST) $(DIST)/$(NAME).a $(DIST)/$(NAME).so

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(DIST)/$(NAME).a: $(OBJS)
	ar rcs $(DIST)/$(NAME).a $(OBJS)

$(DIST)/$(NAME).so: $(OBJS)
	$(CC) $(CXXFLAGS) -shared $(OBJS) -o $(DIST)/$(NAME).so

$(DIST):
	mkdir -p $(DIST)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(DIST)

re: fclean all

.PHONY: all clean fclean re
