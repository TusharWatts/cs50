/**
 *  mario.c
 * 
 *  Tushar Watts
 *  tushtiit@gmail.com
 *  
 *  Prompts the user for the height of half pyramid
 *  and then generate the half pyramid  
 *  
 *  Demonstrates the use of for and while loops
 */
 

#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //prompt the user to enter height
    printf("Enter the height :");
    int height_pyr=GetInt();
    
    //error checking , a non negative integer no greater than 23
    while(height_pyr<0 || height_pyr>23)
    {
        printf("Invalid input. Please try again:");
        height_pyr=GetInt();
    }
    
    //variable to loop the height of pyramid
    int i;

    for(i=0; i<height_pyr ;i++)
    {
        //variable to loop the columns of the pyramid
        int k;
        
        //loop to print the whitespace characters
        //there are a total of (h+1) columns , so the remaining columns are
        //reserved for space characters
         for(k=0;k < ( (height_pyr + 1) - (i+2) ) ; k++)
        {
            printf(" ");
        }

        //loop to print the hash character
        //last (i+2) columns are reserved for hash characters
        for(k=0;k <(i+2)  ; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

