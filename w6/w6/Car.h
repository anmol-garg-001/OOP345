/*
Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15a@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car :public Vehicle{
		std::string m_maker{};
		char m_condition{};
		double m_topSpeed{};
	public:
		Car() {};
		~Car() {};
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif