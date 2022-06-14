#include <stdio.h>
#include <string.h>

struct Person
{
    char fisrtName[100];
    char lastName[100];
    int phoneNumber;
    /* data */
};

int main()
{
    // creating array of struc to store records of phonebook.txt file
    struct Person persons[10];

    // opeening file
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL)
    {
        printf("This File can not be opened.\n");
    }
    else
    {
        int count = 10;

        struct Person persons[count];

        // storing each record in array
        for (int i = 0; i < count; i++)
        {
            fscanf(file, "%s %s %d\n", persons[i].fisrtName, persons[i].lastName, &persons[i].phoneNumber);
        }

        char firstName[100], lastName[100];

        printf("Please, write the first name and surname of the person.\n");
        scanf("%s", firstName);
        scanf("%s", lastName);

        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(persons[i].fisrtName, firstName) == 0 && strcmp(persons[i].lastName, lastName) == 0)
            {
                found = 1;
                printf("%s %s %d\n", persons[i].fisrtName, persons[i].lastName, persons[i].phoneNumber);
            }
        }
        if (found == 0)
            printf("NOT FOUND\n");
    }
    return 1;
}
