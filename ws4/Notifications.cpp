#include <iostream>
#include "Notifications.h"
using namespace w4;
Notifications::Notifications()
{
	for (size_t i = 0; i < max_size_; ++i)
		msg_ptr_ar[i] = nullptr;
}
// copy constructor
Notifications::Notifications(Notifications &other)
{
	*this = other;
}
// copy assignment
Notifications &Notifications::operator=(Notifications &other)
{
	if (this != &other)
	{
		msg_size_ = other.msg_size_;
		for (size_t i = 0; i < max_size_; ++i)
		{
			delete msg_ptr_ar[i];
			msg_ptr_ar[i] = !other.msg_ptr_ar[i] ? nullptr : new Message(*other.msg_ptr_ar[i]);
		}
	}
	return *this;
}
// move constructor
Notifications::Notifications(Notifications &&other)
{
	*this = std::move(other);
}
// move assignment
Notifications &Notifications::operator=(Notifications &&other)
{
	if (this != &other)
	{
		msg_size_ = other.msg_size_;
		for (size_t i = 0; i < msg_size_; ++i)
		{
			delete msg_ptr_ar[i];

			if (!other.msg_ptr_ar[i])
			{
				msg_ptr_ar[i] = nullptr;
			}
			else
			{
				msg_ptr_ar[i] = other.msg_ptr_ar[i];
				other.msg_ptr_ar[i] = nullptr;
			}
		}
	}
	return *this;
}
Notifications::~Notifications()
{
	for (size_t i = 0; max_size_ > i; i++)
		delete msg_ptr_ar[i];
}
void Notifications::operator+=(const Message &msg)
{
	if (msg_size_ < max_size_)
	{
		msg_ptr_ar[msg_size_] = new Message(msg);
		msg_size_++;
	}
	else
	{
		std::cout << "Notification List is full!!" << std::endl;
	}
}
void Notifications::display(std::ostream &os) const
{
	for (size_t i = 0; msg_size_ > i; i++)
	{
		msg_ptr_ar[i]->display(os);
		os << std::endl;
	}
}
