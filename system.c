#include "system.h"

uint8_t mystrlen(uint8_t *strbuff) {
	uint8_t i = 0;
	while(strbuff[i] != 0) {
		i++;
		if(i>64) return 0;
	}
	return i;
}

void GeneralTask() {

}
