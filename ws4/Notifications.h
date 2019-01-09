// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 05.10.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include "Message.h"

namespace w4
{
	class Notifications
	{
		size_t max_size_ = 10;
		size_t msg_size_{};
		Message* msg_ptr_ar[10]{};

	public:
		Notifications();
		Notifications(Notifications&);
		Notifications& operator=(Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif // end W4_NOTIFICATIONS_H
