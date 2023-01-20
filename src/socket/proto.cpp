#include "socket.hpp"
#include <netdb.h>

/*********************************************************************
*
* @brief    GetProtoByName get Protocol Information by name
*
* @param   name: string which represent protocol name 
*
* @return   protent structure pointer or NULL 
*
*********************************************************************/
prot_t	*Socket::GetProtoByName(const std::string &name)
{
	return ((prot_t *)getprotobyname(name.c_str()));
}
