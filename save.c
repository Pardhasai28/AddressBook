#include <stdio.h>
#include<string.h>
#include "contact.h"
int save_contacts(AddressBook *addressbook)     // Displays all saved contacts in formatted output
{
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        fprintf(stderr,"File does not exist\n");
        return 0;
    }
    fprintf(fp,"#%d\n",addressbook->contact_count);      //Prints number of contacts available in the file
    int i=0;
    while(i<addressbook->contact_count)
    {
        fprintf(fp,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
        i++;        //Saving into the file
    }
    printf(GREEN"\nContacts saved\n"RESET);
    fclose(fp);
    return 0;
}