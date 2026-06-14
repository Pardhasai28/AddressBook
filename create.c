#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include "contact.h"

int create_contact(AddressBook *addressbook)        // Create and store a new contact
{
    char temp[35];

    while(1)
    {
        addressbook->contact_count++;               // Increment contact count

        printf(BCYAN"\nCreating contact..."RESET);

        create_name(addressbook);                   // Read contact name
        create_number(addressbook);                 // Read mobile number
        create_mail(addressbook);                   // Read email ID

        printf(GREEN"Contact added successfully"RESET"\n");

        start2:
        printf(BMAGENTA"\nDo you want to create another contact?"RESET"\n 1 for yes \n 2 for no\n");
        printf(BBLUE"Enter choice:"RESET);

        int choice;

        if(scanf("%d",&choice)!=1)                  // Validate user choice
        {
            while(getchar()!='\n');                // Clear input buffer
        }

        if(choice==1)
            continue;                              // Add another contact
        else if(choice==2)
            return 0;                              // Return to main menu
        else
        {
            printf(RED"Invalid choice\n"RESET);
            goto start2;                           // Re-enter choice
        }

        return 0;
    }
}

int create_name(AddressBook *addressbook)
{
    char temp[32];

    for(int i=addressbook->contact_count-1;i<addressbook->contact_count;i++)
    {
        int count=0;

        start11:
        printf("\nEnter the name:");
        scanf(" %[^\n]",temp);

        if(alph(temp))                             // Validate name characters
        {
            count++;
        }
        else
        {
            goto start11;                          // Re-enter name
        }

        if(count==1)
            strcpy(addressbook->contact_details[i].Name,temp);  // Store name
    }

    return 0;
}

int create_number(AddressBook *addressbook)
{
    char temp[21];

    for(int i=addressbook->contact_count-1;i<addressbook->contact_count;i++)
    {
        int count=0;

        start12:
        printf("Enter the phone number:");
        scanf("%s",temp);

        if(check_number(temp))                     // Validate mobile number
        {
            count++;
        }
        else
        {
            goto start12;                          // Re-enter number
        }

        if(addressbook->contact_count>0)
        {
            for(int j=0;j<addressbook->contact_count;j++) // Check duplicate numbers
            {
                if(!strcmp(temp,addressbook->contact_details[j].Mobile_number))
                {
                    count--;
                    printf(RED"Entered number is already existed\nPlease enter the valid new number: "RESET);
                    goto start12;                  // Re-enter unique number
                }
            }
        }

        if(count==1)
            strcpy(addressbook->contact_details[i].Mobile_number,temp); // Store number
    }

    return 0;
}

int create_mail(AddressBook *addressbook)
{
    char temp[32];

    for(int i=addressbook->contact_count-1;i<addressbook->contact_count;i++)
    {
        int count=0;

        start13:
        printf("Enter the gmail id:");
        scanf("\n%[^\n]",temp);

        if(check_mail(temp))                       // Validate email ID
        {
            count++;
        }
        else
        {
            goto start13;                          // Re-enter email
        }

        if(addressbook->contact_count>0)
        {
            for(int j=0;j<addressbook->contact_count;j++) // Check duplicate emails
            {
                if(!strcmp(temp,addressbook->contact_details[j].Mail_ID))
                {
                    count--;
                    printf(RED"Entered mail id is already existed\nPlease enter the valid mail id: \n"RESET);
                    goto start13;                  // Re-enter unique email
                }
            }
        }

        if(count==1)
            strcpy(addressbook->contact_details[i].Mail_ID,temp); // Store email
    }

    return 0;
}