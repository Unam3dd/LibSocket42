#include "socket.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

/*********************************************************************
*
* @brief    Function like inet_addr reconstruct 
* 			IP address from string to unsigned integer
*
* @param    ip:	pass the string which represent IP address
*
* @return   IP Address formated on addr_t (unsigned int) 
*
*********************************************************************/

static int	check_format(const std::string& ip)
{
	if (ip.size() > 0xF || ip.at(0) == '.' || ip.at(ip.size()-1) == '.')
		return (1);

	if (std::strspn(ip.c_str(), "0123456789.") != ip.size())
		return (1);

	size_t	d = 0;
	size_t	total_p = 0;
	size_t	i = 0;

	for (i = 0; i < ip.size(); i++) {
		if (d > 3) return (1);
		if (ip.at(i) == '.' && std::strspn(ip.substr(i).c_str(), ".") > 1) return (1);
		if (ip.at(i) == '.' && d <= 3) { total_p++; d = (d == 3) ? 0 : d; };
		if (std::isdigit(ip.at(i))) d++;
	}
	return (total_p == 3 ? 0 : 1);
}

addr_t	Socket::InetAddr(const std::string& ip)
{
	if (ip.empty() || check_format(ip)) return (0);

	std::string	tmp = ip;
	std::string data;
	uint8_t		addr[4] = {0, 0, 0, 0};

	for (int i = 0; i < 4; i++) {
		data = tmp.substr(0, tmp.find("."));
		addr[i] = (uint8_t)(std::atoi(data.c_str()) & 0xFF);
		tmp = tmp.substr(tmp.find(".")+1);
	}

	return ((addr_t)(addr[3] << 24 | addr[2] << 16 | addr[1] << 8 | addr[0]));
}
