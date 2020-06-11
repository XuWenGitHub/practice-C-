#include"test.h"


int main(){
	const char* str1 = "abcd134";
	const char* str2 = "bc";
	printf("%s\n", myStrstr(str1, str2));

	char str3[] = "cdef1234asd";
	myMemcpy(str3, str1,4);
	printf("%s\n", str3);
	system("pause");
	return 0;
}

