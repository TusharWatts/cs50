

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>
 #include<cs50.h>

 int main(int argc,string argv[])
 {

    //validate the command line argument
     if(argc!=2)
     {
         printf("You didn't submit a valid encryption key. Please quit or re-run the program.\n");
         return 1;
     }
     
     //to make sure our key is correct, we need to convert it to an int
     //k variable is the key
     string k = argv[1];
     
     //Read user input
     //p is plaintext (un-encrypted message)
     string p=GetString();
     //length of the input string
     int n=strlen(p);
     int l=strlen(k);
     
     //Access the individual elements of the stirng
     for(int i=0;i<n;i++)
     {
         //check if the character entered is an alphabet or not
         if(isalpha(p[i]))
         {
              for(int j=0;j<n;j++)
            {
                //if yes then check if we need to wrap around the alphabet or not
                if((p[i]+k[j]-97)<123)
                {
                
                    //if not then simply shift each character by k
                    printf("%c",p[i]+k[j%l]-97);
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
                     
                         printf("%c",( (p[i]+k[j%l]-97) %26)+97);
                    }
                    
                    //make sure that uppercase letters, though rotated, must 
                    //remain uppercase letters
                     else if(isupper(p[i]))
                    {
                        //to wrap around subtract 65
                        p[i]=p[i]-65;
                       
                        printf("%c", (  (p[i]+k[j%l]-97)%26)+65);
                    }
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

