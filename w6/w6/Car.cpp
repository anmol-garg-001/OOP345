/*
Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15a@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>
#include <iomanip>
#include <exception>

#include "Car.h"
namespace sdds {
	
	Car::Car(std::istream& is){
		 std::string temp;
		 std::getline(is,temp,',');

		 m_maker = trim(temp);

		 std::getline(is, temp, ',');
		 temp = trim(temp);
		 if (temp.empty()) 
			m_condition = 'n';
		 else {
			 m_condition = temp[0];
			 if (m_condition != 'u' && m_condition != 'n' && m_condition != 'b') {
				 throw std::invalid_argument("the record is invalid");
			 }
		 }

		 try {
			 std::getline(is, temp, ',');
			 m_topSpeed = stod(trim(temp));
		 }
		catch (std::invalid_argument & e) {
			 throw e;
		}
	}
	
	std::string Car::condition() const
	{
		std::string condition;
		if (m_condition == 'n') {
			condition = "new";
		}
		else if(m_condition == 'u') {
			condition = "used";
		}
		else if (m_condition == 'b') {
			condition = "broken";
		}
		return condition;
	}
	double Car::topSpeed() const{
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const{
		out << "| " << std::setw(10) << std::right  << m_maker;
		out << " | " << std::setw(6) << std::left << condition();
		out << " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
	}
	
}