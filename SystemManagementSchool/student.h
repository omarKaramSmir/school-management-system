#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdbool.h>
#define NULL ((char *)0)
//global variables
extern int Fun_to_edit,data_index ;
enum Fun_to_edit { Create_New_class,Add_New_Student,Delete_Student,Update_Student_Data,Print_Section_List,Print_Student_Data,Print_School_List,Update_SectionOfstudents_score,Update_student_score,Rank_students,EXIT} ;
enum data_index { data_name,data_address,data_phone_number,data_ID,ALL} ;
//=============================================================================================
//=============================================================================================
//struct
typedef struct Node{
     int studentclass ,studentsection;
     char studentName[30];
     float studentScore;
     char  studentAddress[30] ;
     char  studentPhoneNumber[12];
     int  studentID;
     struct Node* NextStudentPtr;
     struct Node* PrevStudentPtr;
     struct Node* NextScorePtr;
     struct Node* PrevScorePtr;
 }Student_Node;

typedef struct Student_List{
  int Class_Num , sec_Num ;
  struct Student_List* NextClassPtr;
  struct Student_List* PrevClassPtr;
  Student_Node*  STU_HeadPtr;
  Student_Node*  STU_TailPtr;
  int  listSize;
}Alpha_Student_Class;


typedef struct class_List{
  Alpha_Student_Class * Classlist_HeadPtr;
  Alpha_Student_Class * Classlist_TailPtr;
  int  listSize;
}List_of_Classes;

extern List_of_Classes CLASS_score_LIST ;
//=============================================================================================
//=============================================================================================

//initial functions
void Init_function();
void Select_What_to_Edit();
//list functions
void Create_ListOfClasses_list(List_of_Classes * l1);
bool insert_list(List_of_Classes * pl,int class_Choice,int score_disenable );
//search functions
Alpha_Student_Class* classList_search(List_of_Classes * pl,int STU_class,int STU_sec);
Student_Node* search_StudentNode2 (List_of_Classes * pl, int STU_ID);
Student_Node* search_StudentNode(Alpha_Student_Class* pl, int STU_ID);
//student data functions
bool insert_student(Alpha_Student_Class* pl,char* STU_Name,char* STU_Address,char* STU_phoneNumber,int STU_ID,int STU_class,int STU_sec);
bool delete_StudentNode(Alpha_Student_Class* pl,int STU_ID);
bool update_StudentData(Alpha_Student_Class* pl,int STU_ID);
//print functions
void print_StudentSection (Alpha_Student_Class* pl);
void print_studentData(Student_Node * pn);
void print_AllStudents(List_of_Classes * pl);
//score functions
void update_student_score(Student_Node * pn,float STU_score);
Alpha_Student_Class* class_scoreList_search(List_of_Classes * pl,int STU_class);
void update_sec_score(Alpha_Student_Class* pl);
void rank_students(Alpha_Student_Class* pl);

#endif // STUDENT_H_INCLUDED
