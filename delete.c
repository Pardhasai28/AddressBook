#include <stdio.h>
#include<string.h>
#include "contact.h"

int delete_contact(AddressBook *addressbook)        // Display delete menu and delete selected contact
{
    int choice,count=0;
    char temp[20],*ptr;

    while(1)
    {
        if(addressbook->contact_count>0)           // Check whether contacts exist
        {
            printf(BMAGENTA"\nDelete Contact menu : \n"RESET"1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"BBLUE"Enter the option : "RESET);

            start5:
            if(scanf("%d",&choice)!=1)             // Validate menu choice
            {
                printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
                while(getchar()!='\n');           // Clear input buffer
                goto start5;
            }

            if(choice==1)
            {
                delete_name(addressbook);          // Delete using name
            }
            else if(choice==2)
            {
                delete_number(addressbook);        // Delete using mobile number
            }
            else if(choice==3)
            {
                delete_mail(addressbook);          // Delete using mail ID
            }
            else if(choice==4)
            {
                return 0;                          // Exit delete menu
            }
            else
            {
                printf(RED"\nInvalid choice\n"RESET);
                printf(BBLUE"\nEnter valid choice:"RESET);
                goto start5;                       // Re-enter choice
            }
        }
        else
        {
            printf(ORANGE"All contacts are deleted\n"RESET);
            return 0;                              // Return if address book is empty
        }
    }

    return 0;
}

int delete_name(AddressBook *addressbook)          // Delete contact by name
{
    printf("Enter the name you want to delete:");

    int res=search_name(addressbook);              // Search contact by name

    if(res+1)
    {
        printf(ORANGE"\nDo you want to delete this contact\n"BBLUE"Enter "RESET"\n1 for yes \n2 for no\n");

        int option;

        start51:
        if(scanf("%d",&option)!=1)                 // Validate confirmation choice
        {
            printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
            while(getchar()!='\n');
            getchar();
        }

        if(option==1)
        {
            for(int j=res;j<addressbook->contact_count;j++) // Shift contacts left
            {
                addressbook->contact_details[j]=addressbook->contact_details[j+1];
            }

            addressbook->contact_count--;          // Reduce contact count

            printf(BCYAN"Deleting contact...\n"RESET);
            printf(GREEN"\nContact delelted\n"RESET);
        }
        else if(option==2)
        {
            return 0;                              // Cancel deletion
        }
        else
        {
            printf(RED"\nInvalid Choice\n"BBLUE"Please enter valid choice\n"RESET);
            goto start51;
        }
    }
}

int delete_number(AddressBook *addressbook)        // Delete contact by mobile number
{
    printf("Enter the contact number  you want to delete:");

    int res=search_number(addressbook);            // Search contact by number

    if(res+1)
    {
        printf(ORANGE"\nDo you want to delete this contact\n"BBLUE"Enter "RESET"\n1 for yes \n2 for no\n");

        int option;

        start52:
        if(scanf("%d",&option)!=1)                 // Validate confirmation choice
        {
            printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
            while(getchar()!='\n');
            getchar();
        }

        if(option==1)
        {
            for(int j=res;j<addressbook->contact_count;j++) // Shift contacts left
            {
                addressbook->contact_details[j]=addressbook->contact_details[j+1];
            }

            addressbook->contact_count--;          // Reduce contact count

            printf(BCYAN"Deleting contact...\n"RESET);
            printf(GREEN"\nContact delelted\n"RESET);
        }
        else if(option==2)
        {
            return 0;                              // Cancel deletion
        }
        else
        {
            printf(RED"\nInvalid Choice"BBLUE"\nPlease enter valid choice\n"RESET);
            goto start52;
        }
    }
}

int delete_mail(AddressBook *addressbook)          // Delete contact by mail ID
{
    printf("Enter the mail id to delete that contact: ");

    int res=search_mail(addressbook);              // Search contact by mail ID

    if(res+1)
    {
        printf(ORANGE"\nDo you want to delete this contact\n"BBLUE"Enter "RESET"\n1 for yes \n2 for no\n");

        int option;

        start53:
        if(scanf("%d",&option)!=1)                 // Validate confirmation choice
        {
            printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
            while(getchar()!='\n');
            getchar();
        }

        if(option==1)
        {
            for(int j=res;j<addressbook->contact_count;j++) // Shift contacts left
            {
                addressbook->contact_details[j]=addressbook->contact_details[j+1];
            }

            addressbook->contact_count--;          // Reduce contact count

            printf(BCYAN"Deleting contact...\n"RESET);
            printf(GREEN"\nContact delelted\n"RESET);
        }
        else if(option==2)
        {
            return 0;                              // Cancel deletion
        }
        else
        {
            printf(RED"\nInvalid Choice\n"BBLUE"Please enter valid choice\n"RESET);
            goto start53;
        }
    }
}