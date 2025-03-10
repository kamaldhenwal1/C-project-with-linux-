#include <stdio.h>
int main(){
	int len,bre,area;
	printf("Insert the length and breath of rectangle");
	scanf("%d %d", &len, &bre);
	area=len*bre;
	printf("The area of the rectangle is : %d",area);
	return 0;
}
