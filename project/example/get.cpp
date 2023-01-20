#include "../inc/socket.hpp"
#include <iostream>
#include <cstring>

// Compile : c++ -Wall -Wextra -Werror -std=c++98 get.cpp ../libsocket.a

int main(int ac, char **av)
{
	if (ac != 2) return (1);

	Socket	s(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	std::string req = "GET /ip HTTP/1.1\r\nHost: ifconfig.me\r\n\r\n";
	char	buf[1024];

	s.Connect(AF_INET, av[1], 80);

	s.Send(req, 0);

	std::memset(buf, 0, sizeof(buf));
	s.Recv(buf, sizeof(buf), 0);

	std::cout << buf << std::endl;

	s.Close(); // not necessary

	return (0);
}
