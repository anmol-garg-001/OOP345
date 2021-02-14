/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		// array of pointers to objects of type Reservation**
		const Reservation** m_reservations{}; 

		// number of reservations in the system
		size_t m_noOfRes{}; 

		// to clear the object
		void deallocate(); 
	public:
		// default constructor -> no implementation
		ConfirmationSender() {};

		// adds the reservation res to the array by adding its address.
		ConfirmationSender& operator+=(const Reservation& res); 

		// removes the reservation res from the array by removing its address
		ConfirmationSender& operator-=(const Reservation& res); 

		// copy constructor
		ConfirmationSender(const ConfirmationSender&); 

		// copy assignment operator
		ConfirmationSender& operator=(const ConfirmationSender&); 

		// move constructor
		ConfirmationSender(ConfirmationSender&&) noexcept; 

		// move assignment operator
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept; 

		// destructor
		~ConfirmationSender(); 

		// the insertion operator to insert the content of a ConfirmationSender object into an ostream object
		friend std::ostream& operator<<(std::ostream&, ConfirmationSender&);
	};
}
#endif //!SDDS_CONFIRMATIONSENDER_H