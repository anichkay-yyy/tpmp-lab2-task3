/* anichkay */

#ifndef CONTACT_H
#define CONTACT_H

/*
 * CONTACT module interface
 * Structure and operations for phonebook (BLOCKNOTE) management
 */

#define MAX_NAME  50
#define MAX_PHONE 20
#define BLOCKNOTE_SIZE 10

/* Date of birth */
typedef struct {
        int     year;
        int     month;
        int     day;
} Date;

/* Contact record */
typedef struct {
        char    name[MAX_NAME];   /* surname and initials */
        char    tele[MAX_PHONE];  /* phone number */
        Date    date;             /* birth date */
} CONTACT;

/* Input contacts from keyboard */
void input_contacts(CONTACT *contacts,
                    int *count,
                    int max_size);

/* Sort contacts by birth date ascending */
void sort_by_date(CONTACT *contacts,
                  int count);

/* Find and print contact by phone number */
void find_by_phone(CONTACT *contacts,
                   int count,
                   const char *phone);

/* Print single contact */
void print_contact(const CONTACT *c);

/* Print all contacts */
void print_all_contacts(CONTACT *contacts,
                        int count);

#endif
