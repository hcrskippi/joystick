#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <sstream>

namespace jsutility{

	template<typename TYPE>
	std::string toString(TYPE data){
		std::stringstream ss;
		std::string ret;
		ss << data;
		ss >> ret;
		return ret;
	}

}

#endif
