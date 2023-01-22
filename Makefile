NAME = libsocket
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -fPIC

SRCS_SOCKET = src/socket/accept.cpp 	\
			  src/socket/bind.cpp		\
			  src/socket/clear.cpp		\
			  src/socket/close.cpp		\
			  src/socket/connect.cpp	\
			  src/socket/listen.cpp		\
			  src/socket/recv.cpp		\
			  src/socket/send.cpp		\
			  src/socket/socket.cpp		\
			  src/socket/socket_sin.cpp	\
			  src/socket/sockopt.cpp	\
			  src/socket/utils.cpp		\
			  src/socket/addr.cpp		\
			  src/socket/read.cpp		\
			  src/socket/write.cpp		\
			  src/socket/proto.cpp		\
			  src/socket/port.cpp


SRCS_EPOLL = src/epoll/close.cpp	\
			 src/epoll/control.cpp	\
			 src/epoll/create.cpp	\
			 src/epoll/epoll.cpp	\
			 src/epoll/wait.cpp		\
			 src/epoll/utils.cpp

SRCS_TCPSERVER = src/tcpserver/setupserver.cpp 	\
				 src/tcpserver/tcpserver.cpp 	\
				 src/tcpserver/utils.cpp		\
				 src/tcpserver/setupepoll.cpp

ifdef OPTI
	CXXFLAGS += -Ofast -O1
endif

ifdef FAST
	CXXFLAGS += -Ofast
endif

ifdef SIZE
	CXXFLAGS += -Os
endif

SRCS = $(SRCS_SOCKET) $(SRCS_EPOLL) $(SRCS_TCPSERVER)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME).a $(NAME).so

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME).a: $(OBJS)
	ar rcs $(NAME).a $(OBJS)

$(NAME).so: $(OBJS)
	$(CC) $(CXXFLAGS) -shared $(OBJS) -o $(NAME).so

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a $(NAME).so

re: fclean $(NAME).a $(NAME).so

.PHONY: all clean fclean re
