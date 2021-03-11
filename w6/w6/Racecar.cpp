/*
Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15a@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>

#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in){
		std::string temp;
		std::getline(in,temp,',');
		m_booster = std::stod(trim(temp));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}