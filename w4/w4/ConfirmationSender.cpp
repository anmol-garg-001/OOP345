/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	void ConfirmationSender::deallocate()
	{
		delete[] m_reservations;
		m_reservations = nullptr;
		m_noOfRes = 0;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = false;
		for (size_t i = 0; i < m_noOfRes && !flag; i++) {
			if (&res == this->m_reservations[i]) {
				flag = true;
			}
		}

		if (!flag) {
			const Reservation** temp = new const Reservation * [m_noOfRes + 1];
			for (size_t i = 0; i < m_noOfRes; i++) {
				temp[i] = m_reservations[i];
			}
			temp[m_noOfRes] = &res;
			m_noOfRes++;
			delete[] m_reservations;
			m_reservations = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < m_noOfRes; i++) {
			if (m_reservations[i] == &res) {
				m_reservations[i] = nullptr;
				for (size_t j = i; j < m_noOfRes; j++)
				{
					m_reservations[j] = m_reservations[j + 1];
				}
				m_reservations[m_noOfRes] = nullptr;
				m_noOfRes--;
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& copy) {
		*this = copy;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& copy)
	{
		if (this != &copy) {
			deallocate();
			this->m_noOfRes = copy.m_noOfRes;
			m_reservations = new const Reservation * [m_noOfRes];
			for (size_t i = 0; i < m_noOfRes; i++) {
				this->m_reservations[i] = copy.m_reservations[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& move) noexcept {
		*this = std::move(move);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& move) noexcept {
		if (this != &move) {
			deallocate();
			this->m_noOfRes = move.m_noOfRes;
			m_reservations = move.m_reservations;
			move.m_reservations = nullptr;
			move.m_noOfRes = 0;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		deallocate();
	}

	std::ostream& operator<<(std::ostream& os, ConfirmationSender& obj) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (obj.m_noOfRes == 0) {
			os << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < obj.m_noOfRes; i++) {
				os << *obj.m_reservations[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
