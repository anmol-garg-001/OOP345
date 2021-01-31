/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199
Date: 31/01/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_
#include <chrono>
#include <string>
#define MAX_EVENTS 10 // maximum number of events

namespace sdds {
	class TimedEvents {
		int m_noOfRecords; // number of records
		std::chrono::steady_clock::time_point m_startTime; // start time of the TimedEvents
		std::chrono::steady_clock::time_point m_endTime; // end time of the TimedEvents
		struct {
			std::string m_eventName; // name of event
			std::string m_timeUnits; // units of time
			std::chrono::steady_clock::duration m_duration; // duration of event
		}events[MAX_EVENTS];
	public:
		TimedEvents(); // default constructor
		void startClock(); // method to start the clock
		void stopClock(); // method to stop the clock
		void addEvent(const char*); // add an event
		friend std::ostream& operator<<(std::ostream&, TimedEvents&); // insertion operator overload for output
	};
}

#endif // !SDDS_TIMEDEVENTS_H__