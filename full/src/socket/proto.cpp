#include "socket.hpp"
#include <netdb.h>

/*********************************************************************
*
* @brief    GetProtoByName retrieve protocol information
*
* @param   name: string 
*
* @return   struct protent_t * or NULL if failed 
*
*********************************************************************/
prot_t	*Socket::GetProtoByName(const std::string& name)
{
	return ((prot_t *)getprotobyname(name.c_str()));
}

/*********************************************************************
*
* @brief    GetProtoByNumber retrieve protocol information
*
* @param   proto: integer 
*
* @return   struct protent_t * or NULL if failed 
*
*********************************************************************/
prot_t	*Socket::GetProtoByNumber(int proto)
{
	return ((prot_t *)getprotobynumber(proto));
}

/*********************************************************************
*
* @brief    Close Protoent Database
*
* @param    void
*
* @return   void (nothing) 
*
*********************************************************************/
void	Socket::EndProtEnt(void)
{
	endprotoent();
}
