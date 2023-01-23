#include "../inc/socket.hpp"
#include <iostream>
#include <cstring>

// Compile : c++ -Wall -Wextra -Werror -std=c++98 get.cpp ../libsocket.a

int main(void)
{
	Socket	s(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sin_t	*ptr = s.GetSin();
	std::string req = "GET /ip HTTP/1.1\r\nHost: ifconfig.me\r\n\r\n";
	char	buf[1024];

	if (s.Connect(AF_INET, "34.160.111.145", 80))
		std::cerr << "Error: Failed to connect !" << std::endl;

	s.Send(req, 0);

	std::memset(buf, 0, sizeof(buf));
	s.Recv(buf, sizeof(buf), 0);

	std::cout << buf << '\n' << std::endl;
	std::cout << s.InetNtoa(ptr->sin_addr.s_addr) << std::endl;
	std::cout << s.Ntohs(ptr->sin_port) << std::endl; 

	s.Close(); // not necessary

	return (0);
}
