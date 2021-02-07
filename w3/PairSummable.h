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
		static V initial;
		static size_t fieldWidth;
	public:
		PairSummable() {
			fieldWidth = 0;
		}
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (key.size() > fieldWidth)
				fieldWidth = key.size();
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return b.key() == this->key();
		}

		PairSummable& operator+=(const PairSummable& ps) {
			*this = PairSummable(this->key(), this->value() + ps.value());
			return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(fieldWidth);
			Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
		};
	};

	template <typename V, typename K>
	size_t PairSummable<V, K>::fieldWidth = 0;

	template<>
	int PairSummable<int, std::string>::initial = 0;

	template<>
	std::string PairSummable<std::string, std::string>::initial = "";

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable <std::string, std::string>& ps) {
		*this = PairSummable(this->key(), this->value() == "" ? ps.value() : this->value() + ", " + ps.value());
		return *this;
	};
}
#endif // !SDDS_PAIR_SUMMABLE_H__