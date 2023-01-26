#ifndef SERVER_HPP
#define SERVER_HPP

#include "socket.hpp"
#include "epoll.hpp"
#include "datetime.hpp"
#include <vector>
#include <map>

/////////////////////////////
//
//			ENUMS
//
/////////////////////////////

enum	tcp_server_status_t
{
	TCP_SERVER_SUCCESS,
	TCP_SERVER_ERR_BIND,
	TCP_SERVER_ERR_LISTEN,
	TCP_SERVER_ERR_EPOLL,
	TCP_SERVER_ERR_ACCEPT,
	TCP_SERVER_ERR_EPOLL_ADD,
	TCP_SERVER_ERR_CLOSE
};

/////////////////////////////
//
//			TYPEDEFS
//
/////////////////////////////

typedef tcp_server_status_t	(*func)(void *);

class TCPServer
{
	public:
		/////////////////////////////
		//
		//		CANONIQUE FORM
		//
		/////////////////////////////
		
		TCPServer(void);
		TCPServer(const TCPServer& c);
		TCPServer	&operator=(const TCPServer& c);
		~TCPServer(void);

		/////////////////////////////
		//
		//		CONSTRUCTOR
		//
		/////////////////////////////
		
		TCPServer(const std::string& address);
		TCPServer(const std::string& ip, const port_t port);

		/////////////////////////////
		//
		//		Methods Utils
		//
		/////////////////////////////
		
		int					Wait(void);
		int					Handle(const Socket	*client);
		int					Start(void);
		int					Close(void);

		/////////////////////////////
		//
		//		Methods Clients
		//
		/////////////////////////////
		
		size_t				GetSizeClients(void);
		void				ShowAllClients(void);

		/////////////////////////////
		//
		//		Methods Callbacks
		//
		/////////////////////////////

		void				ShowCallbacks(void);

		/////////////////////////////
		//
		//		Set Address&Port
		//
		/////////////////////////////

		void				SetHost(const std::string& host);
		void				SetIP(const std::string& ip);
		void				SetPort(const port_t port);

		/////////////////////////////
		//
		//		Get Address&Port
		//
		/////////////////////////////
		
		const std::string&	GetHost(void);
		const std::string&	GetIP(void);
		const port_t&		GetPort(void);
	
	protected:
		Socket							_socket;
		Epoll							_epoll;
		DateTime						_dt;

	private:
		std::string						_host;
		std::string						_ip;
		port_t							_port;
		std::map<std::string, func>		_callbacks;
		std::vector<Socket*>			_clients;
};

#endif
