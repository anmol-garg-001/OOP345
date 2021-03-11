/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <algorithm>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	const std::string& Movie::title() const {
		return m_title;
	}
	std::string Movie::trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, str.find(","));
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);
		return temp;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;
		m_title = trim(temp);
		m_release = std::stoi(trim(temp));
		m_desc = temp.substr(temp.find_first_not_of(" \f\n\r\t\v"), temp.find_last_not_of(" \f\n\r\t\v") + 1);;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& obj) {
		if (!obj.title().empty()) {
			os << std::setw(40) << obj.title() << " | ";
			os << std::setw(4) << obj.m_release << " | ";
			os << obj.m_desc << std::endl;
		}
		return os;
	}
}
