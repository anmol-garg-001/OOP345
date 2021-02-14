/*Name: Anmol Garg
Seneca Id: 149916199
Seneca email: agarg15@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H__
#define SDDS_SET_H__

namespace sdds {
	template <size_t N, typename T>
	class Set {
		T arraySet[N]; // collection of elements of type T
		size_t noOfElements; // current no of elements in the collection
	public:
		//default constructor
		Set() : arraySet{}, noOfElements{ 0 } {};

		//returns the current number of elements in the collection
		size_t size() const {
			return noOfElements;
		};

		//returns a reference to the element at index idx
		const T& get(size_t idx) const {
			return arraySet[idx];
		};

		// operator += for adding an element in the collection if their is capacity
		void operator+=(const T& item) {
			if (noOfElements < N) {
				arraySet[noOfElements] = item;
				noOfElements++;
			}
		};
	};

}

#endif // !SDDS_SET_H__