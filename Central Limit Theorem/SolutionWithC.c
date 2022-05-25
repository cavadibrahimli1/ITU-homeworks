// Name and Surname - Javad Ibrahimli
// ITU ID number - 040210932

//In the first part of the code I added headers which I need to use for my project.
#include<stdio.h>          //for performing input and output.
#include<stdlib.h>      //for performing general functions.
#include<time.h>     // for for manipulating date and time.

int rollingdice()  // Function in order to roll the dices
{ 
	return rand() % 6 + 1;   //gives value between 1-6.
}

int max_finder(int arr[], int n)   // function which find the maximum value of the given array.
{ 
	int max = arr[0];   
	for(int i = 0; i < n; i++)
	{   
		if(arr[i] > max) // if the latter element of the array is greater than the current maximum one, this code defines it the new maximum.
		{
			max = arr[i];
		}
	}

	return max;   //at the end of the execution it gives the value of max. 
}

int main()
{
	srand(time(NULL));   // I used srand in  order to getting new graph results in every execution of the program.

	int randomised_variable; //defined a integer variable
	int freq[6] = {0};  
	int etalon_value = 280;  // I set the  etalon scale value to 200. I did it due to the graph plotted in homework pdf given by Professor of the class.

	for(int i = 0; i < 10000; i++)
	{
		randomised_variable = rollingdice();  
		freq[randomised_variable-1] += 1;  
	}

	int max = max_finder(freq, 6);   // I assigned _finder function result to a integer named max



	for(int i = max / etalon_value; i >= 1; i--)  
	{
		for(int j = 0; j < 6; j++)
		{
			if(freq[j] / etalon_value >= i) //here I set a algorithm where, computer decides whether it must plot an asteriks or not.
			{
				printf("*  ");    //my etalon scale value for this 1 dice rolling algorithm is 200. Below lines  
			}
			else
			{
				printf("   ");   //empty 
			}

		}
		printf("\n");
	}


	printf("1  2  3  4  5  6\n\n");    // here I designed the bottom side of the graph of 1 dice roller.

	int sec_etalon_value = 100;   // I set the etalon scale value for 2 dice rolling
	int frequency[11] = {0};
	int first_try, second_try, sum;   //new defined variables
	for(int i = 0; i < 10000; i++){
		first_try = rollingdice();
		second_try = rollingdice();      
		sum = first_try + second_try;   //here I find the sum of the results of first roll and second roll.

		frequency[sum-2] += 1;
	}

	max = max_finder(frequency, 11);  // I assigned _finder function result to a integer named max
	for(int i = max / sec_etalon_value; i >= 1; i--)   //here I set a algorithm where, computer decides whether it must plot an asteriks or not.
	{
		for(int j = 0; j < 11; j++){
			if(frequency[j] / sec_etalon_value >= i)    //here I set a algorithm where, computer decides whether it must plot an asteriks or not.
			{
				printf("*  ");  
			}
			else{
				printf("   ");
			}

		}
		printf("\n");
	}

	printf("2  3  4  5  6  7  8  9 10 11 12\n");  // here I designed the bottom side of the graph of 2 dice roller.




	return 0; //exit code of the program
}
//thanks for watching.

