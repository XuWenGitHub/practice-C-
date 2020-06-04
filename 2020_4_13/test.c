#include"test.h"

int myStrlen(char *str){
	
	if (*str == '\0'){
		return 0;
	}
	return 1 + myStrlen(str + 1);
}