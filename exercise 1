#include<stdio.h>

#define INTERNAL 0
#define UNIVERSAL 972
#define SIZE 4

int main()
{
	// "%%% hello \/\/orld %%% "%s" - pre exercises // 

	char m = '%';
	char g = '"';
	char fs='/';
	char bs = 92;
	char s = 's';
	printf("%c%c%c%c hello %c%c%c%corld %c%c%c %c%c%c%c\n", g, m, m, m, bs, fs, bs, fs, m, m, m, g, m, s, g);
	printf("\% \\ \n");
	 
	/*
	Part A
	recive 2 numbers and return the sum,sub,mul,div and mod
	*/

	int num1, num2,sum,sub,mul,div,mod;

	printf("Enter 2 numbers\n");
	scanf("%d%d", &num1, &num2);
	
	sum = num1 + num2;
	sub = num1 - num2;
	mul = num1 * num2;
	div = num1 / num2;
	mod = num1 % num2;

	printf("The sum of %d and %d is: %d\n", num1, num2, sum);
	printf("The sub of %d and %d is: %d\n", num1, num2, sub);
	printf("The mul of %d and %d is: %d\n", num1, num2, mul);
	printf("The div of %d and %d is: %d\n", num1, num2, div);
	printf("The mod of %d and %d is: %d\n", num1, num2, mod);

	/*
	Part B
	recive 4 numbers and transport to char code
	*/
	int ch1, ch2, ch3, ch4;

	printf("Enter four numbers as password \n");
	scanf("%d%d%d%d", &ch1, &ch2, &ch3, &ch4);

	printf("Your password is: %c%c%c%c\n", ch1, ch2, ch3, ch4);

	
	/*
	Part C 
	recive a number and flip the order of the numbers
	*/

	int temp = 0, numc, newNum=0,i;

	printf("Enter number with 4 digits\n");
	scanf("%d", &numc);

	temp = numc;
	for (i = 0;i < SIZE;i++) {
		newNum *= 10;
		newNum += temp % 10;
		temp /= 10;
	}

	printf("%d\n", newNum);
	
	/*
	Part D
	recive a phone number without the 0 and return internal and international number
	*/
	int phoneNumber;
	
	printf("Enter phone number\n");
	scanf("%d", &phoneNumber);

	printf("Internal number: %d-%d\n", INTERNAL, phoneNumber);
	printf("Universal number: +%d-%d\n", UNIVERSAL, phoneNumber);

	return 0;
}
