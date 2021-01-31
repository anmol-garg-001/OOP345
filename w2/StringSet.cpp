/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199
Date: 31/01/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include "StringSet.h"

namespace sdds {
	void StringSet::setEmpty() {
		m_noOfStrings = 0;
		m_strings = nullptr;
		m_filename = "";
	}

	StringSet::StringSet() {
		setEmpty();
	}

	StringSet::StringSet(const std::string& str) : m_strings{ nullptr }, m_noOfStrings{ 0 } {
		if (!str.empty()) {

			m_filename = str;
			std::string temp;
			std::ifstream is(str);

			while (getline(is, temp, ' ')) {
				m_noOfStrings++;
			}

			if (m_noOfStrings > 0) {
				is.clear();
				is.seekg(0);//moving the file pointer back to start

				m_strings = new std::string[m_noOfStrings];
				size_t strIndex{ 0 };
				while (getline(is, m_strings[strIndex], ' ')) {
					strIndex++;
				}
			}
			is.close();//closing the file reference
		}
		else {
			setEmpty();
		}
	}


	StringSet::StringSet(const StringSet& cpy) { //copy constructor
		*this = cpy;
	}

	StringSet::StringSet(StringSet&& mv) {
		*this = std::move(mv);
	}

	StringSet& StringSet::operator=(StringSet&& mv) {
		if (this != &mv) {
			m_filename = mv.m_filename;
			mv.m_filename = "";
			m_noOfStrings = mv.m_noOfStrings;
			mv.m_noOfStrings = 0;
			m_strings = mv.m_strings;
			mv.m_strings = nullptr;
		}
		return *this;
	}

	StringSet& StringSet::operator=(const StringSet& copy) {
		if (this != &copy) {//checking that it's not the same
			if (copy.m_strings != nullptr) {  //checking if the copy is valid
				m_filename = copy.m_filename;
				m_noOfStrings = copy.m_noOfStrings;
				m_strings = new std::string[m_noOfStrings];
				for (size_t i = 0; i < copy.m_noOfStrings; i++) {
					m_strings[i] = copy.m_strings[i];
				}
			}
		}
		return *this;
	}
	size_t StringSet::size() const{
		return m_noOfStrings;
	}
	std::string StringSet::operator[](size_t index) const{
		std::string stringAt = "";
		if (index < m_noOfStrings) {
			stringAt = m_strings[index];
		}
		return stringAt;
	}
	StringSet::~StringSet() {
		delete[] m_strings;
	}
}