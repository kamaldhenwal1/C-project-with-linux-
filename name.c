#include<stdio.h> 
int main(){
	char forename[50], surname[50];
	int birthyear;

	printf("Enter your forename : ");
	scanf("%s", forename);
	printf("Enter your surname : ");
	scanf("%s", surname);
	printf("Enter your birth year : ");
	scanf("%d", &birthyear);

	printf("Forename : %s\n",forename);
	printf("Surename : %s\n",surname);
	printf("Birthyear : %d\n",birthyear);
	return 0;
}
