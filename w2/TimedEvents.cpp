/* Name: Anmol Garg
Email: agarg15@myseneca.ca
Seneca Id: 149916199
Date: 31/01/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents()
	{
		m_noOfRecords = 0;
		for (int i = 0; i < MAX_EVENTS; i++)
		{
			events[i].m_eventName = "";
			events[i].m_timeUnits = "";
			events[i].m_duration = {};
		}
	}
	void TimedEvents::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* eventName)
	{
		int index = -1;
		bool flag = true;
		for (int i = 0; i < MAX_EVENTS && flag; i++) 
		{
			if (events[i].m_eventName == "") 
			{
				index = i;
				flag = false;
			}
		}
		if (index > -1)
		{
			events[index].m_eventName = eventName;
			events[index].m_timeUnits = "nanoseconds";
			events[index].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
			m_noOfRecords++;
		}
	}
	std::ostream& operator<<(std::ostream& os, TimedEvents& timedEvents)
	{
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (int i = 0; i < timedEvents.m_noOfRecords; i++) {
			os << std::setw(20) << std::left << timedEvents.events[i].m_eventName;
			os << std::setw(12) << std::right << timedEvents.events[i].m_duration.count() << " " << timedEvents.events[i].m_timeUnits << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}