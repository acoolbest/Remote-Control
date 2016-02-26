#ifndef __Schedule_H__
#define __Schedule_H__

#define Event_TimerExpired_TaskID	0
#define TaskID_2	1
#define TaskID_3	2
#define TaskID_4	3
#define TaskID_5	4
#define TaskID_6	5
#define TaskID_7	6
#define TaskID_8	7

#define Task1()		Timer0_Expire_Task()
#define Task2()		GeneralTask()
#define Task3()		GeneralTask()
#define Task4()		GeneralTask()
#define Task5()		GeneralTask()
#define Task6()		GeneralTask()
#define Task7()		GeneralTask()
#define Task8()		GeneralTask()


extern void ScheduleInit();
extern void TaskPost(uint8_t TaskID);
extern uint8_t RunNextTask(); 

#endif