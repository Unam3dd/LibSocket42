#include "socket.hpp"
#include <cstddef>
#include <netdb.h>

/*********************************************************************
*
* @brief    Wrapper of getserbyport function
*
* @param    port: Port number
* @param    proto: set protocol, If proto is NULL, any protocol will be matched
*
* @return    struct servent_t* or NULL if error was occured
*
*********************************************************************/

serv_t	*Socket::GetServiceByPort(int port, const char *proto)
{
	return (getservbyport(port, proto));
}

/*********************************************************************
*
* @brief    wrapper of getservbyname function
*
* @param   name: Service name
* @param   proto: set protocol, If proto is NULL, any protocol will be matched
*
* @return   struct servent_t* or NULL if error was occured 
*
*********************************************************************/
serv_t	*Socket::GetServiceByName(const char *name, const char *proto)
{
	return (getservbyname(name, proto));
}

/*********************************************************************
*
* @brief    wrapper of endservent function
*
* @param    void
*
* @return   void 
*
*********************************************************************/
void	Socket::EndServiceDB(void)
{
	endservent();
}
