/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include<iostream>
#include <algorithm>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation(const std::string& str) {

		std::string parameter_str = str; // creating a copy of the parameter string

		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		int index = parameter_str.find(':');
		std::string temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_reservationId = temp;

		parameter_str.erase(0, index + 1);
		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		index = parameter_str.find(',');
		temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_name = temp;

		parameter_str.erase(0, index + 1);
		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		index = parameter_str.find(',');
		temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_email = temp;

		parameter_str.erase(0, index + 1);
		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		index = parameter_str.find(',');
		temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_partySize = std::stoi(temp);

		parameter_str.erase(0, index + 1);
		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		index = parameter_str.find(',');
		temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_day = std::stoi(temp);

		parameter_str.erase(0, index + 1);
		parameter_str.erase(0, parameter_str.find_first_not_of(' '));
		index = parameter_str.find(',');
		temp = parameter_str.substr(0, index);
		temp.erase(temp.find_last_not_of(' ') + 1);
		m_hour = std::stoi(temp);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& obj) {
		std::string no_people_str = obj.m_partySize == 1 ? " person." : " people.";
		std::string meal_type_str{};

		os << "Reservation " << std::setw(10) << std::right << obj.m_reservationId << ": ";
		os << std::setw(20) << std::right << obj.m_name << "  ";
		os << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    ";

		if (obj.m_hour >= 6 && obj.m_hour <= 9) {
			meal_type_str = "Breakfast";
		}
		else if (obj.m_hour >= 11 && obj.m_hour <= 15) {
			meal_type_str = "Lunch";
		}
		else if (obj.m_hour >= 17 && obj.m_hour <= 21) {
			meal_type_str = "Dinner";
		}
		else {
			meal_type_str = "Drinks";
		}

		os << meal_type_str << " on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_partySize << no_people_str << std::endl;
		return os;
	}
}