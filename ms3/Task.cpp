// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.12.2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Task.h"

Task::Task(const std::string& str) : Item(str)
{
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os)
{
	if (m_orders.empty() || m_orders.front().getOrderFillState())
		return;

	while (!m_orders.front().getItemFillState(getName()))
		m_orders.front().fillItem(*this, os);
}


bool Task::moveTask()
{
	if (m_orders.empty())
		return false;

	if (m_pNextTask && m_orders.front().getItemFillState(getName()))
	{
		*m_pNextTask += std::move(m_orders.front());
		m_orders.pop_front();
	}

	return true;
}

void Task::setNextTask(Task& task)
{
	m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& co)
{
	if (m_orders.front().getOrderFillState() && !m_orders.empty())
	{
		co = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	return false;
}

void Task::validate(std::ostream& os) const
{
	os << getName() << " --> " << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE") << std::endl;
}

Task& Task::operator+=(CustomerOrder&& co)
{
	m_orders.push_back(std::move(co));
	return *this;
}
