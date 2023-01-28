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
	TCP_SERVER_ERR_CREATE,
	TCP_SERVER_ERR_BIND,
	TCP_SERVER_ERR_LISTEN,
	TCP_SERVER_ERR_EPOLL,
	TCP_SERVER_ERR_ACCEPT,
	TCP_SERVER_ERR_EPOLL_ADD,
	TCP_SERVER_ERR_CLOSE,
	TCP_SERVER_ERR_OPT
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
		
		tcp_server_status_t	Wait(void);
		tcp_server_status_t	Handle(const Socket	*client);
		tcp_server_status_t	Start(void);
		tcp_server_status_t	Close(void);

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

		const std::map<tcp_server_status_t, std::string>& _error_table(void);
		const std::string& GetError(tcp_server_status_t status);
	
	protected:
		Socket													_socket;
		Epoll													_epoll;
		DateTime												_dt;

	private:
		std::string												_host;
		std::string												_ip;
		port_t													_port;
		std::map<std::string, func>								_callbacks;
		std::vector<Socket*>									_clients;
};

#endif
