#ifndef CONTACT_H
#define CONTACT_H
#define RED       "\033[1;31m"
#define RESET     "\033[0m"
#define GREEN     "\033[1;32m"
#define BBLUE     "\033[1;94m"
#define BCYAN     "\033[1;96m"
#define BMAGENTA  "\033[1;95m"
#define ORANGE    "\033[38;5;208m"
#define YELLOW "\033[1;33m"

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int alph(char *);
int check_number(char *);
int check_mail(char *);
int search_name(AddressBook *);
int search_number(AddressBook *);
int search_mail(AddressBook *);
int create_name(AddressBook *);
int create_number(AddressBook *);
int create_mail(AddressBook *);
void edit_name(AddressBook *,int);
void edit_number(AddressBook *,int);
void edit_mail(AddressBook *,int);
int delete_name(AddressBook *);
int delete_number(AddressBook *);
int delete_mail(AddressBook *);
int load_contacts(AddressBook *);

#endif // CONTACT_H
       // CONTACT_H