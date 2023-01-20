/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:29:07 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:38:46 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstddef>
#include <new>
#include <iostream>

/*********************************************************************
*
* @brief	Wrapper on accept without socketfd
*
* @param	void
*
* @return	pointer to a new Socket class if success, NULL if error
*
*********************************************************************/
Socket	*Socket::Accept(void)
{
	sin_t		s;
	Socket		*n = NULL;
	socklen_t	len = sizeof(sin_t);
	int			fd = 0;

	if ((fd = accept(this->_fd, (sockaddr *)&s, &len)) < 0)
		return (NULL);
	n = new (std::nothrow) Socket;
	if (n == NULL) return (NULL);
	n->Setfd(fd);
	n->CopySin(&s);
	return (n);
}

/*********************************************************************
*
* @brief	Wrapper on accept with socketfd
*
* @param	fd: socket file descriptor
*
* @return	pointer to a new Socket class if success, NULL if error
*
*********************************************************************/
Socket	*Socket::Accept(int fd)
{
	sin_t		s;
	Socket		*n = NULL;
	socklen_t	len = sizeof(sin_t);
	int			fdc = 0;

	if ((fdc = accept(fd, (sockaddr *)&s, &len)) < 0)
		return (NULL);
	n = new (std::nothrow) Socket;
	if (n == NULL) return (NULL);
	n->Setfd(fdc);
	n->CopySin(&s);
	return (n);
}
