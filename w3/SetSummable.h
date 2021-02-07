/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_SUMMABLE_H__
#define SDDS_SET_SUMMABLE_H__

#include "Set.h"

namespace sdds {
	template <int N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (int i = 0; i < N; i++)
			{
				if (accumulator.isCompatibleWith(this->get(i)))
				{
					accumulator += this->get(i);
				}
			}
			return accumulator;
		}
	};
}

#endif // !SDDS_SET_SUMMABLE_H__