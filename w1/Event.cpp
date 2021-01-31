#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
size_t g_sysClock = 0;
using namespace std;
namespace sdds {
	Event::Event()
	{
		m_desc = nullptr;
		m_time = 0;
	}
	Event& Event::operator=(const Event& E)
	{
		if (E.m_desc != nullptr)
		{
			deallocate();
			m_desc = new char[strlen(E.m_desc) + 1];
			strcpy(m_desc, E.m_desc);
			m_time = E.m_time;
		}
		else
		{
			m_desc = nullptr;
			m_time = 0;
		}
		return *this;
	}
	Event::Event(const Event& E)
	{
		*this = E;
	}
	void Event::display()const
	{
		static size_t counter = 1;
		if (m_desc != nullptr)
		{
			cout << setfill(' ') << setw(2) << counter << ". " << setfill('0') << setw(2) << m_time / 3600 << ":" << setw(2) << (m_time % 3600) / 60 << ":" << setw(2) << (m_time % 3600) % 60 << " => " << m_desc << endl;
		}
		else
		{
			cout << setfill(' ') << setw(2) << counter << ". | No Event |" << endl;
		}
		counter++;
	}
	void Event::set(const char* desc)
	{
		if (desc != nullptr && desc[0] != '\0')
		{
			deallocate();
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
			m_time = g_sysClock;
		}
		else
		{
			deallocate();
		}
	}
	void Event::deallocate()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}
	Event::~Event()
	{
		deallocate();
	}
}
