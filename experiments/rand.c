/* Program to demonstrate time taken by function fun() */
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>

// A function that terminates when enter key is pressed 
/*
void fun() 
{ 
double	lol;
	lol = drand48();
	lol = lol * 0.05;
    printf("fun() starts \n"); 
    printf("Press enter to stop fun \n"); 
    while(1) 
    { 
        if (getchar()) 
            break; 
    } 
    printf("fun() ends \n"); 
} 
  */
// The main program calls fun() and measures time taken by fun() 

double	fun()
{
	return (0);
}
int main() 
{ 
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    fun(); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("fun() took %f seconds to execute \n", time_taken); 

    return 0; 
} 

