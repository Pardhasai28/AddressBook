# AddressBook
# Address Book Management System

## Overview

The Address Book Management System is a console-based application developed in C for storing and managing contact information. It allows users to add, search, edit, delete, display, save, and load contacts efficiently through a menu-driven interface.

## Features

### 1. Add Contact

* Add a new contact with:

  * Name
  * Mobile Number
  * Email ID
* Input validation is performed before storing the contact.
* Duplicate mobile numbers and email IDs are not allowed.

### 2. Search Contact

Contacts can be searched using:

* Name
* Mobile Number
* Email ID

Partial matching is supported, and if multiple contacts match the search criteria, the user can select the desired contact from the displayed list.

### 3. Edit Contact

Existing contact details can be modified:

* Name
* Mobile Number
* Email ID
* All details simultaneously

### 4. Delete Contact

Contacts can be deleted by searching through:

* Name
* Mobile Number
* Email ID

A confirmation is requested before deleting the selected contact.

### 5. Display Contacts

Displays all saved contacts in a formatted tabular structure including:

* Serial Number
* Name
* Mobile Number
* Email ID

### 6. Save Contacts

Stores all contact information into a file for future use.

### 7. Load Contacts

Previously saved contacts are automatically loaded when the application starts.

## Input Validations

### Name Validation

* Only alphabets and single spaces are allowed.
* Consecutive spaces are not allowed.
* Name cannot start with a space.

### Mobile Number Validation

* Must contain exactly 10 digits.
* Only numeric characters are allowed.
* First digit must be between 6 and 9.
* Duplicate mobile numbers are not allowed.

### Email Validation

* Only lowercase letters, digits, '@', and '.' are allowed.
* Must contain exactly one '@'.
* Consecutive dots are not allowed.
* Must end with '.com' or '.in'.
* Domain name should contain only alphabets.
* Duplicate email IDs are not allowed.

## Technologies Used

* Programming Language: C
* Standard Libraries:

  * stdio.h
  * string.h
  * ctype.h

## Data Structure Used

The project uses structures to store contact information:

* Name
* Mobile Number
* Email ID

All contacts are maintained inside an Address Book structure that tracks the total number of contacts.

## Project Workflow

1. Load contacts from file.
2. Display main menu.
3. Perform selected operation:

   * Add
   * Search
   * Edit
   * Delete
   * Display
   * Save
4. Save contacts before exiting.
5. Exit application.

## Learning Outcomes

* Structure handling in C
* File handling
* String manipulation
* Input validation
* Menu-driven programming
* Modular programming using multiple source files
* Searching and data management techniques

## Author

Pardha Sai
