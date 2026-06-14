#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include "contact.h"

int search_contacts(AddressBook *addressbook)
{   int choice,count=0;char temp[20],*ptr;
    start3:
   if(scanf("%d",&choice)!=1)
   {    
        printf(RED"Invalid choice\n"BBLUE"Enter valid choice:"RESET);
        while(getchar()!='\n');
        goto start3;    
   }
    if(choice==1)
    {   printf(BCYAN"\nSearching contact...\n"RESET);
        printf("Enter the name you want to search:");
        search_name(addressbook);
    }    
    else if(choice==2)
    {   
        printf(BCYAN"\nSearching contact...\n"RESET);
        printf("Enter the Mobile numbmer you want to search:");
        search_number(addressbook);
    }
    else if(choice==3)
    {   
        printf(BCYAN"\nSearching contact...\n"RESET);
        printf("Enter the mail id you want to search:");
        search_mail(addressbook);
    }
    else if(choice==4)
    return 0;
    else
    {
        printf(RED"Invalid choice\n"RESET);
        printf(BBLUE"Enter Valid choice:"RESET);
        goto start3;
    }
    
}

int search_name(AddressBook *addressbook)       // Searches contact by name and displays matching records
{   
    int index,tem,arr[20],printcount=0;
    int count=0,i=0;
    char temp[20],*ptr;
    ALPHA:
    scanf(" %[^\n]",temp);
    getchar();
    while(temp[i]!='\0')
    {
        if(!isalpha(temp[i]))
        {
            printf(RED"Please enter alphabets only\n"RESET);
            printf("Enter the Name you want to search:");
            goto ALPHA;
        }
        i++;
    }
    for(i=0;i<addressbook->contact_count;i++)
    {
        ptr=strcasestr(addressbook->contact_details[i].Name,temp);
        if(ptr)             //checks whether user entered name is present in the address book or not
        {  
            printcount++;
            if(printcount==1)
            {   
                printf(GREEN"\nContact(s) found\n"RESET);
                printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
                printf("----------------------------------------------------------------------------------------------------------\n");
            }
            printf("%d\t%-32s \t\t %s \t\t %s\n",count+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
            tem=i;
            arr[count]=i;
            count++;
        }
    }
    if(count==1)
    return tem;
    if(count>1)
    {
        printf(BBLUE"\nEnter the S.No you searched for:"RESET);
        SNo:
        scanf("%d",&index);
        if(index<=count)
        {
        printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%-32s \t\t %s \t\t %s\n",index,addressbook->contact_details[arr[index-1]].Name,addressbook->contact_details[arr[index-1]].Mobile_number,addressbook->contact_details[arr[index-1]].Mail_ID);
        }
        else
        {

            printf(ORANGE"Please choose the S.No in the above given table:\n"RESET);
            goto  SNo;
        }
        return arr[index-1];
    }
    if(!count)
    {
    printf(RED"No conatact found\n"RESET);
    return -1;
    }
}
int search_number(AddressBook *addressbook)     // Searches contact by mobile number
{   int index,i=0,tem,arr[20],printcount=0;
    int count=0;char temp[20],*ptr;
    NUMBER:
    scanf("%s",temp);
    while(temp[i]!='\0')
    {
        if(!isdigit(temp[i]))
        {
            printf(RED"Please enter digits only\n"RESET);
            printf("Enter the Mobile number you want to search:");
            goto NUMBER;
        }
        i++;
    }
    for(i=0;i<addressbook->contact_count;i++)
    {
        ptr=strcasestr(addressbook->contact_details[i].Mobile_number,temp);
        if(ptr)         //checks whether user entered mobile number is present in the address book or not
        {   printcount++;
            if(printcount==1)
            {   printf(GREEN"\nContact(s) found\n"RESET);
                printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
                printf("----------------------------------------------------------------------------------------------------------\n");
            }
            printf("%d\t%-32s \t\t %s \t\t %s\n",count+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
            tem=i;
            arr[count]=i;
            count++;
        }
    }
    if(count==1)        // Returns directly when a single matching contact is found
    return tem;
    if(count>1)         // Allows user selection when multiple matching contacts exist
    {
        printf(BBLUE"\nEnter the S.No you searched for:"RESET);
        SNo:
        scanf("%d",&index);
        if(index<=count)
        {
        printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%-32s \t\t %s \t\t %s\n",index,addressbook->contact_details[arr[index-1]].Name,addressbook->contact_details[arr[index-1]].Mobile_number,addressbook->contact_details[arr[index-1]].Mail_ID);
        }
        else
        {
            printf(ORANGE"Please choose the S.No in the above given table:\n"RESET);
            goto  SNo;
        }
        return arr[index-1];
    }
    if(!count)
    {
    printf(RED"No conatact found\n"RESET);
    return -1;          // Returns -1 if no matching contact is found
    }
    
}

int search_mail(AddressBook *addressbook)       // Searches contact by email ID
{   int index,tem,arr[20],printcount=0;
    int count=0;char temp[20],*ptr,i=0;
    scanf("%s",temp);
    for(i=0;i<addressbook->contact_count;i++)
    {
        ptr=strcasestr(addressbook->contact_details[i].Mail_ID,temp);
        if(ptr)         //checks whether user entered mail id is present in the address book or not
        {   
            printcount++;
            if(printcount==1)
            {   printf(GREEN"\nContact(s) found\n"RESET);
                printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
                printf("----------------------------------------------------------------------------------------------------------\n");
            }
            printf("%d\t%-32s \t\t %s \t\t %s\n",count+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
            tem=i;
            arr[count]=i;
            count++;
        }
    }
    if(count==1)        // Returns directly when a single matching contact is found
    return tem;
    if(count>1)        // Allows user selection when multiple matching contacts exist
    {
        printf(BBLUE"\nEnter the S.No you searched for"RESET);
        SNo:
        scanf("%d",&index);
        if(index<=count)
        {
        printf(BCYAN"S.No  \tName\t\t\t\t\t\tMobile Number\t\t Gmail id\n"RESET"----------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%-32s \t\t %s \t\t %s\n",index,addressbook->contact_details[arr[index-1]].Name,addressbook->contact_details[arr[index-1]].Mobile_number,addressbook->contact_details[arr[index-1]].Mail_ID);
        }
        else
        {
            printf(ORANGE"Please choose the S.No in the above given table:\n"RESET);
            goto  SNo;
        }
        return arr[index-1];
    }
    if(!count)
    {
    printf(RED"No conatact found\n"RESET);
    return -1;          // Returns -1 if no matching contact is found
    }
}