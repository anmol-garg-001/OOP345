#ifndef _SDDS_EVENT_H_
#define _SDDS_EVENT_H_
#include <cstddef> 
extern size_t g_sysClock;
namespace sdds {
	class Event
	{
		char* m_desc;
		size_t m_time;
	public:
		Event();
		Event(const Event& E);
		Event& operator=(const Event& E);
		void display()const;
		void set(const char* desc = nullptr);
		void deallocate();
		~Event();
	};
}
#endif // !_SDDS_EVENT_H_
