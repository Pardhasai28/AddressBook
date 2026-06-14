#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include "contact.h"

int alph(char *check)       // Validate name format
{
    int i=0;

    while(check[i])         // Check for valid characters
    {
        if((!isalpha(check[i])) && !(check[i]==' '))
        {
            printf(RED"Name should contain only alphabets,spaces."BBLUE"\nTRY AGAIN!\n\n"RESET);
            return 0;
        }
        i++;
    }

    i=0;
    while(check[i])         // Check for consecutive spaces
    {
        if(check[i]==' ' && check[i+1]==' ')
        {
            printf(RED"Multiple spaces are not allowed in the name.\n"BBLUE"TRY AGAIN!\n\n"RESET);
            return 0;
        }
        i++;
    }

    if(check[0]==' ')       // Check leading space
    {
        printf(RED"Name should not start with space.\n"BBLUE"TRY AGAIN!\n\n"RESET);
        return 0;
    }

    return 1;
}

int check_number(char *check)       // Validate mobile number
{
    int i=0;

    while(check[i])         // Verify digits only
    {
        if(!isdigit(check[i]))
        {
            printf(RED"Invalid! Mobile number should contain only digits\n"BBLUE"TRY AGAIN!\n\n"RESET);
            return 0;
        }
        i++;
    }

    if(strlen(check)!=10)   // Verify length
    {
        printf(RED"Invalid Mobile number! Mobile number should have 10 digits\n"BBLUE"TRY AGAIN!\n\n"RESET);
        return 0;
    }

    if(!(check[0]>=6+'0' && check[0]<=9+'0')) // Verify starting digit
    {
        printf(RED"The first number should be in between 6 and 9.\n"BBLUE"TRY AGAIN!\n\n"RESET);
        return 0;
    }

    return 1;
}

int check_mail(char *check)     // Validate email ID
{
    int i=0;
    int charcount=0;

    while(check[i])
    {
        if(check[i]=='@')
        {
            charcount++;    // Count '@' characters
        }

        if((!islower(check[i])) && (!isdigit(check[i])) &&
           !(check[i]=='@') && !(check[i]=='.'))
        {
            printf(RED"Invalid Mail ID! \nMail id should contain only lowercase letters,digits,@ and '.'\n"BBLUE"TRY AGAIN!\n\n"RESET);
            return 0;
        }
        i++;
    }

    if(!(charcount==1))     // Ensure exactly one '@'
    {
        printf(RED"Invalid Mail ID! Mail id should contain @ for only 1 time\n"BBLUE"TRY AGAIN!\n\n"RESET);
        return 0;
    }

    i=0;
    char *p,*q,*p1;
    int add=strlen(check);

    p=strstr(check,".com"); // Search for .com
    p1=strstr(check,".in"); // Search for .in
    q=strstr(check,"@");    // Locate '@'

    for(i=0;i<strlen(check);i++)
    {
        if(check[i]=='.' && check[i+1]=='.') // Check consecutive dots
        {
            printf(RED"Consecutive dots are not allowed\n"RESET);
            return 0;
        }
    }

    if(p1==NULL)            // Validate .com domain
    {
        if(!(p==&(check[add-4])))
        {
            printf(RED"Invalid Mail ID! Please enter a valid mail id ending with '.com' or '.in'\n"BBLUE"TRY AGAIN!\n\n "RESET);
            return 0;
        }

        if(p-q<2)           // Validate domain length
        {
            printf(RED"Invalid Mail ID! Mail id should have valid domain name\n"BBLUE"TRY AGAIN!\n\n"RESET);
            return 0;
        }

        char *k;
        k=q+1;

        while(k!=p)         // Validate domain characters
        {
            if(!isalpha(*k))
            {
                printf(RED"Invalid Mail ID! The domain should contain only alphabets\n"BBLUE"TRY AGAIN!\n\n"RESET);
                return 0;
            }
            k++;
        }
    }

    if(p==NULL)             // Validate .in domain
    {
        if(!(p1==&(check[add-3])))
        {
            printf(RED"Invalid Mail ID! Please enter a valid mail id ending with '.com' or '.in'\n"BBLUE"TRY AGAIN!\n\n "RESET);
            return 0;
        }

        if(p1-q<2)          // Validate domain length
        {
            printf(RED"Invalid Mail ID! Mail id should have valid domain name\n"BBLUE"TRY AGAIN!\n\n"RESET);
            return 0;
        }

        char *k;
        k=q+1;

        while(k!=p1)        // Validate domain characters
        {
            if(!isalpha(*k))
            {
                printf(RED"Invalid Mail ID! The domain should contain only alphabets\n"BBLUE"TRY AGAIN!\n\n"RESET);
                return 0;
            }
            k++;
        }
    }

    return 1;               // Email validation successful
}