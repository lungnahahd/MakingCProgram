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

//파일과 연동하는 함수
int readfile()
{
    
    int rerror = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r+");
    for (int i = 0; i < 20; i++)
    {
        //파일이 존재하지 않을 경우 동작
        if (rerror != 0) break;
        if (feof(myfile))
        {
            fclose(myfile);

            break;
        }
        fread(books[i].ID, sizeof(books[i].ID), 1, myfile);
        fread(books[i].name, sizeof(books[i].name), 1, myfile);
        fread(books[i].publisher, sizeof(books[i].publisher), 1, myfile);
        myIndex++;
    }

    return 0;
}

int main() {

    readfile();
    _write(1, "Finish Read File!!  \n", 22);
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
    //불러온 파일 뿐만 아니라 새로 입력한 파일 전부를 출력하는 코드
    for (i = 0; i < myIndex - 1; i++)
    {
        if (feof(myfile))
        {
            break;
        }
        fread(list[i].ID, sizeof(list[i].ID), 1, myfile);
        fread(list[i].name, sizeof(list[i].name), 1, myfile);
        fread(list[i].publisher, sizeof(list[i].publisher), 1, myfile);
        printf("\n              \n");
        printf("\nID %s     \n", list[i].ID);
        printf("\nName %s     \n", list[i].name);
        printf("\nAddress %s\n  ", list[i].publisher);

    }
}
