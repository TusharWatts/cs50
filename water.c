/**
 *  water.c
 * 
 *  Tushar Watts
 *  tushtiit@gmail.com
 *  
 *  Prompts the user for the length of his/her shower in minutes and 
 *  prints the equivalent number of bottles of water  
 *  
 *  Demonstrates the use of integer and floating point values, multiplication
 */
 
 #include<stdio.h>
 #include<cs50.h>
 
 int main(void)
 {
     //prompts the user to enter the length of shower
     printf("Enter the length of shower in minutes:"); 
     
     //the length of shower is stored in the variable len_show
     int len_show=GetInt();
     
     //error checking to make sure that the user enters a positive integer
     while(len_show<0)
     {
         printf("Invalid input, please enter a positive integer:");
         len_show=GetInt();
         
     }
     
     //calculate the equivalent number of bottles of water required
     int num_bottles = (len_show * 1.5 *128) / 16 ; 
     
     //print the output
     printf("Equivalent Number of bottles required : %i\n", num_bottles);
     
     
 }