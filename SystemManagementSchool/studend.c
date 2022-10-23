#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include<string.h>
float score;
List_of_Classes CLASS_score_LIST ;
int Fun_to_edit=-1 ,First_prep_index=0 ,Second_prep_index=0,Third_prep_index=0 ,data_index=-1 ,ran;
int First_prep_rank=0 ,Second_prep_rank=0,Third_prep_rank=0 ;
//================================================================================================
//================================================================================================

void Init_function()
{
    int pass;
    while(1)
    {
        printf("welcome,sir.\nEnter password ,please\n") ;
        scanf("%d",&pass);
        if(pass == 11)
        {
            printf("valid password");
            break;
        }
        else printf("wrong password!\n===========================================================================\n");
    }
}
//================================================================================================
//================================================================================================
void Select_What_to_Edit()
{
    printf("\nplease Enter one of this options to edit.\n(0) to create new section\n(1) to add new student");
    printf("\n(2) to delete student\n(3) to update student data\n(4) to Print Section List\n(5) to Print student data");
    printf("\n(6) to Print all students data\n(7) to update section of student score\n(8) to update student score\n(9) to rank students\n(10) to EXIT\n");
    scanf("%d",&Fun_to_edit);
}
//================================================================================================
//================================================================================================

void Create_ListOfClasses_list(List_of_Classes * l1)
{
  l1->Classlist_HeadPtr = NULL;
  l1->Classlist_TailPtr = NULL;
  l1->listSize = 0;
}
//================================================================================================
//================================================================================================
bool insert_list(List_of_Classes * pl,int class_Choice,int score_disenable )
{
    //step 1 : allocate a memory for class list
   Alpha_Student_Class * pn=(Alpha_Student_Class *)malloc(sizeof(Alpha_Student_Class));
   if(pn == NULL)
   {
       printf("No memory available\n");
       return false;
   }
   //step 2 : initialization class list
   pn->STU_HeadPtr = NULL;
   pn->STU_TailPtr = NULL;
   pn->Class_Num = class_Choice;
   pn->NextClassPtr = NULL;
   pn->PrevClassPtr = NULL;
   pn->listSize = 0;
   if(score_disenable)
   {
       switch(class_Choice)
      {
         case 1:
            First_prep_index++;
            pn->sec_Num = First_prep_index;
            break;
         case 2:
            Second_prep_index++;
            pn->sec_Num = Second_prep_index;
            break;
         case 3:
            Third_prep_index++;
            pn->sec_Num = Third_prep_index;
            break;
       }
   }
   //step 3 : insert node in list
   //step 3.1 : if empty
   if(pl->Classlist_HeadPtr == NULL)
   {
       pl->Classlist_HeadPtr = pl->Classlist_TailPtr = pn;
   }
   //step 3.2 : if Not empty
   else{
       // search for correct place
       Alpha_Student_Class * temp = pl->Classlist_HeadPtr;//init
       while(temp!= NULL && class_Choice >= temp->Class_Num && pn->sec_Num >= temp->sec_Num)
       {
           temp = temp->NextClassPtr;
       }
       if(temp == pl->Classlist_HeadPtr)// @ head
       {
          //step 1 :new node next is old head
          pn->NextClassPtr = pl->Classlist_HeadPtr;
          //step 2 : old head prev is new node
          pl->Classlist_HeadPtr->PrevClassPtr = pn;
          //step 3 : assign new node as new head
          pl->Classlist_HeadPtr = pn;
       }
       else if(temp == NULL)//@ Tail
       {
          //step 1 : assign old tail as new node prev
          pn->PrevClassPtr = pl->Classlist_TailPtr;
          //step 2 : assign new node as old tail`s next
          pl->Classlist_TailPtr->NextClassPtr = pn;
          //step 3 : assign new node as new tail
          pl->Classlist_TailPtr = pn;
       }
        else // @ middle
        {
            pn->NextClassPtr = temp;
            pn->PrevClassPtr = temp->PrevClassPtr;
            temp->PrevClassPtr->NextClassPtr = pn;
            temp->PrevClassPtr = pn;
        }

     }//else not empty

  pl->listSize++;
  if(score_disenable)
     printf("\nclass list for sec(%d)_class(%d) is created\n",pn->sec_Num,class_Choice);
  else
    //printf("\nclass list for class(%d) is created\n",class_Choice);

  return true;
}
//================================================================================================
//================================================================================================
bool insert_student(Alpha_Student_Class* pl,char* STU_Name,char* STU_Address,char* STU_phoneNumber,int STU_ID,int STU_class,int STU_sec)
{
    //step 1 : allocate a memory for Node
   Student_Node * pn=(Student_Node *)malloc(sizeof(Student_Node));
   if(pn == NULL)
   {
       printf("No memory available\n");
       return false;
   }
   //step 2 : initialization node
   pn->studentclass = STU_class;
   pn->studentsection = STU_sec;
   strcpy(pn->studentName,STU_Name);
   strcpy(pn->studentAddress,STU_Address);
   strcpy(pn->studentPhoneNumber,STU_phoneNumber);
   pn->studentID = STU_ID;
   pn->studentScore = 0;
   pn->NextStudentPtr = NULL;
   pn->PrevStudentPtr = NULL;
   //step 3 : insert node in list
   //step 3.1 : if empty
   if(pl->STU_HeadPtr == NULL)
   {
       pl->STU_HeadPtr = pl->STU_TailPtr = pn;
   }
   //step 3.2 : if Not empty
   else{
       // search for correct place
       Student_Node * temp = pl->STU_HeadPtr;//init
       while(temp!= NULL && strcmp(STU_Name,temp->studentName) >0)
       {
           temp = temp->NextStudentPtr;
       }
       if(temp == pl->STU_HeadPtr)// @ head
       {
          //step 1 :new node next is old head
          pn->NextStudentPtr = pl->STU_HeadPtr;
          //step 2 : old head prev is new node
          pl->STU_HeadPtr->PrevStudentPtr = pn;
          //step 3 : assign new node as new head
          pl->STU_HeadPtr = pn;
       }
       else if(temp == NULL)//@ Tail
       {
          //step 1 : assign old tail as new node prev
          pn->PrevStudentPtr = pl->STU_TailPtr;
          //step 2 : assign new node as old tail`s next
          pl->STU_TailPtr->NextStudentPtr = pn;
          //step 3 : assign new node as new tail
          pl->STU_TailPtr = pn;
       }
        else // @ middle
        {
            pn->NextStudentPtr = temp;
            pn->PrevStudentPtr = temp->PrevStudentPtr;
            temp->PrevStudentPtr->NextStudentPtr = pn;
            temp->PrevStudentPtr = pn;
        }

     }//else not empty
  pl->listSize++;
  printf("%s is inserted into sec(%d)_class(%d)\n",STU_Name,STU_sec,STU_class);
  return true;
}
//================================================================================================
//================================================================================================
bool delete_StudentNode(Alpha_Student_Class* pl,int STU_ID)
{
     if(pl->STU_HeadPtr == NULL)
   {
       printf("No data available , the list is empty\n");
       return false;
   }
   Student_Node * temp = search_StudentNode(pl,STU_ID);
       if(temp == NULL)
       {
          printf("no ID with value %d is found\n",STU_ID);
          return false ;
       }
       else if(temp == pl->STU_TailPtr &&temp == pl->STU_HeadPtr)
       {
          pl->STU_HeadPtr = pl->STU_TailPtr = NULL;
          free(temp);
       }
       else if(temp == pl->STU_HeadPtr)
       {
          pl->STU_HeadPtr = temp->NextStudentPtr ;
          pl->STU_HeadPtr->PrevStudentPtr = NULL;
          free(temp);
       }
       else if(temp == pl->STU_TailPtr)
       {
          pl->STU_TailPtr = temp->PrevStudentPtr ;
          pl->STU_TailPtr->NextStudentPtr = NULL;
          free(temp);
       }
       else
       {
            temp->NextStudentPtr->PrevStudentPtr = temp->PrevStudentPtr;
            temp->PrevStudentPtr->NextStudentPtr = temp->NextStudentPtr;
            free(temp);
       }
  pl->listSize--;
  printf("student with id(%d) is deleted\n",STU_ID);
  return true;
}
//================================================================================================
//================================================================================================
Alpha_Student_Class* classList_search(List_of_Classes * pl,int STU_class,int STU_sec)
{
   Alpha_Student_Class * temp = pl->Classlist_HeadPtr;
  while(temp!= NULL && STU_class != temp->Class_Num && STU_sec != temp->sec_Num)
  {
      temp = temp->NextClassPtr;
  }
  return temp;
}
//================================================================================================
//================================================================================================
Student_Node* search_StudentNode(Alpha_Student_Class* pl, int STU_ID)
{
    Student_Node * temp = pl->STU_HeadPtr;
    while(temp!= NULL && STU_ID != temp->studentID )
    {
       temp = temp->NextStudentPtr;
    }
    return temp;
}
//================================================================================================
//================================================================================================
Student_Node* search_StudentNode2(List_of_Classes * pl, int STU_ID)
{
    Student_Node * STU_temp ;
    Alpha_Student_Class * temp = pl->Classlist_HeadPtr;
    while(temp!= NULL)
    {
        STU_temp = search_StudentNode(temp,STU_ID);
        if(STU_temp!= NULL)
            return STU_temp;
        temp = temp->NextClassPtr;
    }
}
//================================================================================================
//================================================================================================
bool update_StudentData(Alpha_Student_Class* pl,int STU_ID)
{
       Student_Node * temp = search_StudentNode(pl,STU_ID);
       if(temp == NULL)
       {
          printf("no ID with value %d is found\n",STU_ID);
          return false ;
       }
       else
       {
           switch(data_index)
                {
                    case data_name:
                        printf("\nEnter new name?\n");
                        gets(temp->studentName);
                        break;

                    case data_address:
                        printf("\nEnter new address ?\n");
                        gets(temp->studentAddress);
                        break;

                    case data_phone_number:
                         printf("\nEnter new phone number ?\n");
                         gets(temp->studentPhoneNumber);
                        break;

                    case data_ID:
                        printf("\nEnter new id ?\n");
                        scanf("%d",&temp->studentID);
                        break;
                }
                return true;
       }

}

//================================================================================================
//================================================================================================
void print_StudentSection(Alpha_Student_Class* pl)
{
    if(pl->STU_HeadPtr == NULL)//list is empty
    {
        printf("section is empty\n");
        return;
    }
   Student_Node * temp;
   for(temp= pl->STU_HeadPtr ;temp!= NULL;temp=temp->NextStudentPtr)
   {
       switch(data_index)
                {
                    case data_name:
                        printf("%s\n",temp->studentName);
                        break;

                    case data_address:
                        printf("%s\n",temp->studentAddress);
                        break;

                    case data_phone_number:
                        printf("%s\n",temp->studentPhoneNumber);
                        break;

                    case data_ID:
                        printf("%d\n",temp->studentID);
                        break;
                    case ALL :
                        print_studentData(temp);
                        printf("\n************************\n");
                        break;
                }
   }
}

//================================================================================================
//================================================================================================
void print_studentData(Student_Node * pn)
{
    printf("studentName : %s\n",pn->studentName);
    printf("studentAddress : %s\n",pn->studentAddress);
    printf("studentPhoneNumber : %s\n",pn->studentPhoneNumber);
    printf("studentID : %d\n",pn->studentID);
    printf("studentClass : %d\n",pn->studentclass);
    printf("studentSection : %d\n",pn->studentsection);
    printf("studentScore : %f\n",pn->studentScore);
}
//================================================================================================
//================================================================================================
void print_AllStudents(List_of_Classes * pl)
{
    data_index = ALL;
    Alpha_Student_Class * temp = pl->Classlist_HeadPtr;
    while(temp!= NULL)
    {
        print_StudentSection(temp);
        temp = temp->NextClassPtr;
    }

}
//================================================================================================
//================================================================================================
void update_student_score(Student_Node * pn,float STU_score)
{
    //create the class score list for the student class if not created before
    switch( pn->studentclass )
    {
        case 1:
            if(First_prep_rank==0)
            {
                insert_list(&CLASS_score_LIST,1,0);
                First_prep_rank++;
            }
            break;
        case 2:
            if(First_prep_rank==0)
            {
                insert_list(&CLASS_score_LIST,2,0);
                Second_prep_rank++;
            }
            break;
        case 3:
            if(First_prep_rank==0)
            {
                insert_list(&CLASS_score_LIST,3,0);
                Third_prep_rank++;
            }
            break;
    }

    //search for the address of student class in CLASS_score_LIST
    Alpha_Student_Class * pl = class_scoreList_search(&CLASS_score_LIST,pn->studentclass);

    //insert student node in the class score list according to score
    //step 1 : initialization node
    pn->studentScore =STU_score ;
    pn->NextScorePtr = NULL;
    pn->PrevScorePtr = NULL;
    //insert node in list
    // if empty
    if(pl->STU_HeadPtr == NULL)
    {
       pl->STU_HeadPtr = pl->STU_TailPtr = pn;
    }
    // if Not empty
    else{
       // search for correct place
       Student_Node * temp = pl->STU_HeadPtr;
       while(temp!= NULL && temp->studentScore > STU_score )
       {
           temp = temp->NextScorePtr;
       }
       if(temp == pl->STU_HeadPtr)// @ head
       {
          //step 1 :new node next is old head
          pn->NextScorePtr = pl->STU_HeadPtr;
          //step 2 : old head prev is new node
          pl->STU_HeadPtr->PrevScorePtr = pn;
          //step 3 : assign new node as new head
          pl->STU_HeadPtr = pn;
       }
       else if(temp == NULL)//@ Tail
       {
          //step 1 : assign old tail as new node prev
          pn->PrevScorePtr = pl->STU_TailPtr;
          //step 2 : assign new node as old tail`s next
          pl->STU_TailPtr->NextScorePtr = pn;
          //step 3 : assign new node as new tail
          pl->STU_TailPtr = pn;
       }
        else // @ middle
        {
            pn->NextScorePtr = temp;
            pn->PrevScorePtr = temp->PrevScorePtr;
            temp->PrevScorePtr->NextScorePtr = pn;
            temp->PrevScorePtr = pn;
        }

     }
     pl->listSize++;
     printf("updated successfully\n");
}
//================================================================================================
//================================================================================================
Alpha_Student_Class* class_scoreList_search(List_of_Classes * pl,int STU_class)
{
   Alpha_Student_Class * temp = pl->Classlist_HeadPtr;
  while(temp!= NULL && STU_class != temp->Class_Num)
  {
      temp = temp->NextClassPtr;
  }
  return temp;
}
//================================================================================================
//================================================================================================
void update_sec_score(Alpha_Student_Class* pl)
{
    if(pl->STU_HeadPtr == NULL)//list is empty
    {
        printf("section is empty\n");
        return;
    }
   Student_Node * temp;
   for(temp= pl->STU_HeadPtr ;temp!= NULL;temp=temp->NextStudentPtr)
   {
        printf("\nEnter student score for %s ?\n",temp->studentName);
        scanf("%f",&score);
        update_student_score(temp,score);
   }
}
//================================================================================================
//================================================================================================
void rank_students(Alpha_Student_Class* pl)
{
    if(pl->STU_HeadPtr == NULL)//list is empty
    {
        printf("section is empty\n");
        return;
    }
   Student_Node * temp;
   for(temp= pl->STU_HeadPtr ;temp!= NULL;temp=temp->NextStudentPtr)
   {
        printf("\nthe score of student %s = (%f)\n",temp->studentName,temp->studentScore);
   }
}

//================================================================================================
//================================================================================================
