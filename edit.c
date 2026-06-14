#include <stdio.h>
#include<string.h>
#include "contact.h"

int edit_contact(AddressBook *addressbook)      // Edit existing contact details
{
    int choice,count=0;
    char temp[20],*ptr,edit[20],flag;

    while(1)
    {
        printf(BMAGENTA"\nSearch by: "RESET"\n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"BBLUE"Enter the option : "RESET);

        Invalid:
        if(scanf("%d",&choice)!=1)              // Validate search option
        {
            printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
            while(getchar()!='\n');            // Clear input buffer
            goto Invalid;
        }

        if(choice==1)
        {
            printf("Enter the name you want to search:");
            flag=search_name(addressbook);      // Search contact by name
        }
        else if(choice==2)
        {
            printf("Enter the Mobile number you want to search:");
            flag=search_number(addressbook);    // Search contact by mobile number
        }
        else if(choice==3)
        {
            printf("Enter the Mail id you want to search:");
            flag==search_mail(addressbook);     // Search contact by mail ID
        }
        else if(choice==4)
            return 0;                           // Exit edit menu
        else
        {
            printf(RED"Invalid choice\n"RESET);
            printf(BBLUE"Enter valid choice:"RESET);
            goto Invalid;
        }

        if(flag+1)                              // Proceed if contact found
        {
            printf(BMAGENTA"Edit Contact menu : "RESET"\n1.Name \n2.Mobile number\n3.Mail ID\n4.All details\n5.Exit\n"BBLUE"Enter the option : "RESET);

            start4:
            if(scanf("%d",&choice)!=1)          // Validate edit option
            {
                printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
                while(getchar()!='\n');
                goto start4;
            }

            if(choice==1)
            {
                edit_name(addressbook,flag);    // Edit contact name
            }
            else if(choice==2)
            {
                edit_number(addressbook,flag);  // Edit contact number
            }
            else if(choice==3)
            {
                edit_mail(addressbook,flag);    // Edit contact mail ID
            }
            else if(choice==4)
            {
                edit_name(addressbook,flag);    // Edit all details
                edit_number(addressbook,flag);
                edit_mail(addressbook,flag);
            }
            else if(choice==5)
                return 0;                       // Exit edit operation
            else
            {
                printf(RED"Invalid choice\n"RESET);
                printf(BBLUE"Enter Valid choice: "RESET);
                goto start4;
            }

            start41:
            printf(BMAGENTA"\nDo you want to edit any other contact \n"BBLUE"Enter \n"RESET"1 for yes \n2 for no:");

            int editchoice;

            if(scanf("%d",&editchoice)!=1)      // Validate user response
            {
                printf(RED"Invalid choice\n"RESET);
                while(getchar()!='\n');
                goto start41;
            }

            if(editchoice==1)
            {
                continue;                       // Edit another contact
            }
            else if(editchoice==2)
                return 0;                       // Return to main menu
            else
            {
                printf(RED"Invalid choice"RESET);
                goto start41;
            }
        }
    }

    return 0;
}

void edit_name(AddressBook *addressbook,int res)     // Update contact name
{
    char edit[20];

    printf("Enter new name:");

    start42:
    scanf(" %[^\n]",edit);

    if(alph(edit))                                  // Validate name
    {
        strcpy(addressbook->contact_details[res].Name,edit); // Store updated name
        printf(GREEN"Name is Edited\n"RESET);
    }
    else
    {
        printf(BBLUE"Enter valid name:"RESET);
        goto start42;
    }
}

void edit_number(AddressBook *addressbook,int res)   // Update contact number
{
    char edit[20];

    printf("Enter new mobile number:");

    start43:
    scanf(" %s",edit);

    if(check_number(edit))                          // Validate mobile number
    {
        if(addressbook->contact_count>0)
        {
            for(int j=0;j<addressbook->contact_count;j++) // Check duplicate numbers
            {
                if(!strcmp(edit,addressbook->contact_details[j].Mobile_number))
                {
                    printf(ORANGE"Entered number is already existed\n"BBLUE"Please enter the valid another number: \n"RESET);
                    goto start43;
                }
            }
        }

        strcpy(addressbook->contact_details[res].Mobile_number,edit); // Store updated number
        printf(GREEN"Mobile number is Edited\n"RESET);
    }
    else
    {
        printf(BBLUE"Enter valid mobile number:"RESET);
        goto start43;
    }
}

void edit_mail(AddressBook *addressbook,int res)     // Update contact mail ID
{
    char edit[20];

    printf("Enter new mail id:");

    start44:
    scanf(" %[^\n]",edit);

    if(check_mail(edit))                            // Validate mail ID
    {
        if(addressbook->contact_count>0)
        {
            for(int j=0;j<addressbook->contact_count;j++) // Check duplicate mail IDs
            {
                if(!strcmp(edit,addressbook->contact_details[j].Mail_ID))
                {
                    printf(ORANGE"Entered mail id is already existed\n"BBLUE"Please enter the valid another mail id: \n"RESET);
                    goto start44;
                }
            }
        }

        strcpy(addressbook->contact_details[res].Mail_ID,edit); // Store updated mail ID
        printf(GREEN"Mail id is Edited\n"RESET);
    }
    else
    {
        printf(BBLUE"Enter valid Mail id:"RESET);
        goto start44;
    }
}