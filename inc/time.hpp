#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <ctime>

class DateTime
{
	public:
		DateTime(void);
		DateTime(const DateTime& t);
		DateTime	&operator=(const DateTime& t);
		~DateTime(void);

		std::string		Now(void);
		std::string		Now(const std::string& fmt);
		std::string&	Now(std::string& buf);
		std::string&	Now(const std::string& fmt, std::string& buf);

	private:
		time_t	rawtime;
};

#endif
