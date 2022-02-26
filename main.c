#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Initializing Required Variables
    int NoSem, NoSub, CSem, CSub, EMrk, TCH, CH, CP = 0;
    float GPA, TGP, GP, CGPA, TGPA;
    char Grade, Grade_;

    //Entering No. of Semesters
    do {
        printf("Enter No. of Semesters : ");
        scanf("%d", &NoSem);
        if(NoSem > 8)
            printf("Invalid Input! Enter Again.\n");
    } while(NoSem > 8);

    printf("___________________________\n");

    //Loop for each semester result
    for(CSem = 1; CSem <= NoSem; CSem++) {
        printf("\n\nSEMESTER %d\n", CSem);
        printf("___________\n");

        //Entering No. of Subject studied in current semester
        do {
            printf("No. of Subject Studied in Semester %d : ", CSem);
            scanf("%d", &NoSub);
            if(NoSub > 7)
                printf("Invalid Input! Enter Again.\n");
        } while(NoSub > 7);

        printf("\nENTER MARKS (or enter -1 to terminate)\n\n");

        TGP = 0, CH = 0;

        //Loop for each subject result
        for(CSub = 1; CSub <= NoSub; CSub++) {
            printf("Subject %d:  ", CSub);
            scanf("%d", &EMrk);

            if(EMrk == -1)
                return 0;
            else if(EMrk < 0 || EMrk > 100)
                EMrk = 50;

            //Getting Grade and GPA by Marks
            if(EMrk < 50)
                GP = 0.00, Grade = 'F', Grade_ = ' ';
            else if(EMrk < 54)
                GP = 0.10, Grade = 'D', Grade_ = ' ';
            else if(EMrk < 58)
                GP = 1.01, Grade = 'D', Grade_ = '+';
            else if(EMrk < 61)
                GP = 1.31, Grade = 'C', Grade_ = '-';
            else if(EMrk < 64)
                GP = 1.67, Grade = 'C', Grade_ = ' ';
            else if(EMrk < 68)
                GP = 2.01, Grade = 'C', Grade_ = '+';
            else if(EMrk < 71)
                GP = 2.34, Grade = 'B', Grade_ = '-';
            else if(EMrk < 75)
                GP = 2.67, Grade = 'B', Grade_ = ' ';
            else if(EMrk < 80)
                GP = 3.01, Grade = 'B', Grade_ = '+';
            else if(EMrk < 85)
                GP = 3.34, Grade = 'A', Grade_ = '-';
            else if(EMrk >= 85)
                GP = 3.67, Grade = 'A', Grade_ = ' ';

            //Printing Marks, GP, Grade for each subject
            printf("    Marks : %d    Grade Point : %.2f    Grade : %c%c\n", EMrk, GP, Grade, Grade_);
            TGP += GP * 4;
        }

        CH = NoSub * 4;
        GPA = (float)TGP / (float)CH;
        TGPA += TGP;
        TCH += CH;

        //Printing result for each subject
        printf("\nCredit Hours :     %d\n", CH);
        printf("Total GP :         %.2f\n", TGP);
        printf("Semester %d GPA :   %.2f\n", CSem, GPA);

        //Printing Probation when GPA in less than 2
        if(GPA < 2.00) {
            printf("\nSTUDENT STATUS\n");
            printf("    DANGER! YOU ARE IN PROBATION!!!\n");
            CP += 1;
            if(CP == 2) {
                if(CSem <= 4) {
                    printf("    SORRY! YOU CANNOT CONTINUE YOUR DEGREE!!!\n");
                    return 0;
                }
                else {
                    printf("    SORRY! YOU HAVE TO REPEAT YOUR SEMESTER!!!\n");
                    return 0;
                }
            }
        }
        else
            CP = 0;
    }
    CGPA = TGPA / (float)TCH;
    printf("\n\nCumulative Grade Point Average\n");
    printf("________");

    //Printing CGPA
    if(NoSem == 8)
        printf("\n\n    End of Degree CGPA :      %.2f\n", CGPA);
    else
        printf("\n\n    Current CGPA :    %.2f\n", CGPA);
    printf("___________________________\n");
    return 0;
}
