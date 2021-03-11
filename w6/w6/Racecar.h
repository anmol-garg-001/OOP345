/*
Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15a@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <istream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{ 0 };
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif