#include "socket.hpp"
#include <unistd.h>
#include <fcntl.h>

/*********************************************************************
*
* @brief    Fnclt Wrapper function
* 			see fcntl man pages for more information
*
* @param    cmd: cmd like F_SETFD| F_GETFD
* @param    args: long argument to apply
*
* @return    F_DUPFD, FT_GETFD, etc.. otherwise -1 is return was an error was occured
*
*********************************************************************/
int	Socket::Fcntl(int cmd, long arg)
{
	return (fcntl(this->_fd, cmd, arg));
}

/*********************************************************************
*
* @brief    Fnclt Wrapper function
* 			see fcntl man pages for more information
*
* @param    fd: int target file descriptor
* @param    cmd: cmd like F_SETFD| F_GETFD
* @param    args: long argument to apply
*
* @return    F_DUPFD, FT_GETFD, etc.. otherwise -1 is return was an error was occured
*
*********************************************************************/
int	Socket::Fcntl(int fd, int cmd, long arg)
{
	return (fcntl(fd, cmd, arg));
}
