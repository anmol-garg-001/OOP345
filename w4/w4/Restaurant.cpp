/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		if (reservations != nullptr) {
			deallocate();
			m_noOfRes = cnt;
			m_reservations = new Reservation[m_noOfRes];
			for (size_t i = 0; i < m_noOfRes; i++) {
				m_reservations[i] = *reservations[i];
			}
		}
	}
	size_t Restaurant::size() const {
		return m_noOfRes;
	}
	Restaurant::Restaurant(const Restaurant& copy) {
		*this = copy;
	}
	Restaurant& Restaurant::operator=(const Restaurant& copy) {
		if (this != &copy) {
			deallocate();
			m_noOfRes = copy.m_noOfRes;
			m_reservations = new Reservation[m_noOfRes];
			for (size_t i = 0; i < m_noOfRes; i++) {
				m_reservations[i] = copy.m_reservations[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& move) noexcept{
		*this = std::move(move);
	}
	Restaurant& Restaurant::operator=(Restaurant&& move) noexcept{
		if (this != &move) {
			deallocate();
			this->m_noOfRes = move.m_noOfRes;
			m_reservations = move.m_reservations;
			move.m_reservations = nullptr;
			move.m_noOfRes = 0;
		}
		return *this;
	}
	void Restaurant::deallocate()
	{
		delete[] m_reservations;
		m_reservations = nullptr;
		m_noOfRes = 0;
	}
	Restaurant::~Restaurant()
	{
		deallocate();
	}
	std::ostream& operator<<(std::ostream& os, Restaurant& restaurant) {
		static int counter = 1;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << counter++ << ")" << std::endl;
		os << "--------------------------" << std::endl;
		if (restaurant.m_noOfRes == 0) {
			os << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < restaurant.m_noOfRes; i++) {
				os << restaurant.m_reservations[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}