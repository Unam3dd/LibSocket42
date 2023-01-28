#include <iostream>
#include "server.hpp"

int main(void)
{
	TCPServer	s("127.0.0.1", 8080);
	tcp_server_status_t	status;

	status = s.Start();
	
	if (status) {
		std::cout << s.GetError(status) << std::endl;
		return (1);
	}

	status = s.Close();
	if (status) {
		std::cout << s.GetError(status) << std::endl;
		return (1);
	}
	return (0);
}
