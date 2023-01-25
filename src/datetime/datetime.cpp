#include "datetime.hpp"

DateTime::DateTime(void) {}

DateTime::~DateTime(void) {}

std::string	DateTime::Now(void)
{
	time_t	rawtime = 0;

	time(&rawtime);

	return (ctime(&rawtime));
}

std::string	DateTime::Now(const std::string& fmt)
{
	std::string	t;
	tm			*tinfo = NULL;
	time_t		rawtime = 0;

	if (fmt.empty()) return ("");
	t.reserve(80);
	time(&rawtime);
	tinfo = localtime(&rawtime);
	std::strftime((char *)t.c_str(), t.capacity(), fmt.c_str(), tinfo);
	return (t.data());
}
