/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199
Date: 31/01/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STRINGSET_H_
#define SDDS_STRINGSET_H_
#include <string>
namespace sdds {
	class StringSet {
		std::string* m_strings; // dynamic array of strings
		std::string m_filename; // to store the filename
		size_t m_noOfStrings; // number of records
		void setEmpty(); // private method to set the object to an empty state
	public:
		StringSet();//default constructor
		StringSet(const std::string&);// one argument constructor accepting an integer value
		StringSet(const StringSet&);// copy constructor
		StringSet(StringSet&&);// move constructor
		StringSet& operator=(StringSet&&);// move assignment operator
		StringSet& operator=(const StringSet&);// copy assignment operator
		size_t size() const;// a query to return the size of array
		std::string operator[](size_t) const;// overload for the [] operator
		~StringSet();// destructor
	};
}
#endif // !SDDS_RECORDSET_H__
