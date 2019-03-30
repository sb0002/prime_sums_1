#include "include.h"

int main(void)
{
	char str1[120], str2[120];				//arrays for holding raw user input
	int start, nums, temp1, temp2;				//starting number and number of numbers to test, and some temps.
	while(1)
	{
		printf("Enter an even starting number: ");
		fgets(str1, 20, stdin);
		if((sscanf(str1, "%d", &start) == 1) && iseven(start)) break;	//exit the input-demand loop if the user entered one even integer
		printf("That's not a valid number.\n");
	}
	while(1)
	{
		printf("Enter how many numbers to test: ");
		fgets(str2, 20, stdin);
		if((sscanf(str2, "%d", &nums) == 1) && nums>=1) break;		//exit the second input-demand loop if the user entered one even integer
		printf("The number entered is invalid.\n");
	}
	
	int ctr=0;                                              //counter to keep track of array index
        int primelist[79000];                                  //array to store all primes from 2 to 1000198
        for(int i=3;i<1000200;i++)
        {
                if(isprime(i))                                  //if the number is prime, add to the array
                {
                        primelist[ctr]=i;
                        ctr++;
                }
        }
	
	//printf("Starting with %i and finding the next %i numbers as the sum of two primes.\n", start, nums);

	for(int x=start;x<start+(nums*2);x+=2)			//start looping through the numbers within the range specified by the user
	{
		for(int i=x,j=0;i>0;i--,j++)			//for each number, start looking for sums of primes
		{
			if(isprime(x-primelist[j]))		//if the number minus a prime was prime, the difference must be prime too
			{
				int out1=x-primelist[j];
				printf("%i = %2i + %i\n", x, primelist[j], out1);	//output the even number, equal to the sum of two primes
				break;
			}
		}
	}
	return 0;
}
