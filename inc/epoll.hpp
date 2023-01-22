/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoll.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:09 by stales            #+#    #+#             */
/*   Updated: 2023/01/22 16:56:57 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EPOLL_HPP
#define EPOLL_HPP

//////////////////////////////////
//
//	       INCLUDES
//
/////////////////////////////////

#include <sys/epoll.h>

//////////////////////////////////
//
//	       DEFINES
//
/////////////////////////////////

#ifndef MAX_EV
#define MAX_EV 16
#endif

//////////////////////////////////
//
//	       TYPEDEFS
//
/////////////////////////////////

typedef epoll_event	ev_t;

class Epoll
{
	public:

		//////////////////////////////////
		//
		//	       Constructor
		//
		/////////////////////////////////

		Epoll(void);
		Epoll(size_t size);
		Epoll(int flags);
		Epoll(const Epoll& e);
		Epoll &operator=(const Epoll& e);
		bool operator==(const Epoll& e);

		//////////////////////////////////
		//
		//	       Create Instance
		//
		/////////////////////////////////

		int	Create(size_t size);
		int	Create(int flags);

		//////////////////////////////////
		//
		//	       Control Epoll
		//
		/////////////////////////////////

		int	Ctl(int op, int fd, ev_t *ev);
		int Ctl(int efd, int op, int fd, ev_t *ev);

		//////////////////////////////////
		//
		//	       Wait Epoll
		//
		/////////////////////////////////

		int	Wait(ev_t *events, int maxevents, int timeout);
		int Wait(int efd, ev_t *events, int maxevents, int timeout);

		//////////////////////////////////
		//
		//	       Utils
		//
		/////////////////////////////////
		
		inline bool	IsInitialized(void) { return (this->_isinit); }

		//////////////////////////////////
		//
		//	       Close
		//
		/////////////////////////////////

		int	Close(int fd);
		int	Close(void);

		//////////////////////////////////
		//
		//	       Destructor
		//
		/////////////////////////////////

		~Epoll(void);

	private:

		//////////////////////////////////
		//
		//	       Variables
		//
		/////////////////////////////////

		epoll_event	_init_ev;
		int			_efd;
		bool		_isinit;
};

#endif
