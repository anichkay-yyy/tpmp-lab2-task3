/* anichkay */

/*
 * CONTACT phonebook client
 * Inputs contacts into BLOCKNOTE array,
 * sorts by birth date, searches by phone number
 */

#include <stdio.h>

#include "contact.h"

int
main(void)
{
        CONTACT blocknote[BLOCKNOTE_SIZE];
        int     count = 0;
        char    phone[MAX_PHONE];

        /* input contacts from keyboard */
        input_contacts(blocknote, &count, BLOCKNOTE_SIZE);

        /* sort by birth date ascending */
        sort_by_date(blocknote, count);

        /* display sorted contacts */
        print_all_contacts(blocknote, count);

        /* search by phone number */
        printf("\nEnter phone number to search: ");
        fgets(phone, MAX_PHONE, stdin);
        phone[strcspn(phone, "\n")] = '\0';

        find_by_phone(blocknote, count, phone);

        return 0;
}
