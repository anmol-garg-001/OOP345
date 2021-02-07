/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H__
#define SDDS_SET_H__

namespace sdds {
	template <int N, typename T>
	class Set {
		T m_arraySet[N];
		int m_noOfElements;
	public:
		//default constructor
		Set() : m_arraySet{}, m_noOfElements{ 0 } {};
		size_t size() const {
			return m_noOfElements;
		};
		const T& get(size_t idx) const {
			return m_arraySet[idx];
		};
		void operator+=(const T& item) {
			if (m_noOfElements < N) {
				m_arraySet[m_noOfElements] = item;
				m_noOfElements++;
			}
		};
	};

}

#endif // !SDDS_SET_H__