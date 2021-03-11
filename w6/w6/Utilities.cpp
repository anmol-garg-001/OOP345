/*
Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15a@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <sstream>

#include "Utilities.h"
#include "Racecar.h"


namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		std::string temp;
		std::getline(in, temp, '\n');

		std::string val1 = trim(temp);

		std::stringstream str;
		str << temp;


		if (str && !temp.empty()) {

			if (val1 == "c" || val1 == "C") {

				return new Car(str);

			}
			else if (val1 == "r" || val1 == "R") {
				return new Racecar(str);
			}
			else {
				if (val1 != "u" && val1 != "n" && val1 != "b") {
					std::string err = "Unrecognized record type: [" + val1 + "]";
					throw err;
				}
				
			}
		}
		return nullptr;
	}

	std::string trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, str.find(","));
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);

		return temp;
	}
}