#include <stdio.h>
#include<string.h>
#include "contact.h"

void list_contacts(AddressBook *addressbook)        // Display all contacts stored in address book
{
    if(addressbook->contact_count>0)               // Check whether contacts are available
    {
        printf(YELLOW"\nTotal contacts saved : %d"RESET"\n",addressbook->contact_count); // Display contact count

        printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<addressbook->contact_count;i++) // Traverse all contacts
        {
            printf("%d\t%-32s \t\t %s \t\t %s\n----------------------------------------------------------------------------------------------------------\n",
                   i+1,
                   addressbook->contact_details[i].Name,
                   addressbook->contact_details[i].Mobile_number,
                   addressbook->contact_details[i].Mail_ID); // Display contact details
        }
    }
    else
    {
        printf(ORANGE"\nNo conatacts found. Address book is empty\n"RESET); // Address book is empty
    }
}