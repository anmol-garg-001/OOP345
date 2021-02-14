/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_SUMMABLE_H__
#define SDDS_PAIR_SUMMABLE_H__
#include <string>
#include <iostream>

#include "Pair.h"

namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial; //initial value for a summation.
		static size_t minFieldWidth; // minimum field width for pretty columnar output
	public:
		//default constructor
		PairSummable() {
			minFieldWidth = 0;
		}

		// two argument constructor for creating new object with key and value
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (key.size() > minFieldWidth)
				minFieldWidth = key.size();
		}

		// checks if the parameter has the same key as the current object
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return b.key() == this->key();
		}

		//adds the value of the parameter object to the value of the current object
		PairSummable& operator+=(const PairSummable& ps) {
			*this = PairSummable(this->key(), this->value() + ps.value());
			return *this;
		}

		// function to display the key value pair
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minFieldWidth);
			Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
		};
	};

	//initializing minimum field width
	template <typename V, typename K>
	size_t PairSummable<V, K>::minFieldWidth = 0;

	//initializing inital summation value if we are adding integers
	template<>
	int PairSummable<int, std::string>::initial = 0;

	//initializing inital summation value if we are adding strings
	template<>
	std::string PairSummable<std::string, std::string>::initial = "";

	// specialization for concatenating the strings with ',' as the seperation when adding strings 
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable <std::string, std::string>& ps) {
		if (this->value().empty()) {
			*this = PairSummable(this->key(), ps.value());
		}
		else {
			*this = PairSummable(this->key(), this->value() + ", " + ps.value());
		}
		return *this;
	};
}
#endif // !SDDS_PAIR_SUMMABLE_H__