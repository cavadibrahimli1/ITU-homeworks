#include <stdio.h>
#include <string.h>

struct Person
{
    char Name[100];
    char Surname[100];
    int phoneNumber;
};

int main()
{

    struct Person contacts[10];


    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL)
    {
        printf("This File can not be opened.\n");
    }
    else
    {
        int count = 10;

        struct Person contacts[count];


        for (int i = 0; i < count; i++)
        {
            fscanf(file, "%s %s %d\n", contacts[i].Name, contacts[i].Surname, &contacts[i].phoneNumber);
        }

        char Name[100], Surname[100];

        printf("Please, write the  name and surname of the person.\n");
        scanf("%s", Name);
        scanf("%s", Surname);

        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(contacts[i].Name, Name) == 0 && strcmp(contacts[i].Surname, Surname) == 0)
            {
                found = 1;
                printf("%s %s %d\n", contacts[i].Name, contacts[i].Surname, contacts[i].phoneNumber);
            }
        }
        if (found == 0)
            printf("NOT FOUND!!!\n");
    }
    return 1;
}
