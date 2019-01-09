// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.12.2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& str, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customer_order):
	m_cntCustomerOrder(0)
{
	Utilities util;
	size_t next_pos = 0;
	auto more = true;
	auto tf_first_task = true;
	std::string record;
	std::string next;
	std::ifstream file(str);

	while (!file.eof())
	{
		std::getline(file, record);
		auto task = util.extractToken(record, next_pos, more);

		if (more)
			next = util.extractToken(record, next_pos, more);

		for (size_t i = 0; i < tasks.size(); ++i)
		{
			if (tasks[i]->getName() == task)
			{
				if (tf_first_task)
				{
					m_firstTask = i;
					tf_first_task = !tf_first_task;
				}

				if (next.empty())
				{
					m_lastTask = i;
				}
				else
				{
					for (size_t j = 0; j < tasks.size(); ++j)
						if (tasks[j]->getName() == next)
						{
							tasks[i]->setNextTask(*tasks[j]);
							break;
						}
				}

				break;
			}
		}

		next_pos = 0;
		more = true;
		task.clear();
		next.clear();
	}

	for (auto& co : customer_order)
		ToBeFilled.push_back(std::move(co));

	customer_order.erase(customer_order.begin(), customer_order.end());
	AssemblyLine = tasks;
}

bool LineManager::run(std::ostream& os)
{
	auto tf = true;

	if (!ToBeFilled.empty())
	{
		*AssemblyLine[m_firstTask] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto& i : AssemblyLine)
		i->runProcess(os);

	CustomerOrder buffer;

	if (AssemblyLine[m_lastTask]->getCompleted(buffer))
		Completed.push_back(std::move(buffer));

	for (auto& i : AssemblyLine)
		if (i->moveTask())
			tf = false;

	return tf;
}

void LineManager::displayCompleted(std::ostream& os) const
{
	if (!Completed.empty())
		for (const auto& i : Completed)
			i.display(os);
}

void LineManager::validateTasks() const
{
	if (!AssemblyLine.empty())
		for (auto i : AssemblyLine)
			i->validate(std::cout);
}
