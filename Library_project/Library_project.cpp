﻿#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 50
#define SIZE 100

//책 정보를 담는 구조체
struct LM
{
    char book_id[NUM];
    char book_name[NUM];
    char publication_date[NUM];
    char author_name[NUM];
    char author_email_address[NUM];
};

FILE* myfile; // 실제 파일 루트
FILE* temp; // 복사를 위한 예비 파일 루트
struct LM book_information;
char blank[1] = { '\n' }; //공백 삽입을 위한 변수
char buff[50]; // 파일의 문자열을 받기 위한 버퍼
// 책의 정보를 입력하는 함수
int addinfo()
{

    int error = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "a");
    if (error != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }
    system("cls");
    printf("Add book information\n");
    printf("---------------------------------------------------------\n");
    printf("1. BOOK ID : ");
    scanf_s("%[^\n]s\n", book_information.book_id, 50);
    getchar();
    fclose(myfile);
    fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r+");
    int check_id = 0;
    //실제 book_id에 입력된 내용만 카운트 해주는 size 변수
    int size = 0;
    for (int i = 0; i < 50; i++)
    {
        if (book_information.book_id[i] == NULL)
        {
            break;
        }
        size++;
    }
    //id가 중복되는지 중복되지 않는지 확인하는 과정
    while (!feof(myfile))
    {

        fgets(buff, 50, myfile);
        if (check_id % 5 == 0)
        {
            int test = strncmp(buff, book_information.book_id, size);
            if (test == 0)
            {
                printf("This id is already in Library!!!!!!\n");
                system("pause");
                fclose(myfile);
                return 0;
            }
        }
        check_id++;
    }
    fclose(myfile);
    fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "a");
    fputs(book_information.book_id, myfile);
    fputc(blank[0], myfile);
    printf("2. BOOK NAME : ");
    scanf_s("%[^\n]s\n", book_information.book_name, 50);
    getchar();
    fputs(book_information.book_name, myfile);
    fputc(blank[0], myfile);
    printf("3. PUBLICATION DATE : ");
    scanf_s("%[^\n]s\n", book_information.publication_date, 50);
    getchar();
    fputs(book_information.publication_date, myfile);
    fputc(blank[0], myfile);
    printf("4. AUTHOR NAME : ");
    scanf_s("%[^\n]s\n", book_information.author_name, 50);
    getchar();
    fputs(book_information.author_name, myfile);
    fputc(blank[0], myfile);
    printf("5. AUTHOR EMAIL ADDRESS : ");
    scanf_s("%[^\n]s\n", book_information.author_email_address, 50);
    getchar();
    fputs(book_information.author_email_address, myfile);
    fputc(blank[0], myfile);
    fclose(myfile);
    system("pause");
    return 0;

}

//화면에 전체 책 리스트를 출력해서 보여주는 함수
int displaylist()
{
    int check = 0;

    int error = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r");
    if (error != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }
    system("cls");
    if (myfile == NULL)
    {
        printf("Book List\n");
        printf("---------------------------------------------------------\n");
        printf("NO INFORMATION!!");
        system("pause");
        return 0;
    }
    else
    {
        printf("Book List\n");
        printf("---------------------------------------------------------\n");
        int countnum = 1;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (check % 5 == 1)
            {
                printf("%d. ", countnum);
                printf(buff);
                printf("**********************************************************\n");
                countnum++;
            }
            check++;
        }
    }

    fclose(myfile);
    return 0;
}
// 파일 전체를 삭제하는 어찌보면 위험한 함수
int deletefile()
{
    system("cls");
    int result = remove("C:\\Users\\ASUS\\Documents\\information.txt");
    if (result == 0)
    {
        printf("SELECT MENU\n");
        printf("---------------------------------------------------------\n");
        printf("Delete data complite!!!\n");
    }
    else if (result == -1)
    {
        printf("SELECT MENU\n");
        printf("---------------------------------------------------------\n");
        printf("Already No Data!!!\n");
    }
    system("pause");
    return 0;
}

int choice;
//changedata()에서 사용되는 변수(어느 부분을 변경해야 할지 기준이 되어주는 역할 수행)
int standard;
// 선택된 책에 상세 정보를 화면에 보여주는 함수
int searchdata()
{
    int find = 0;

    displaylist();
    int error = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r");
    if (error != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }
    printf("===============================================================\n");
    printf("===============================================================\n");
    printf("Show me what you what? (insert Num)     ");
    scanf_s("%d", &choice, 3);
    system("cls");
    printf("Show Book's Data\n");
    printf("( 1 = Book ID, 2 = Book Name, 3 = Publication Date, 4 = Author Name, 5 = Author Email Address )\n");
    printf("---------------------------------------------------------\n");

    int checkdetail = 1;
    while (!feof(myfile))
    {
        fgets(buff, 50, myfile);
        if (find == (choice - 1) * 5)
        {
            standard = find;
            while (find < choice * 5)
            {
                printf("%d. ", checkdetail);
                printf(buff);
                find++;
                checkdetail++;
                fgets(buff, 50, myfile);
            }
            break;
        }
        find++;
    }

    fclose(myfile);
    return 0;
}

//상세정보 중, 원하는 데이터를 수정하는 함수
int changedata()
{
    searchdata();
    int cerror = fopen_s(&temp, "C:\\Users\\ASUS\\Documents\\tempinfo.txt", "w");
    int error = fopen_s(&myfile, "C:\\Users\\ASUS\\Documents\\information.txt", "r+");
    char oldname[] = "C:\\Users\\ASUS\\Documents\\tempinfo.txt";
    char newname[] = "C:\\Users\\ASUS\\Documents\\information.txt";
    if (error != 0 || cerror != 0)
    {
        printf("ERROR! PLEASE CHECK AGAIN");
        exit(1);
    }
    printf("===============================================================\n");
    printf("===============================================================\n");
    printf("Do you want to go back, Please select 0\n");
    printf("Do you want to change book's information? (insert Num)     ");
    int change;
    scanf_s("%d", &change, 3);
    getchar();
    if (change == 0)
    {
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");
        return 0;
    }
    else if (change == 1)
    {
        int change1 = 0;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (change1 == standard)
            {
                printf("Change id : ");
                scanf_s("%[^\n]s\n", book_information.book_id, 50);
                getchar();
                fputs(book_information.book_id, temp);
                fputc(blank[0], temp);
            }
            else
            {
                if (!feof(myfile))
                {
                    fputs(buff, temp);
                }
                else
                {
                    break;
                }
            }
            change1++;
        }
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\information.txt");
        rename(oldname, newname);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");
    }
    else if (change == 2)
    {
        int change2 = 0;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (change2 == standard + 1)
            {
                printf("Change name : ");
                scanf_s("%[^\n]s\n", book_information.book_name, 50);
                getchar();
                fputs(book_information.book_name, temp);
                fputc(blank[0], temp);
            }
            else
            {
                if (!feof(myfile))
                {
                    fputs(buff, temp);
                }
                else
                {
                    break;
                }
            }
            change2++;
        }
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\information.txt");
        rename(oldname, newname);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");
    }
    else if (change == 3)
    {
        int change3 = 0;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (change3 == standard + 2)
            {
                printf("Change publication date : ");
                scanf_s("%[^\n]s\n", book_information.publication_date, 50);
                getchar();
                fputs(book_information.publication_date, temp);
                fputc(blank[0], temp);
            }
            else
            {
                if (!feof(myfile))
                {
                    fputs(buff, temp);
                }
                else
                {
                    break;
                }
            }
            change3++;
        }
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\information.txt");
        rename(oldname, newname);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");
    }
    else if (change == 4)
    {
        int change4 = 0;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (change4 == standard + 3)
            {
                printf("Change author name : ");
                scanf_s("%[^\n]s\n", book_information.author_name, 50);
                getchar();
                fputs(book_information.author_name, temp);
                fputc(blank[0], temp);
            }
            else
            {
                if (!feof(myfile))
                {
                    fputs(buff, temp);
                }
                else
                {
                    break;
                }
            }
            change4++;
        }
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\information.txt");
        rename(oldname, newname);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");
    }
    else if (change == 5)
    {
        int change5 = 0;
        while (!feof(myfile))
        {
            fgets(buff, 50, myfile);
            if (change5 == standard + 4)
            {
                printf("Change author email address : ");
                scanf_s("%[^\n]s\n", book_information.author_email_address, 50);
                getchar();
                fputs(book_information.author_email_address, temp);
                fputc(blank[0], temp);
            }
            else
            {
                if (!feof(myfile))
                {
                    fputs(buff, temp);
                }
                else
                {
                    break;
                }
            }
            change5++;
        }
        fclose(myfile);
        fclose(temp);
        remove("C:\\Users\\ASUS\\Documents\\information.txt");
        rename(oldname, newname);
        remove("C:\\Users\\ASUS\\Documents\\tempinfo.txt");

    }
    return 0;
}


int main()
{
    while (1)
    {
        system("cls");
        printf("SELECT MENU\n");
        printf("---------------------------------------------------------\n");
        printf("1. Add book information\n");
        printf("2. Update book informaiton\n");
        printf("3. Search book information\n");
        printf("4. Display a list of all books\n");
        printf("5. Delete all information\n");
        printf("6. End Program\n");
        printf("---------------------------------------------------------\n");
        printf("what is your choice?     ");

        int select;
        scanf_s("%d", &select);
        getchar();
        if (select == 1)
        {
            addinfo();
        }
        else if (select == 2)
        {
            changedata();
        }
        else if (select == 3)
        {
            searchdata();
            system("pause");
        }
        else if (select == 4)
        {
            displaylist();
            system("pause");
        }
        else if (select == 5)
        {
            deletefile();
        }
        else if (select == 6)
        {
            break;
        }
    }
    return 0;
}