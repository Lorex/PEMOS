#pragma once

// task.h#pragma once
#define MAX_TASK 10

// Task Interval
int allocatedTaskID = 0;
String taskNameList[MAX_TASK];
long taskIntervalList[MAX_TASK];
long taskLastExecuteTimeList[MAX_TASK];

// Time variables
unsigned long currentTime = 0;

// Get Task ID by Name
int getTaskIDbyName(char * name) {
	for (int i = 0; i < allocatedTaskID; i++) {
		if (taskNameList[i] == name)
			return i;
	}
	return -1;
}

// Create task and add into task list
void createTask(char * taskName, long taskInterval) {
	taskNameList[allocatedTaskID] = taskName;
	taskIntervalList[allocatedTaskID] = taskInterval;
	taskLastExecuteTimeList[allocatedTaskID] = 0;
	allocatedTaskID += 1;
}

// Monitor and run task
void runTask(char * taskName) {
	currentTime = millis();
	if (currentTime - taskLastExecuteTimeList[getTaskIDbyName(taskName)] >= taskIntervalList[getTaskIDbyName(taskName)]) {
		taskLastExecuteTimeList[getTaskIDbyName(taskName)] = currentTime;
		((void(*)())taskName)();
	}
}