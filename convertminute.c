#include<stdio.h>
int main(){
	int min,hour,no_of_minute;
	    printf("Enter the value of the minute : ");
	scanf("%d",&min);
	printf("Enter the value of the hour : ");
	scanf("%d",&hour);

	no_of_minute=(hour*60)+min;
	printf("The total no. of minutes = %d",no_of_minute);
}
