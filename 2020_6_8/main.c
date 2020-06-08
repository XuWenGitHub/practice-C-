#include"test.h"

int main(){
	char str1[] = {"helloa    " };
	char str2[] = { "hellob" };
	//printf("%s\n", str1);
	//printf("%s\n", str2);
	////strcat(str1, str2);
	//char*p = mystrcat(str1, str2);
	//printf("%s\n", str1);
	//printf("%s\n", p);

	//printf("%d\n", myStrcmp(str1, str2));
	
	//printf("%s\n", myStrcpy(str1, str2));

	printf("%d\n", myStrlen1(str1));
	printf("%d\n", myStrlen2(str1));
	printf("%d\n", myStrlen3(str1));
	system("pause");
}