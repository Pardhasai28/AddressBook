//Documentation

/*Name             : V.Pardha Sai
Date             : 22/01/2026
Description      : The following functions are implemented in the Address Book project to manage contact information efficiently.

create_contact() :->Adds a new contact to the address book by collecting name, mobile number, and email ID from the user.
                  ->Validates all inputs before storing the contact in memory.
search_contacts():->Searches for contacts based on name, mobile number, or email ID entered by the user.
                  ->Displays matching records and allows selection when multiple contacts are found.
edit_contact()   :->Allows the user to modify existing contact details such as name, mobile number, or email ID.
                  ->Ensures updated values are validated before saving the changes.
delete_contact() :->Removes a selected contact from the address book based on user input.
                  ->Reorganizes remaining records to maintain proper data order.
list_contacts()  : ->Displays all saved contacts in a formatted tabular view.
                   ->Helps the user easily review stored contact information.
save_contacts()  :->Writes all current contact data from memory into a file for permanent storage.
                  ->Ensures that contacts are preserved for future program executions.
save and exit    :->Displays all saved contacts in a formatted tabular view.
                  ->Helps the user easily review stored contact information.
load_contacts()  :->Loads previously saved contact details from the file into memory when the program starts.
                  ->Allows the user to continue working with existing contacts without data loss.*/
#include <stdio.h>
#include "contact.h"
#include <stdio_ext.h>

int main()
{
    int option;                          // Stores user's menu choice
    AddressBook addressbook;             // Address book structure
    addressbook.contact_count = 0;       // Initialize contact count

    load_contacts(&addressbook);         // Load contacts from file

    while (1)
    {
        printf(BMAGENTA"\nAddress book menu\n"RESET);
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Save and Exit\n");
        printf(BBLUE"Enter the option : "RESET);

    Invalid:
        if (scanf("%d", &option) != 1)   // Validate menu input
        {
            printf(RED"Invalid option "RESET);
            printf(GREEN"Select between (1 to 7)"RESET);
            printf(BBLUE"\nEnter valid option:"RESET);

            while (getchar() != '\n');   // Clear input buffer
            goto Invalid;
        }

        switch (option)
        {
            case 1:
            {
                create_contact(&addressbook);   // Add new contact
                break;
            }

            case 2:
            {
                if (addressbook.contact_count > 0)
                {
                    printf(BMAGENTA"\nSearch Contact menu : "RESET"\n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"BBLUE"Enter the option : "RESET);
                    search_contacts(&addressbook);   // Search contact
                }
                else
                {
                    printf(ORANGE"\nNo contacts found. Address book is empty.\n"RESET);
                }
                break;
            }

            case 3:
            {
                if (addressbook.contact_count > 0)
                {
                    edit_contact(&addressbook);   // Edit existing contact
                }
                else
                {
                    printf(ORANGE"\nNo contacts found. Address book is empty.\n"RESET);
                }
                break;
            }

            case 4:
            {
                if (addressbook.contact_count > 0)
                {
                    delete_contact(&addressbook);   // Delete a contact
                }
                else
                {
                    printf(ORANGE"\nNo contacts found. Address book is empty.\n"RESET);
                }
                break;
            }

            case 5:
            {
                if (addressbook.contact_count > 0)
                {
                    printf("List Contacts:\n");   // Display contacts heading
                }

                list_contacts(&addressbook);      // Show all contacts
                break;
            }

            case 6:
            {
                if (addressbook.contact_count > 0)
                {
                    printf(BCYAN"\nSaving contacts...\n"RESET);
                    save_contacts(&addressbook);  // Save contacts to file
                }
                else
                {
                    printf(ORANGE"\nNo contacts to save. Please add contacts before saving....\n"RESET);
                }
                break;
            }

            case 7:
            {
                if (addressbook.contact_count > 0)
                {
                    printf(BCYAN"INFO : Save and Exit...\n"RESET);
                    save_contacts(&addressbook);  // Save before exit
                    printf(GREEN"Exiting...\n\n"RESET);
                }
                else
                {
                    printf(ORANGE"\nNo contacts to save. Exiting....\n\n"RESET);
                }

                return 0;                         // Terminate program
            }

            default:
            {
                printf(RED"Invalid option "RESET);
                printf(GREEN"Select between (1 to 7)"RESET);
                break;
            }
        }
    }

    return 0;   // Program end
}