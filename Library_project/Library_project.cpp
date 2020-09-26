#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 50
#define SIZE 100

struct LM
{
    char book_id[NUM];
    char book_name[NUM];
    char publication_date[NUM];
    char author_name[NUM];
    char author_email_address[NUM];
};

int checkpoint = -1;
FILE* myfile;
FILE* temp;
int count = 0;
struct LM book_information;


char blank[1] = { '\n' };

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
    count++;
    system("pause");
    return 0;

}

char buff[50];

int standard;


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
                fputs(buff, temp);
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
                fputs(buff, temp);
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
                fputs(buff, temp);
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
                fputs(buff, temp);
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
                fputs(buff, temp);
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

    while (true)
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