#include "server.hpp"
#include <iostream>

/*********************************************************************
*
* @brief    Handle Client Methods
*
* @param    Socket * Instance
*
* @return   tcp_server_status_t
*
*********************************************************************/

tcp_server_status_t	TCPServer::Handle(Socket *s)
{
	std::string	buf;
	std::string	res = "HTTP/1.1 200 OK\r\nContent-Length: 20\r\n\r\n<h1>Hello world</h1>";

	buf.reserve(1024);

	std::cout << this->_dt.Now("[%H:%M:%S]") << " New Data from : " << s->InetNtoa(s->GetSin()->sin_addr.s_addr)
		<< ":" << s->Ntohs(s->GetSin()->sin_port) << std::endl;
	s->Recv(buf, buf.capacity(), 0);
	std::cout << "Data : " << buf.data() << std::endl;
	s->Send(res, 0);
	std::cout << this->_dt.Now("[%H:%M:%S]") << " Close Connection : " << s->InetNtoa(s->GetSin()->sin_addr.s_addr)
		<< ":" << s->Ntohs(s->GetSin()->sin_port) << std::endl;
	s->Close();
	delete s;
	return (TCP_SERVER_SUCCESS);
}
