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
	Reservation::Reservation()
	{
		m_reservationId = "";
		m_name = "";
		m_email = "";
		m_partySize = 0;
		m_day = 0;
		m_hour = 0;
	}
	Reservation::Reservation(const std::string& str) {

		std::string local_str = str;

		local_str.erase(0, local_str.find_first_not_of(' '));
		size_t index = local_str.find(':');
		std::string tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_reservationId = tempStr;

		local_str.erase(0, index + 1);
		local_str.erase(0, local_str.find_first_not_of(' '));
		index = local_str.find(',');
		tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_name = tempStr;

		local_str.erase(0, index + 1);
		local_str.erase(0, local_str.find_first_not_of(' '));
		index = local_str.find(',');
		tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_email = tempStr;

		local_str.erase(0, index + 1);
		local_str.erase(0, local_str.find_first_not_of(' '));
		index = local_str.find(',');
		tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_partySize = std::stoi(tempStr);

		local_str.erase(0, index + 1);
		local_str.erase(0, local_str.find_first_not_of(' '));
		index = local_str.find(',');
		tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_day = std::stoi(tempStr);

		local_str.erase(0, index + 1);
		local_str.erase(0, local_str.find_first_not_of(' '));
		index = local_str.find(',');
		tempStr = local_str.substr(0, index);
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_hour = std::stoi(tempStr);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& obj) {
		std::string hour_food_type{};
		std::string people_person = obj.m_partySize == 1 ? " person." : " people.";

		os << "Reservation " << std::setw(10) << std::right << obj.m_reservationId << ": ";
		os << std::setw(20) << std::right << obj.m_name << "  ";
		os << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    ";

		if (obj.m_hour >= 6 && obj.m_hour <= 9) {
			hour_food_type = "Breakfast";
		}
		else if (obj.m_hour >= 11 && obj.m_hour <= 15) {
			hour_food_type = "Lunch";
		}
		else if (obj.m_hour >= 17 && obj.m_hour <= 21) {
			hour_food_type = "Dinner";
		}
		else {
			hour_food_type = "Drinks";
		}

		os << hour_food_type << " on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_partySize << people_person << std::endl;
		return os;
	}
}