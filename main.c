#include "system.h"

void main() {
	HAL_Init_Hardware();
	APP_Init();
	HPL_ISR_GLOBAL_SET();
	while(1) {
		if(RunNextTask() == 0) {
			//SLEEP();
		}
	}
}