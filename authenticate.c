#include<stdio.h>
#include<string.h>
int main(){
	int give = 12353 ,store;
	char given[70] = "Whiteevil", stored[70];

	printf("Enter the username : ");
	scanf("%s", stored);

	printf("Enter the password : ");
	scanf("%d",&store);

	if(strcmp(given,stored)){
		if(give==store){
			printf("You are authorised to the account!");
		}
	
	else{
		printf("You are not authorised");
	}
	}
	return 0;
}
