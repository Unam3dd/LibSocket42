#include <iostream>
#include "server.hpp"

int main(void)
{
	TCPServer	s("127.0.0.1", 8080);

	s.Start();
	s.Close();
	return (0);
}
