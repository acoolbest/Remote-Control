#include "system.h"

uint8_t TaskLists;

void ScheduleInit(){
	TaskLists = 0;
}

void TaskPost(uint8_t TaskID){
	TaskLists |= 1 << TaskID;
}

uint8_t RunNextTask(){
	if(TaskLists == 0)
		return 0;

	if(TaskLists & 0x01) {
		TaskLists &= ~0x01;
		Task1();
	} else if(TaskLists & 0x02) {
		TaskLists &= ~0x02;
		Task2();
	} else if(TaskLists & 0x04) {
		TaskLists &= ~0x04;
		Task3();
	} else if(TaskLists & 0x08) {
		TaskLists &= ~0x08;
		Task4();
	} else if(TaskLists & 0x10) {
		TaskLists &= ~0x10;
		Task5();
	} else if(TaskLists & 0x20) {
		TaskLists &= ~0x20;
		Task6();
	} else if(TaskLists & 0x40) {
		TaskLists &= ~0x40;
		Task7();
	} else if(TaskLists & 0x80) {
		TaskLists &= ~0x80;
		Task8();
	}
	return 1;
}