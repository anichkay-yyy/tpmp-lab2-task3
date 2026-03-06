/* anichkay */

/*
 * CONTACT module implementation (server)
 * Provides input, sorting, searching operations
 * for CONTACT structures in BLOCKNOTE array
 */

#include <stdio.h>
#include <string.h>

#include "contact.h"

/*
 * compare_dates - compares two dates
 * Returns negative if d1 < d2, positive if d1 > d2, 0 if equal
 */
static int
compare_dates(Date d1, Date d2)
{
        if (d1.year != d2.year)
                return d1.year - d2.year;
        if (d1.month != d2.month)
                return d1.month - d2.month;
        return d1.day - d2.day;
}

void
input_contacts(CONTACT *contacts,
               int *count,
               int max_size)
{
        int i;
        int n;

        printf("Enter number of contacts (max %d): ", max_size);
        scanf("%d", &n);
        getchar();

        if (n > max_size)
                n = max_size;
        if (n < 1)
                n = 1;

        for (i = 0; i < n; i++) {
                printf("\n--- Contact %d ---\n", i + 1);

                printf("Name (surname and initials): ");
                fgets(contacts[i].name, MAX_NAME, stdin);
                contacts[i].name[strcspn(contacts[i].name, "\n")] = '\0';

                printf("Phone number: ");
                fgets(contacts[i].tele, MAX_PHONE, stdin);
                contacts[i].tele[strcspn(contacts[i].tele, "\n")] = '\0';

                printf("Birth date (year month day): ");
                scanf("%d %d %d",
                      &contacts[i].date.year,
                      &contacts[i].date.month,
                      &contacts[i].date.day);
                getchar();
        }

        *count = n;
}

void
sort_by_date(CONTACT *contacts,
             int count)
{
        int     i;
        int     j;
        CONTACT temp;

        for (i = 0; i < count - 1; i++) {
                for (j = 0; j < count - i - 1; j++) {
                        if (compare_dates(contacts[j].date,
                                          contacts[j + 1].date) > 0) {
                                temp = contacts[j];
                                contacts[j] = contacts[j + 1];
                                contacts[j + 1] = temp;
                        }
                }
        }
}

void
find_by_phone(CONTACT *contacts,
              int count,
              const char *phone)
{
        int i;
        int found = 0;

        for (i = 0; i < count; i++) {
                if (strcmp(contacts[i].tele, phone) == 0) {
                        printf("\nContact found:\n");
                        print_contact(&contacts[i]);
                        found = 1;
                }
        }

        if (!found)
                printf("Contact with phone \"%s\" not found.\n", phone);
}

void
print_contact(const CONTACT *c)
{
        printf("  Name:  %s\n", c->name);
        printf("  Phone: %s\n", c->tele);
        printf("  Born:  %02d.%02d.%04d\n",
               c->date.day, c->date.month, c->date.year);
}

void
print_all_contacts(CONTACT *contacts,
                   int count)
{
        int i;

        printf("\n=== All contacts (sorted by birth date) ===\n");
        for (i = 0; i < count; i++) {
                printf("\n[%d]\n", i + 1);
                print_contact(&contacts[i]);
        }
}
