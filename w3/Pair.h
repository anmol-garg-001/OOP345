/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__
#include <iostream>
namespace sdds {
	template<typename V, typename K>
	class Pair {
		K m_key; // key member variable
		V m_value; // value member variable
	public:
		//default constructor
		Pair() : m_key{}, m_value{} {};

		// copies the values referred to by the parameters into the instance variables
		Pair(const K& key, const V& value) : m_key{ key }, m_value{ value } {};

		//returns the value component of the pair
		const V& value() const {
			return m_value;
		};

		//returns the key component of the pair
		const K& key() const {
			return m_key;
		};

		//inserts into stream os the key and the value of the pair
		virtual void display(std::ostream& os) const {
			os << key() << " : " << value() << std::endl;
		};

	};
	//helper extraction operator for display
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	};
}

#endif // !SDDS_PAIR_H__