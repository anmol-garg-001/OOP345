/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds {
	class Restaurant {
		// array of pointers to objects of type Reservation*
		Reservation* m_reservations{};

		// number of reservations in the system
		size_t m_noOfRes{}; 

		// to clear the object
		void deallocate(); 
	public:
		//  a constructor that receives as a parameter an array of reservations and stores in instance variables
		Restaurant(const Reservation* reservations[], size_t cnt); 

		// a query that returns the number of reservations in the system.
		size_t size() const; 

		// copy constructor
		Restaurant(const Restaurant&);

		// copy assignment operator
		Restaurant& operator=(const Restaurant&);

		// move constructor
		Restaurant(Restaurant&&) noexcept; 

		// move assignment operator
		Restaurant& operator=(Restaurant&&) noexcept; 
		
		// destructor
		~Restaurant();

		//the friend insertion operator to insert the content of a Restaurant object into an ostream object
		friend std::ostream& operator<<(std::ostream&, Restaurant&);
	};
}

#endif //!SDDS_RESTAURANT_H
