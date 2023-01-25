#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <ctime>

class DateTime
{
	public:
		DateTime(void);
		~DateTime(void);

		std::string			Now(void);
		std::string			Now(const std::string& fmt);
};

#endif
