#pragma once
#include "Task.h"
enum taskType { Yolo, SPPE, Quit };

void decode(Task task);
void scheduler();
