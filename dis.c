#include <stdio.h>
int main(){
	int price, dis, fpri;
	printf("Enter your price for discount eligibility check\n: ");
	scanf("%d",&price);
	if(price>10000){
		printf("You are eligible for discount = 23%\n");
		dis = price*0.23;
		fpri = price-dis;
		printf("Your Final price = %d",fpri);
	}else if(10000< price >70000){
		printf("You are eligible for discount = 19%\n");
		dis = price*0.19;
		fpri = price-dis;
		printf("Your Final price = %d",fpri);
	}else if(7000< price >5000){
		printf("You are eligible for discount = 13%\n");
		dis = price*0.13;
		fpri = price-dis;
		printf("Your Final price = %d",fpri);
	}else if(5000< price >2000){
		printf("You are eligible for discount = 5%\n");
		dis = price*0.5;
		fpri=price-dis;
		printf("You Final price = %d",fpri);
	}else 
		printf("Please shop above 2000 price for discount!");
	return 0;
}
