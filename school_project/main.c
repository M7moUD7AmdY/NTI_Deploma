#include <stdio.h>
#include <stdlib.h>
#include"HEADER.h"
int main()
{
    int n=1,ds,es;
    printf("\tWillcome to my school management system\n\n\t\tMade by Mahmoud hamdi :)");
    printf("\n1_NEW_STUDENT\n2_DELETE_STUDENT\n3_STUDENT_LIST\n4_STUDENT_EDIT\n5_RANK_STUDENT");

    while(n)
    {printf("\n\nPleas enter your targeted (choose from 1 to 6) :");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            new_student();

        }
        break;
         case 2:
        {// not complet yet
            printf("pleas enter student id u want to delet :");
            scanf("%d",&ds);
            delet_student(ds);

        }
        break;
         case 3:
        {
        student_LIST();

        }
        break;
         case 4:
        {
           printf("pleas enter student num you want to edit :");
           scanf("%d",&es);
           student_edit(es);
        }
        break;
         case 5:
        {
         rank_student(arr);

        }
        break;
         default:
        {
            printf("\npleas enter number from 1 to 5");
        }
        break;
    }
    }


    return 0;
}
