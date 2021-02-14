/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_SUMMABLE_H__
#define SDDS_SET_SUMMABLE_H__

#include "Set.h"

namespace sdds {
	template <size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		//accumulates into a local object in the collection that satisfy filter parameter
		T accumulate(const std::string& filter) const {
			T accumulatorObj(filter);
			for (size_t i = 0; i < N; i++)
				if (accumulatorObj.isCompatibleWith(this->get(i)))
					accumulatorObj += this->get(i);
			return accumulatorObj;
		}
	};
}
#endif // !SDDS_SET_SUMMABLE_H__