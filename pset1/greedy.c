/**
 *  greedy.c
 * 
 *  Tushar Watts
 *  tushtiit@gmail.com
 *  
 *  Prompts the user for the amount of change owed and then spits out the
 *  minimum number of coins with which said change can be made
 *  
 *  Demonstrates the use of Greedy Algorithm and math.round fucntion
 */
 
 #include<stdio.h>
 #include<cs50.h>
 #include<math.h>
 
 //define symbolic constants
 //only coins available
 #define QUARTERS 25
 #define DIMES 10
 #define NICKLES 5
 #define PENNIES 1
 
 int main(void)
 {
     //variable to hold the amount of change owed
     float change;
     
     //prompt the user for an amount of change in dollars
     printf("How  much change is owed ? \n");
     change=GetFloat();
     
     //error checking 
     //if the user fails to prompt a non negative value, then reprompt
     while(change<0)
     {
         printf("Invalid input. Please try again:");
         change=GetFloat();
     }
     
     //convert the change in dollars to cents 
     //use round function to avoid errors
     //1 dollar=100 cents
     int cents = (int) round(change * 100);
     
     //variable to hold the number of coins with which said change can be made
     //initialize it to 0
     int coins=0;
     
     //Apply greedy algo to spit out the min no of required coins
     while(cents!=0)
     {
         if(cents>=QUARTERS)
         {
             cents=cents-QUARTERS;
             coins++;
         }
         
         else if(cents>=DIMES)
         {
             cents=cents-DIMES;
             coins++;
         }
         
         else if(cents>=NICKLES)
         {
             cents=cents-NICKLES;
             coins++;
         }
         
         else
         {
             cents=cents-PENNIES;
             coins++;
         }
     }
     
     //print the no of coins required
     printf("%i\n",coins);
     
 }
 
 