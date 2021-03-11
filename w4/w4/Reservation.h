/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>

namespace sdds {
	class Reservation {
		// the Id of the reservation
		std::string m_reservationId;
		
		// the name on the reservation
		std::string m_name; 
		
		// the email to be used to send a confirmation that the reservation can be honored or cannot
		std::string m_email; 

		// the number of people in the party
		int m_partySize;

		// the day when the party expects to come
		int m_day; 

		// the hour when the party expects to come
		int m_hour;
	public:
		// default constructor
		Reservation();

		// this constructor extracts information about the reservation from the string and stores it in the instance's attributes
		Reservation(const std::string&); 

		// the friend insertion operator to insert the contents of a reservation object into an ostream object
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

#endif //!SDDS_RESERVATION_H