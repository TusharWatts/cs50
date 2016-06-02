/**
 *  caesar.c
 * 
 *  Tushar Watts
 *  tushtiit@gmail.com
 *  
 *  Prompts the user for an integer key and a plain text. The program will then
 *  encipher the text
 *  
 *  Demonstrates the concepts of cryptography, ASCII Math , use of 
 *  command line arguments, and ctype library functions.
 */
 
 #include<stdio.h>
 #include<cs50.h>
 #include<stdlib.h>
 #include<ctype.h>
 #include<string.h>
 
 int main(int argc, string argv[])
 {
     //validate the command line argument
     if(argc!=2)
     {
         printf("You didn't submit a valid encryption key. Please quit or re-run the program.\n");
         return 1;
     }
     
     //to make sure our key is correct, we need to convert it to an int
     //k variable is the key
     int k=atoi(argv[1]);
     
     //Read user input
     //p is plaintext (un-encrypted message)
     string p=GetString();
     //length of the input string
     int n=strlen(p);
     
     //Access the individual elements of the stirng
     for(int i=0;i<n;i++)
     {
         //check if the character entered is an alphabet or not
         if(isalpha(p[i]))
         {
             //if yes then check if we need to wrap around the alphabet or not
             if((p[i]+k)<26)
             {
                 //if not then simply shift each character by k
                 printf("%c",p[i]+k);
             }
         
            //if we need to wrap around the element 
            else 
            {
                //make sure that lowercase letters, though rotated, must 
                //remain lowercase letters
                if(islower(p[i]))
                {
                    //to wrap around subtract 97
                    p[i]=p[i]-97;
                     
                     printf("%c",( (p[i]+k) %26)+97);
                }
                
                //make sure that uppercase letters, though rotated, must 
                //remain uppercase letters
                 else if(isupper(p[i]))
                {
                    //to wrap around subtract 65
                    p[i]=p[i]-65;
                   
                    printf("%c", (  (p[i]+k)%26)+65);
                }
            }
         }
         
         //if the character entered is not an alphabet, no need processing
         else
         {
             printf("%c",p[i]);
         }
     }
     printf("\n");
     
 }