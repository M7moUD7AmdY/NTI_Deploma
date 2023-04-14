#include<stdio.h>
#include"HEADER.h"
//glopal variable i used it at more than function
int i,j=1,sn,snt=0,pi=1,del[10]={0};
// complet
void new_student(void)
{

    printf("enter the number of student u want to add :");
    scanf("%d",&sn);
    snt+=sn;
    for(i=1;i<=snt;i++)
    {
    printf("\nEnter new student name(%d) :",i);
    str_scan(&arr[i].name);
    printf("\nEnter new student ID(%d) :",i);
    scanf("%d",&arr[i].id);
    printf("\nEnter new student score(%d) :",i);
    scanf("%d",&arr[i].score);
    printf("\nEnter new student day of bairth(%d) :",i);
    scanf("%d/%d/%d",&arr[i].db.day,&arr[i].db.month,&arr[i].db.year);
    printf("\nEnter new student phone num(%d) :",i);
    scanf("%d",&arr[i].pnum);
    printf("\nEnter new student address(%d) :",i);
    scanf("%s",arr[i].addres);
    }
    pi=i;
    printf("\nyou had been add %d new student",sn);
}




// not compleat yet need to linked list data structure
void delet_student(int a)
{j=1;//for more safty.
/*check if arr[j].id = the id i put it or not while it true
i will save the true case at variable to use it at list function
    */
    while(a!=arr[j].id)
    {
        j++;
    }
    del[j]=j;
    printf("\nthe studen %s with id:%d has been delated\n",arr[j].name,arr[j].id);
    pi--;//as a counter for list function;


}

// complet
void student_edit(int es)
{
    /*i used if &if else condithon to chaeck the modifing variable
    to select the elment that i want to modify it
    */
    int mo;//modifing variable
    printf("\n1_name\n2_ID\n3_score\n4_phone num\n5_addres\n6_DOB");
    printf("\nwhat do u want to edit on it :");
    scanf("%d",&mo);

    if(mo==1)
    {
        printf(">>%s will be modifid to :",arr[es].name);
        scanf("%s",&arr[es].name);
    }
    else if(mo==2)
    {
        printf(">>%d will be modifid to :",arr[es].id);
        scanf("%d",&arr[es].id);
    }
    else if(mo==3)
    {
        printf(">>%d will be modifid to :",arr[es].score);
        scanf("%d",&arr[es].score);
    }
    else if(mo==4)
    {
        printf(">>%d will be modifid to :",arr[es].pnum);
        scanf("%d",&arr[es].pnum);
    }
    else if(mo==5)
    {
        printf(">>%s will be modifid to :",arr[es].addres);
        scanf("%s",&arr[es].addres);
    }
    else if(mo==6)
    {
        printf(">>%d/%d/%d will be modifid to :",arr[es].db.day,arr[es].db.month,arr[es].db.year);
        scanf("%d/%d/%d",&arr[es].db.day,&arr[es].db.month,&arr[es].db.year);

    }


}
/* i use  if condition inside for loop to check the del variable & not
printing the deleted student;
*/
void student_LIST()
{   j=1;//for more safty

// condtion to check if the list is emte or not
if(pi==0)
{
    printf("there are no student pleas enter ne student first");
}
else{


     printf("\nName \t\t ID \t\t SCORE \t\t DOB \t\t Phone num \t\t Adress ");
// condithion with loop to select the deleted data.
    for(j=1;j<=snt;j++)
    {
        if(j!=del[j])
        {
          printf(" \n%s\t\t %d\t\t %d\t\t%d/%d/%d\t%d\t\t%s",arr[j].name,arr[j].id,arr[j].score,arr[j].db.day,arr[j].db.month,arr[j].db.year,arr[j].pnum,arr[j].addres);
        }
    }
}
}

/*i send the array of struct to the function
and do if condithion inside 2 for loops to select the lower
score and sorted it as a first element ;
*/
int rank_student( school rn[])
{school temp;
for(i=1;i<=snt;i++)
{
    for(j=i+1;j<=snt;j++)
    {
        if(rn[i].score>rn[j].score)
        {
            temp=rn[i];
            rn[i]=rn[j];
            rn[j]=temp;

        }
    }
}
// printing the new  sorted list
printf("\nName \t\t ID \t\t SCORE \t\t DOB \t\t Phone num \t\t Adress ");
for(i=1;i<=snt;i++)
{
    if(i!=del[i]){
printf(" \n%s\t\t %d\t\t %d\t\t%d/%d/%d\t%d\t\t%s",rn[i].name,rn[i].id,rn[i].score,rn[i].db.day,rn[i].db.month,rn[i].db.year,rn[i].pnum,rn[i].addres);

}}

}
//****************************
void str_scan(char *str)
{
    int i=0;
    scanf(" %c",&str[i]);
    while(str[i] != '\n')
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}
// functoin file end
