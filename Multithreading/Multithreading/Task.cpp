#include "Task.h"

#include <iostream>

void yoloTask(void* data)
{
	YoloInput input = *(YoloInput*)data;
	std::cout << "This is Yolo Task" << std::endl;
	std::cout << "Data is" << input.data1 << std::endl;
	return;
}