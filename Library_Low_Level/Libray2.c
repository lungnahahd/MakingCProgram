#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <io.h>

struct Books
{
    int ID[10];
    char name[20];
    char publisher[200];
};


struct Books books[20];

int myIndex = 0;

int main() {

    int next = 1;

    while (1)
    {
        _write(1, " \n", 3);

        _write(1, "\nEnter Book ID: ", 17);
        _read(0, books[myIndex].ID, sizeof(books[myIndex].ID));

        _write(1, "\nEnter book name: ", 19);
        //printf("\nEnter book name: ");
        _read(0, books[myIndex].name, sizeof(books[myIndex].name));


        _write(1, "\nEnter publisher: ", 19);
        _read(0, books[myIndex].publisher, sizeof(books[myIndex].publisher));

        myIndex++;

        _write(1, "\nRecord saved\n", 15);

        _write(1, "\nWould you like to add another book? \n<< Enter 1 to continue and 0 to exit>> ", 78);

        //professor I can't use 'read' function at next's scanf! Please help me.
        scanf("%d", &next);
        getchar();

        if (next == 0) break;

    }


    int i;

    for (i = 0; i < myIndex; i++)
    {
        printf("\n              \n");
        printf("\nID %s     \n", books[i].ID);
        printf("\nName %s     \n", books[i].name);
        printf("\nAddress %s\n  ", books[i].publisher);
    }
}