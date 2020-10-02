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

FILE* myfile;
struct Books books[20];

int myIndex = 0;

int main() {

    int error = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "a");
    if (error != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }

    int next = 1;

    while (1)
    {
        _write(1, " \n", 3);

        _write(1, "\nEnter Book ID: ", 17);
        _read(0, books[myIndex].ID, sizeof(books[myIndex].ID));
        fwrite(books[myIndex].ID, sizeof(books[myIndex].ID), 1, myfile);

        _write(1, "\nEnter book name: ", 19);
        //printf("\nEnter book name: ");
        _read(0, books[myIndex].name, sizeof(books[myIndex].name));
        fwrite(books[myIndex].name, sizeof(books[myIndex].name), 1, myfile);


        _write(1, "\nEnter publisher: ", 19);
        _read(0, books[myIndex].publisher, sizeof(books[myIndex].publisher));
        fwrite(books[myIndex].publisher, sizeof(books[myIndex].publisher), 1, myfile);

        myIndex++;

        _write(1, "\nRecord saved\n", 15);

        _write(1, "\nWould you like to add another book? \n<< Enter 1 to continue and 0 to exit>> ", 78);

        //professor I can't use 'read' function at next's scanf! Please help me.
        scanf("%d", &next);
        getchar();

        if (next == 0) break;

    }
    fclose(myfile);


    int i;

    struct Books list[20];
    int error2 = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r+");
    if (error2 != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }

    for (i = 0; i < myIndex; i++)
    {
        fread(&list[i], sizeof(struct Books), 1, myfile);
        printf("\n              \n");
        printf("\nID %s     \n", list[i].ID);
        printf("\nName %s     \n", list[i].name);
        printf("\nAddress %s\n  ", list[i].publisher);
    }
}
