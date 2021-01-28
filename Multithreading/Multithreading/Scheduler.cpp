#include "TSQ.h"
#include "Scheduler.h"
#include <iostream>
extern TSQ<Task> q;

void decode(Task task)
{
	switch (task.id)
	{
	case Yolo:
	{
		std::cout << "Yolo\n";
		YoloInput input = { 1234 };	//example input
		yoloTask((void*)&input);	//cast input to void pointer
		break;
	}
	case SPPE:
		std::cout << "SPPE\n";
		break;
	case Quit:
		throw "Quit\n";
	default:
		std::cout << "Default\n";
	}
}

void scheduler()
{
	while (true)
	{
		if (!q.empty())
		{
			Task task = q.extract();
			try
			{
				decode(task);
			}
			catch (const char* err)
			{
				std::cout << err;
				return;
			}

		}
	}
}
