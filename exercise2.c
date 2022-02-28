#include<stdio.h>
#include<math.h>

#define EXIT -1
#define PHONE_NUM 9


int oddOrEven(long int num);
int sumSize(long int phoneNumber);
int checkIfVaried(long int num);
int countOddAndEven(long int phoneNumber);
int printDavidStar(int numForStar);
int allMersenneNumbers(int num1,int num2);
int SquareEquation(double a, double b, double c);

int main()
{
	char firstLetter, secondLetter; //printing the name//
	int option=0; //switch case//
	int numForStar; //option 2 star of david//
	int num1, num2; //option c Mersenne//
	int again ;
	
	//print the user initials in capital//
	printf("Hello, what is the first letter of your name?\n");
	do {
		again = 0;
		scanf(" %c", &firstLetter); //Valid input :assum that there will be insert two letters, if they are small make them capital//
		scanf(" %c", &secondLetter);
		if ((firstLetter < 65 || firstLetter > 122) || (90 < firstLetter && firstLetter < 97) || (secondLetter < 65 || secondLetter > 122) || (90 < secondLetter && secondLetter < 97)) {
			again = 1;
		}
		} while (again==1);
	
	if (97 <= firstLetter && firstLetter <= 122) {  //Change small letters to capital//
		firstLetter -= 32;
	}
	if (97 <= secondLetter && secondLetter <= 122) {
		secondLetter -= 32;
	}
	printf("Hello %C. %C, welcome to our menu!\n", firstLetter, secondLetter);

	//The program will run until option = -1//
	
	while (option != EXIT){
		int resA1;
		int resA2;
		int resA3;
		int resA4;
		int resB;
		long int phoneNumber;
		int resC;
		int resD;
		double a=0, b=0, c=0;
		long int check=0,checkcount;
		

	printf("Choose 1 for phone, 2 for David, 3 for Mersenne, 4 for equation, -1 for exit\n");
	do { //keep reading numbers from the user until valid input//
		scanf("%d", &option); //valid input: 1,2,3,4,-1//
	}
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != EXIT);
		switch (option) {
		
			//case 1 reciving a 9 digits phone number from the user and classify the number by 4 parameters//
		case 1: 
			
			printf("Enter phone number (9 digits)\n");
			do {
				scanf("%ld", &phoneNumber);
				check = phoneNumber;
				checkcount = 0;
				while (check > 0)
				{
					check /= 10;
					checkcount++;
				}
			} while (checkcount != 9);

			resA1 = oddOrEven(phoneNumber);
			resA2 = sumSize(phoneNumber);
			resA3 = countOddAndEven(phoneNumber);
			resA4 = checkIfVaried(phoneNumber);

			if (resA1 == 1 && resA2 > 40 && resA3 == 1 && resA4 == 1) {
				printf("The number is amazing!\n");
			}
			break;
		
			//case 2 reciving a number from the user and print 3 stars of davif in 3 different sizes//
		case 2:
			printf("Enter size number:\n");
			do {
				scanf("%d", &numForStar);
			} while ((numForStar < 7 || numForStar>77) || ((numForStar % 2) == 0));
			resB = printDavidStar(numForStar);
			break;

			//case 3 reciving 2 numbers from the user and print the Mersenne numbers that are in between them//
		case 3:
			printf("Enter two numbers:\n");
			do {
				scanf("%d%d", &num1, &num2);
			} while (num1 <= 0 || num2 <= 0);

			resC = allMersenneNumbers(num1, num2);
			break;

			//case 4 reciving 3 numbers from the user and print the square equation and solve it//
		case 4:
			printf("Enter three numbers:\n");
			scanf("%lf%lf%lf", &a, &b, &c);
			resD = SquareEquation(a, b, c);
			break;
		}
		
	}
	printf("Thank you, %c. %c, have a nice day!",firstLetter,secondLetter);
	return 0;
}


/*************************************************************************
Function name: oddOrEven
Input: 9 digits number
Output: 1 for even 0 for odd
The function operation: check if the number is even or odd
************************************************************************/

int oddOrEven(long int num) {
	if (num % 2 == 0) {
		printf("The number is even\n");
		return 1;
	}
	else {
		printf("The number is odd\n");
		return 0;
	}

}

/*************************************************************************
Function name: sumSize
Input: 9 digits number
Output: the digit sum
The function operation: check the sum of the number , print if it is small/medium/large and return the sum
************************************************************************/
int sumSize(long int phoneNumber) {
	long int temp;
	int digitSum=0, i;
	temp = phoneNumber;
	for (i = 0;i < PHONE_NUM;i++) {
		digitSum += temp % 10;
		temp /= 10;
	}
	if (digitSum > 40) {
		printf("The number is large\n");
	}
	else if (30 <= digitSum && digitSum <= 40) {
		printf("The number is medium\n");
	}
	else {
		printf("The number is small\n");
	}
	return digitSum;
}

/*************************************************************************
Function name: countOddAndEven
Input: 9 digits number
Output: 1 for special 0 for not special
The function operation: check if the number of odds or even numbers are high or equal to 7
************************************************************************/

int countOddAndEven(long int num) {
	long int temp;
	int i, even = 0, odd = 0;
	temp = num;
	for (i = 0;i < PHONE_NUM;i++) {
		if (temp % 2 == 0) {
			even++;
			temp = temp /= 10;
		}
		else {
			odd++;
			temp = temp /= 10;
		}
	}
	if (even >= 7 || odd >= 7) {
		printf("The number is special\n");
		return 1;
	}
	else {
		printf("The number is not special\n");
		return 0;
	}
}

/*************************************************************************
Function name:checkIfVaried
Input: 9 digits phone number
Output: 1 for varied 0 for not varied
The function operation: check if at least one number is appears more then twice
************************************************************************/

 int checkIfVaried(long int num){
	int i,answer = 0, count;
	long int temp;
	for (i = 0;i <= PHONE_NUM;i++) { 
		count = 0;
		temp = num;
		while (temp > 0) {
			if (temp % 10 == i) {
				count++;
				temp /= 10;
			}
			else
			{
				temp /= 10;
			}

		}
		if (count > 2) {
			answer = 1;
		}

	}
	if (answer == 1) {
		printf("The number is not varied\n");
		return 0;
	}
	else {
		printf("The number is varied\n");
		return 1;
	}
}

 /*************************************************************************
Function name:printDavidStar
Input: reciving a number
Output: return 0 after printing
The function operation: recive an odd number(n) and print 3 stars of david with the size of 9 lines and the length of (2M-1)
when M IS equal to 3 different sizes(M=n+2 , M=n and M=n-2) 
************************************************************************/

 int printDavidStar(int num) {
	 int k, i, M, j;
	 M = num - 2;
	 for (k = 0;k < 3;k++) {

		 for (i = 1;i <= 9;i++) {
			 for (j = 1;j <= (M * 2 - 1);j++) {
				 switch (i) {
				 case 1:
					 if (j == M) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 case 2:
					 if (j == M - 1 || j == M + 1) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 case 3:
					 printf("O");
					 break;
				 case 4:
					 if (j == 2 || j == (2 * M - 2)) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }

					 break;
				 case 5:
					 if (j == 3 || j == (2 * M - 3)) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 case 6:
					 if (j == 2 || j == (2 * M - 2)) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 case 7:
					 printf("O");
					 break;
				 case 8:
					 if (j == M - 1 || j == M + 1) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 case 9:
					 if (j == M) {
						 printf("O");
					 }
					 else {
						 printf("-");

					 }
					 break;
				 }
			 }
			 printf("\n");
		 }
		 M += 2;
		 num += 2;
		 printf("\n");
	 }
	 return 0;
 }

 /*************************************************************************
Function name:allMersenneNumbers
Input: 2 numbers
Output: return 0 
The function operation: reciving two numbers, and  checking if between the small one to the bigger one there are numbers of Mersenne
(2^n-1). in the end printing all the numbers in the range or print none if there are no numbers in the range
************************************************************************/

 int allMersenneNumbers(int num1,int num2) {
	 int temp,answer=0,none=0,exsist=0,i=0;
	 if (num2 < num1) {
		 temp = num2;
		 num2 = num1;
		 num1 = temp;
	 }

	 while ((pow(2, i) - 1) <= (pow(2, num2))) {
		 answer = (int)pow(2, i) - 1;
		 if (answer >= num1 && answer <= num2) {
			 if (answer!=0){
				 printf("%d\n", answer);
			 }
			 exsist = 1;

		 }
		 else {
			 none = 1;
		 }
		 i++;
	 }
	 if (none == 1 && exsist == 0) {
		 printf("None\n");
	 }
	 
	 return 0;
 }

 /*************************************************************************
Function name:SquareEquation
Input: 3 numbers
Output: return 0
The function operation: reciving three numbers, printing the square equation solving it and printing the solution
************************************************************************/

 int SquareEquation(double a, double b, double c) {
	 double a1, b1, delta=0, x1, x2 = 0, sqrtAnswer, positiveDelta, temp;

	 if (a != 0) {
		 if ((a < 0 || a > 0) && a != 1 && a != -1) {
			 printf("%.0lfx^2 ", a);
		 }
		 else if (a == 1) {
			 printf("x^2 ");
		 }
		 else if (a == -1) {
			 printf("-x^2 ");
		 }
	 }
	 if (b != 0) {
		 if (b > 0) {
			 if (a != 0) {
				 printf("+ ");
			 }
			 if (b == 1) {
				 printf("x ");
			 }
			 else {
				 printf("%.0lfx ", b);
			 }

		 }
		 else if (b < 0) {
			 if (a != 0) {
				 printf("- ");
			 }
			 if (b == -1 && a != 0) {
				 printf("x ");
			 }
			 else if (b == -1 && a == 0) {
				 printf("-x ");
			 }
			 else if (a == 0 && b != -1) {
				 printf("%.0lfx ", b);
			 }
			 else {
				 printf("%.0lfx ", (-1) * b);
			 }
		 }
	 }
	 if (c != 0) {
		 if (a != 0) {
			 if (c > 0) {
				 printf("+ ");

				 printf("%.0lf = 0\n", c);
			 }
			 else if (c < 0) {
				 printf("- ");
				 printf("%.0lf = 0\n", (-1) * c);
			 }
		 }
	 }
	 else if (c == 0 && (a != 0 || b != 0)) {
		 printf("= 0\n");
	 }

	 if (a == 0 && b == 0 && c != 0) {
		 printf("%.0lf = 0\n", c);
		 printf("No solution!\n");
	 }
	 else if (a == 0 && b == 0 && c == 0) {
		 printf("0 = 0\n");
		 printf("Infinite solutions!\n");
	 }
	 else if (a == 0 && b != 0) {
		 x1 = (-1)*(c / b);
		 if (c > 0) {
			 printf("+ %.0lf = 0\n", c);
		 }
		 if (c < 0) {
			 printf("- %.0lf = 0\n", (-1) * c);
		 }
		 if (x1!=0) {
			 printf("x1 = %.3lf\n", x1);
		 }
		 else {
			 printf("x1 = 0.000\n");
		 }
		 }
	 else {
		 delta = ((pow(b, 2)) - (4 * a * c));

		 if (delta >= 0) {
			 sqrtAnswer = sqrtl(delta);
			 x1 = ((-b) + (sqrtAnswer)) / (2 * a);
			 x2 = ((-b) - (sqrtAnswer)) / (2 * a);
			 if (x2 > x1) {
				 temp = x2;
				 x2 = x1;
				 x1 = temp;
			 }
			 if (x1 == x2) {
				 if (x1 == 0.000) {
					 printf("x1 = 0.000\n");
				 }
				 else {
					 printf("x1 = %.3lf\n", x1);
				 }
			 }
			 else {
				 if (x1 == 0.000) {
					 printf("x1 = 0.000\n");
					 printf("x2 = %.3lf\n", x2);

				 }
				 else if (x2 == 0.000) {
					 printf("x1 = %.3lf\n", x1);
					 printf("x2 = 0.000\n");
				 }
				 else {
					 printf("x1 = %.3lf\nx2 = %.3lf\n", x1, x2);
				 }
			 }
		 }
		 else {
			 positiveDelta = (-1) * delta;
			 sqrtAnswer = sqrtl(positiveDelta);
			 a1 = (-b) / (2 * a);
			 b1 = sqrtAnswer / (2 * a);
			 if (b1 > 0) {
				 if (a1 != 0) {
					 if (b1 != 1) {
						 printf("x1 = %.3lf + %.3lfi\nx2 = %.3lf - %.3lfi\n", a1, b1, a1, b1);
					 }
					 if (b1 == 1) {
						 printf("x1 = %.3lf + i\nx2 = %.3lf - i\n", a1, a1);
					 }
				 }
				 else {
					 if (b1 != 1) {
						 printf("x1 = %.3lfi\nx2 = %.3lfi\n", b1, (-1) * b1);
					 }
					 if (b1 == 1) {
						 printf("x1 = i\nx2 = -i\n");
					 }
				 }
			 }
			 if (b1 < 0) {
				 if (a1 != 0) {
					 if (b1 != -1) {
						 printf("x1 = %.3lf + %.3lfi\nx2 = %.3lf - %.3lfi\n", a1, (-1) * b1, a1, (-1) * b1);
					 }
					 if (b1 == -1) {
						 printf("x1 = %.3lf + i\nx2 = %.3lf - i\n", a1, a1);
					 }
				 }
				 else {
					 if (b1 != -1) {
						 printf("x1 = %.3lfi\nx2 = %.3lfi\n", (-1) * b1, b1);
					 }
					 if (b1 == -1) {
						 printf("x1 = i\nx2 = -i\n");
					 }
				 }
			 }
		 }
	 }
		 return 0;
	 }
	
