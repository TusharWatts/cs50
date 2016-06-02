/**
 *  intitials.c
 * 
 *  Tushar Watts
 *  tushtiit@gmail.com
 *  
 *  Prompts the user for for their name and then outputs their initials 
 *  in uppercase 
 *  
 *  Demonstrates the use of strings , typecasting and ASCII table
 */
 
#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main(void)
{
    //prompts the user for their full name and store in variable s
    string s=GetString();
    
    //temporary variables to access the individual string elements
    int i,x;

    //capitalize the 1st letter of the 1st name
    //if the 1st letter is small, then capitalize it ELSE keep it intact
    if(s[0] >= 'a' && s[0]<='z')
    {
        printf("%c",(int)s[0]-32);
    }
    else
    {
        printf("%c",s[0]);
    }


    //Find out the 1st letter of the middle and/or last name
    for(i=0;i<strlen(s);i++)
    {
        //check for space character
        if((int)s[i]==32)
        {
            //store the space character index in temporary variable x
            //in other words, look for space between names
            x=i;

            //capitalize the next element to the space character
            //in other words, cpaitalize the 1st letter of 
            //middle and/or last name
            if(s[x+1] >= 'a' && s[x+1]<='z')
            {
                printf("%c",(int)s[x+1]-32);
            }
            //if its already capitalize then keep it intact
            else
            {
                printf("%c",s[x+1]);
            }
        }

    }
    
    printf("\n");


}








