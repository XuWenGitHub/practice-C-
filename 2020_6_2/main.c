#include"test.h"


int main(){
	/*char str[6] = { 'A', 'A', 'B', 'C', 'D', '\0' };
	char compStr[6] = { 'A', 'B', 'C', 'D', 'A','\0' };
	char compStr2[6] = { 'B', 'C', 'D', 'A', 'A', '\0' };
	char compStr3[6] = { 'A', 'A', 'B', 'C', 'D', '\0' };
	char compStr4[6] = { 'C', 'D', 'B', 'A', 'A', '\0' };
	int result = stringRotation(str, compStr4);
	printf("%d", result);*/

	char str2[] = { 'a', 'b', 'c', 'd','e','\0' };
	printf("%d\n", strlen(str2));
	printf("%s\n", str2);
	stringRotation2(str2, strlen(str2), 4);
	printf("%s\n", str2);
	system("pause");
}