#include <thread>
#include <vector>
#include "TSQ.h"
#include "Scheduler.h"

#include <iostream>
#include <chrono>


TSQ<Task> q;

int main()
{
	//init
	int num_thread = 10;
	std::vector<std::thread> threads;
	for (int i = 0; i < num_thread; i++)
	{
		threads.push_back(std::thread(scheduler));
	}

	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

	//execute
	Task yoloTask = { Yolo, &num_thread };
	for (int i = 0; i < 1000; i++)
	{
		q.push(yoloTask);
	}
	Task quitTask = { Quit, nullptr };
	for (int i = 0; i < num_thread; i++)
	{
		q.push(quitTask);
	}

	for (int i = 0; i < num_thread; i++)
	{
		threads[i].join();
	}

	std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds total_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << total_time.count() << std::endl;

	return 0;
}
