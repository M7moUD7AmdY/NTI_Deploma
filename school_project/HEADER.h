#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{ int day;
  int month;
  int year;
}DOB;


typedef struct
{char name[10],addres[10];
  int id;
  int pnum;
  int score;
  DOB db;

}school;
void new_student();
void delet_student(int);
void student_LIST();
void student_edit(int);
int rank_student(school arr[]);
void str_scan(char *str);
school arr[50];



#endif // HEADER_H_INCLUDED
