#include <stdio.h>
#include<string.h>
#include "contact.h"
int load_contacts(AddressBook *addressbook)     // Loads contacts from file at program startup
{
    FILE *fp;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        fprintf(stderr,"File does not exist\n");        //Prints error message if no file is found 
        return 0;
    }
    fscanf(fp,"#%d",&addressbook->contact_count);       //Reads number of contacts available in the file
    if(addressbook->contact_count>0)
    {
        int i=0;
        while(i<=addressbook->contact_count)
        {
            fscanf(fp,"\n%[^,],%[^,],%[^\n]",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
            i++;        //Loading contacts the file to the program
        }
    }
    else
    printf(ORANGE"\nThere are no contacts in the addressbook\n"RESET);
    fclose(fp);
    return 0;
}