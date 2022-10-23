#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <string.h>

int main()
{
    Student_Node* STU_temp;
    Alpha_Student_Class* temp ;
    float STU_score;
    char STU_Name[30],STU_Address[30],STU_phoneNumber[12];
    int class_Choice,STU_ID ,class_num ,sec_num,Update_index ;
    List_of_Classes CLASSES_LIST ;
    Create_ListOfClasses_list(&CLASSES_LIST);
    //List_of_Classes CLASS_score_LIST ;
    Create_ListOfClasses_list(&CLASS_score_LIST);
    Init_function();

    while(1)
    {
        Select_What_to_Edit();
        switch(Fun_to_edit)
        {
            case Create_New_class:
                printf("which class do u want add section to it?\nEnter\t(1)to add to first preparatory\n\t");
                printf("(2)to add to second preparatory\n\t(3)to add to third preparatory\n");
                scanf("%d",&class_Choice);
                insert_list(&CLASSES_LIST,class_Choice,1);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Add_New_Student:
			    fflush(stdin);
                printf("\nEnter student name ?\n");
                gets(STU_Name);
                printf("\nEnter student address ?\n");
                gets(STU_Address);
                printf("\nEnter student phone number ?\n");
                gets(STU_phoneNumber);
                printf("\nEnter student id ?\n");
                scanf("%d",&STU_ID);
                printf("\nEnter student class ?\n");
                scanf("%d",&class_num);
                printf("\nEnter student sec ?\n");
                scanf("%d",&sec_num);
                temp = classList_search(&CLASSES_LIST,class_num,sec_num);
                insert_student(temp,STU_Name,STU_Address,STU_phoneNumber,STU_ID,class_num,sec_num);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Delete_Student:
                printf("\nEnter student id ?\n");
                scanf("%d",&STU_ID);
                printf("\nEnter student class ?\n");
                scanf("%d",&class_num);
                printf("\nEnter student sec ?\n");
                scanf("%d",&sec_num);
                temp = classList_search(&CLASSES_LIST,class_num,sec_num);
                delete_StudentNode(temp,STU_ID);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Update_Student_Data://update class & section late
			    printf("\nwhich student?(enter his id)");
			    scanf("%d",&STU_ID);
                printf("\nEnter student class ?\n");
                scanf("%d",&class_num);
                printf("\nEnter student sec ?\n");
                scanf("%d",&sec_num);
                temp = classList_search(&CLASSES_LIST,class_num,sec_num);

                printf("which data do u to update?\nEnter\t(0)to update name\n\t");
                printf("(1)to update address\n\t(2)to update phone number\n\t(3)to update ID\n");
                scanf("%d",&data_index);
                fflush(stdin);
                update_StudentData(temp,STU_ID);
                printf("\nupdated successfully\n");
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Print_Section_List:
                printf("\nEnter class number ?\n");
                scanf("%d",&class_num);
                printf("\nEnter sec number ?\n");
                scanf("%d",&sec_num);
                temp = classList_search(&CLASSES_LIST,class_num,sec_num);

                printf("which data do u to want to print of student?\nEnter\t(0)to print name\n\t");
                printf("(1)to print address\n\t(2)to print phone number\n\t(3)to print ID\n\t(4)to print all\n");
                scanf("%d",&data_index);
                print_StudentSection(temp);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Print_Student_Data:
                printf("\nEnter student id ?\n");
                scanf("%d",&STU_ID);
                STU_temp = search_StudentNode2( &CLASSES_LIST,STU_ID);
                print_studentData(STU_temp);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
			case Print_School_List:
                print_AllStudents( &CLASSES_LIST);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
            case Update_SectionOfstudents_score:
                printf("\nEnter class number ?\n");
                scanf("%d",&class_num);
                printf("\nEnter sec number ?\n");
                scanf("%d",&sec_num);
                temp = classList_search(&CLASSES_LIST,class_num,sec_num);
                update_sec_score(temp);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
            case Update_student_score:
                printf("\nEnter student id ?\n");
                scanf("%d",&STU_ID);
                STU_temp = search_StudentNode2( &CLASSES_LIST,STU_ID);
                printf("\nEnter student score ?\n");
                scanf("%f",&STU_score);
                update_student_score(STU_temp,STU_score);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
				break;
//============================================================================================================
//============================================================================================================
            case Rank_students:
                printf("\nEnter class number ?\n");
                scanf("%d",&class_num);
                temp = class_scoreList_search(&CLASS_score_LIST,class_num);
                rank_students(temp);
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
                break;
//============================================================================================================
//============================================================================================================
                case EXIT:
                printf("//============================================================================================================");
                printf("\n//============================================================================================================\n");
                return 0;
                break;
       }
    }
return 0;
}
