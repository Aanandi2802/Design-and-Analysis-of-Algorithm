#include <stdio.h>
int main () {
	
	int Coins, coin_list[100], useit[100], i, amnt;
 
	printf("\nEnter Number Of Different Coins You Have : ");
	scanf("%d", &Coins);
 
	printf("Enter the value of Coins in descending order: ");
 
	for(i=0; i< Coins; i++) 
	{
		scanf("%d", &coin_list[i]);
		// useit[i] = 0;
	}
 
	printf("Enter the amount : ");
	scanf("%d", &amnt);
  int a=amnt;
	for(i=0; i < Coins; i++)
	{
		useit[i] = amnt / coin_list[i];
		amnt %= coin_list[i];
	}
 
	printf("Change for %d is : ",a);
	for(i=0; i < Coins; i++) 
	{
		printf(" %d*%d +", coin_list[i], useit[i]);
	}
	printf("\n\n");
}
