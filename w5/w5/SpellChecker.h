/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
const int noOfWords = 6;
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[noOfWords]{};
		std::string m_goodWords[noOfWords]{};
		int m_replaceCount[noOfWords]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif //!SDDS_SPELLCHECKER_H