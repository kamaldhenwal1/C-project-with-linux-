#include <stdio.h>
#define PI 3.14
int main(){
	int radius,vol;
	printf("Enter the value of radius");
	scanf("%d",&radius);
	vol=4/3*(PI*radius*radius*radius);
	printf("The volume of the sphere is : %d",vol);
	return 0;
}
