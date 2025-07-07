#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char id[50];
    char name[50];
    int semester;
    char section[10];
    char department[50];
    double total_class;
    double present;
    double percentange;
    double cgpa;
};

struct student a[100];
int number_ofstudent;

int main()
{
    FILE *f = fopen("logs.txt", "r");
    if (f == 0)
    {
        f = fopen("logs.txt", "w");
        fclose(f);
    }
    else
    {
        fclose(f);
    }

    while (1)
    {
        int choice;
        printf("\n1. View all students\n");
        printf("2. Add a student information\n");
        printf("3. Delete a student information\n");
        printf("4. Update a student information\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1)
        {
            system("cls");
            f = fopen("logs.txt", "r");
            if (f == 0)
            {
                printf("Error opening the file\n");
                continue;
            }

            int i = 0;
            while (fscanf(f, "%s\n", a[i].id) == 1)
            {
                fscanf(f, "%[^\n]\n", a[i].name);
                fscanf(f, "%d\n", &a[i].semester);
                fscanf(f, "%s\n", a[i].section);
                fscanf(f, "%s\n", a[i].department);
                fscanf(f, "%lf\n", &a[i].total_class);
                fscanf(f, "%lf\n", &a[i].present);
                fscanf(f, "%lf\n", &a[i].percentange);
                fscanf(f, "%lf\n", &a[i].cgpa);
                i++;
            }
            number_ofstudent = i;
            fclose(f);

            for (int i = 0; i < number_ofstudent; i++)
            {
                for (int j = i + 1; j < number_ofstudent; j++)
                {
                    if (a[i].semester > a[j].semester)
                    {

                        struct student swap;
                        swap = a[i];
                        a[i] = a[j];
                        a[j] = swap;
                    }
                }
            }

            printf("\n\n---------------------------------\n");
            if (number_ofstudent == 0)
            {
                printf("No Student Info found\n");
            }
            else
            {
                for (int i = 0; i < number_ofstudent; i++)
                {
                    printf("Name: %s\n", a[i].name);
                    printf("ID: %s\n", a[i].id);
                    printf("CGPA: %.2lf\n", a[i].cgpa);
                    printf("semesterester: %d\n", a[i].semester);
                    printf("section: %s\n", a[i].section);
                    printf("department: %s\n", a[i].department);

                    printf("Attendance: %.2lf%%\n", a[i].percentange);
                    printf("---------------------------------\n");
                }
            }
        }

        else if (choice == 2)
        {
            system("cls");
            f = fopen("logs.txt", "r");
            if (f != 0)
            {
                int i = 0;
                while (fscanf(f, "%s\n", a[i].id) == 1)
                {
                    fscanf(f, "%[^\n]\n", a[i].name);
                    fscanf(f, "%d\n", &a[i].semester);
                    fscanf(f, "%s\n", a[i].section);
                    fscanf(f, "%s\n", a[i].department);
                    fscanf(f, "%lf\n", &a[i].total_class);
                    fscanf(f, "%lf\n", &a[i].present);
                    fscanf(f, "%lf\n", &a[i].percentange);
                    fscanf(f, "%lf\n", &a[i].cgpa);
                    i++;
                }
                number_ofstudent = i;
                fclose(f);
            }

            struct student temp;

            printf("Enter your ID: ");
            scanf("%s", temp.id);
            printf("Enter your Name: ");
            scanf(" %[^\n]", temp.name);
            printf("Enter your semesterester: ");
            scanf("%d", &temp.semester);
            printf("Enter your Section: ");
            scanf("%s", temp.section);
            printf("Enter your Department: ");
            scanf("%s", temp.department);
            printf("Enter the number of your total class: ");
            scanf("%lf", &temp.total_class);
            printf("Enter the number of your present: ");
            scanf("%lf", &temp.present);
            temp.percentange = (temp.present / (temp.total_class)) * 100;
            printf("Enter your CGPA: ");
            scanf("%lf", &temp.cgpa);

            a[number_ofstudent++] = temp;

            f = fopen("logs.txt", "w");
            if (f == 0)
            {
                printf("Error opening the file!!\n");
            }
            else
            {
                for (int i = 0; i < number_ofstudent; i++)
                {
                    fprintf(f, "%s\n", a[i].id);
                    fprintf(f, "%s\n", a[i].name);
                    fprintf(f, "%d\n", a[i].semester);
                    fprintf(f, "%s\n", a[i].section);
                    fprintf(f, "%s\n", a[i].department);
                    fprintf(f, "%lf\n", a[i].total_class);
                    fprintf(f, "%lf\n", a[i].present);
                    fprintf(f, "%.2lf\n", a[i].percentange);
                    fprintf(f, "%.2lf\n", a[i].cgpa);
                }
                fclose(f);
            }

            printf("Student added successfully!\n");
        }
        else if (choice == 3)
        {
            system("cls");

            f = fopen("logs.txt", "r");
            if (f != 0)
            {
                int i = 0;
                while (fscanf(f, "%s\n", a[i].id) == 1)
                {
                    fscanf(f, "%[^\n]\n", a[i].name);
                    fscanf(f, "%d\n", &a[i].semester);
                    fscanf(f, "%s\n", a[i].section);
                    fscanf(f, "%s\n", a[i].department);
                    fscanf(f, "%lf\n", &a[i].total_class);
                    fscanf(f, "%lf\n", &a[i].present);
                    fscanf(f, "%lf\n", &a[i].percentange);
                    fscanf(f, "%lf\n", &a[i].cgpa);
                    i++;
                }
                number_ofstudent = i;
                fclose(f);
            }
            int location = -1;
            char id[50];

            printf("Enter your id: ");
            scanf("%s", id);

            printf("\n\n");

            for (int i = 0; i < number_ofstudent; i++)
            {
                if (strcmp(a[i].id, id) == 0)
                {
                    location = i;
                    break;
                }
            }
            if (location == -1)
            {
                printf("Id not found!!\n");
                continue;
            }
            else
            {
                printf("Id removed succesfully\n");
            }
            for (int i = location; i < number_ofstudent - 1; i++)
            {
                a[i] = a[i + 1];
            }
            number_ofstudent--;

            f = fopen("logs.txt", "w");
            if (f == 0)
            {
                printf("Error opening the file!!\n");
            }
            else
            {
                for (int i = 0; i < number_ofstudent; i++)
                {
                    fprintf(f, "%s\n", a[i].id);
                    fprintf(f, "%s\n", a[i].name);
                    fprintf(f, "%d\n", a[i].semester);
                    fprintf(f, "%s\n", a[i].section);
                    fprintf(f, "%s\n", a[i].department);
                    fprintf(f, "%lf\n", a[i].total_class);
                    fprintf(f, "%lf\n", a[i].present);
                    fprintf(f, "%.2lf\n", a[i].percentange);
                    fprintf(f, "%.2lf\n", a[i].cgpa);
                }
                fclose(f);
            }
        }
        else if (choice == 4)
        {
            system("cls");
            f = fopen("logs.txt", "r");
            if (f == NULL)
            {
                printf("Error opening the file\n");
                continue;
            }

            int i = 0;
            while (fscanf(f, "%s\n", a[i].id) == 1)
            {
                fscanf(f, "%[^\n]\n", a[i].name);
                fscanf(f, "%d\n", &a[i].semester);
                fscanf(f, "%s\n", a[i].section);
                fscanf(f, "%s\n", a[i].department);
                fscanf(f, "%lf\n", &a[i].total_class);
                fscanf(f, "%lf\n", &a[i].present);
                fscanf(f, "%lf\n", &a[i].percentange);
                fscanf(f, "%lf\n", &a[i].cgpa);
                i++;
            }
            number_ofstudent = i;
            fclose(f);

            int location = -1;
            char id[50];

            printf("Enter your id: ");
            scanf("%s", id);

            printf("\n\n");

            for (int i = 0; i < number_ofstudent; i++)
            {
                if (strcmp(a[i].id, id) == 0)
                {
                    location = i;
                    break;
                }
            }
            if (location == -1)
            {
                printf("Id not found!!\n");
                continue;
            }

            int option;
            printf("PLease select what You want to Update\n");
            printf("1.Name\n");
            printf("2.section\n");
            printf("3.deaprtment\n");
            printf("4.cgpa\n");
            printf("5.semester\n");
            printf("Select an option: ");
            scanf("%d", &option);
            system("cls");

            while (1)
            {

                if (option == 1)
                {

                    char name[50];
                    printf("Please enter your updated name: ");
                    scanf("\n%[^\n]", name);

                    printf("\n\n");
                    strcpy(a[location].name, name);
                    printf("Your name updated succesfully\n\n");
                    break;
                }
                else if (option == 2)
                {
                    char section[50];
                    printf("Please enter your updated section: ");
                    scanf("%s", section);
                    printf("\n\n");

                    strcpy(a[location].section, section);
                    printf("Your section updated succesfully\n\n");
                    break;
                }
                else if (option == 3)
                {
                    char department[50];
                    printf("Please enter your updated department: ");
                    scanf("%s", department);
                    printf("\n\n");

                    strcpy(a[location].department, department);
                    printf("Your department updated succesfully\n\n");
                    break;
                }
                else if (option == 4)
                {
                    double cgpa;
                    printf("Please enter your updated CGPA: ");
                    scanf("%lf", &cgpa);
                    printf("\n\n");

                    a[location].cgpa = cgpa;
                    printf("Your cgpa updated succesfully\n\n");
                    break;
                }
                else if (option == 5)
                {
                    int semester;
                    printf("Please enter your updated semester: ");
                    scanf("%d", &semester);
                    printf("\n\n");

                    a[location].semester = semester;
                    printf("Your semester updated succesfully\n\n");
                    break;
                }
                else
                {
                    printf("Wrong option please try again\n\n");
                    printf("Enter a valid option (1-5): \n\n");

                    printf("1.Name\n");
                    printf("2.section\n");
                    printf("3.deaprtment\n");
                    printf("4.cgpa\n");
                    printf("5.semester\n");
                    printf("Select an option: ");
                    scanf("%d", &option);
                }
            }

            f = fopen("logs.txt", "w");
            if (f == 0)
            {
                printf("Error opening the file!!\n");
            }
            else
            {
                for (int i = 0; i < number_ofstudent; i++)
                {
                    fprintf(f, "%s\n", a[i].id);
                    fprintf(f, "%s\n", a[i].name);
                    fprintf(f, "%d\n", a[i].semester);
                    fprintf(f, "%s\n", a[i].section);
                    fprintf(f, "%s\n", a[i].department);
                    fprintf(f, "%lf\n", a[i].total_class);
                    fprintf(f, "%lf\n", a[i].present);
                    fprintf(f, "%.2lf\n", a[i].percentange);
                    fprintf(f, "%.2lf\n", a[i].cgpa);
                }
                fclose(f);
            }
        }
        else if (choice == 5)
        {
            printf("Thank You for using :)\n\n");
            return 0;
        }
        else
        {
            printf("Wrong option please try again\n\n");
            printf("Enter a valid option (1-5): \n\n");
        }
    }

    return 0;
}
