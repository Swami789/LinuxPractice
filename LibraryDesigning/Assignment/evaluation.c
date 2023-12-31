#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void *(*iterator)(void *), /*Iterator function callback*/
        int (*comparator)(void *, void *),
        void *(*get_app_data)(void *)); /*Comparison function callback*/


/*Application specific data structures*/
typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


/*Step 2 : Implement list iterator function here*/
/*Now write an iterator function called "void* list_iterator (void *list_node)" in evaluation.c file. 
which takes an input a pointer to node of a linked list, and return the pointer to next node. 
Signature of function should be generic as below. Handle NULL cases.*/
void* list_iterator (void *list_node){

    /*write your code here*/
    if (!list_node) {
     return NULL;
    } else {
        dll_node_t *node = (dll_node_t *)list_node;
        return (void *)node->right;
    }
}

/*Step 3 : implement student comparator function here*/
/*Write a comparator function called "int student_comparator (void *_studentobj1, void *_studentobj2)" in 
evaluation.c file which takes an input the pointer to objects of type student_t and return 0 if two objects are equal , 
otherwise -1. The signature of function should be generic as below :
*/

int student_comparator (void *_studentobj1, void *_studentobj2){

    student_t *studentobj1 = (student_t *)_studentobj1;
    student_t *studentobj2 = (student_t *)_studentobj2;

    /*Write your code here*/
    if(!studentobj1 && !studentobj2)
        return 0;
    else if(!studentobj1 && studentobj2)
        return -1;
    else if(studentobj1 && !studentobj2)
        return -1;

    if ((strcmp(studentobj1->name, studentobj2->name) == 0) &&
    (studentobj1->year_of_birth == studentobj2->year_of_birth) &&
    (studentobj1->height == studentobj2->height) && 
    (studentobj1->weight == studentobj2->weight) &&
    (studentobj1->total_marks == studentobj2->total_marks)) {
        return 0;
    } else {
        return -1;
    }
} 

/*Step 4 : implement get_app_data_from_list_node function*/
/*Write a function called "void * get_app_data_from_list_node(void *list_node)" in file evaluation.c 
which takes an input the pointer to node of linked list and return the object to data held by the node of the linked list.*/
void*
get_app_data_from_list_node(void *list_node){

    /*Write your code here*/
    if (!list_node) {
        return NULL;
    } else {
        dll_node_t *node = (dll_node_t *)list_node;
        return (void *)node->data;
    }
}


int
main(int argc, char **argv){

    /*Student database list 1*/
    student_t *student1 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->year_of_birth = 2000;
    student1->height = 167;
    student1->weight = 80;
    student1->total_marks = 90;

    student_t *student2 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student2->name, "Sagar", strlen("Sagar"));
    student2->year_of_birth = 2001;
    student2->height = 170;
    student2->weight = 82;
    student2->total_marks = 80;

    student_t *student3 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student3->name, "Vineet", strlen("Vineet"));
    student3->year_of_birth = 2002;
    student3->height = 161;
    student3->weight = 62;
    student3->total_marks = 72;

    student_t *student4 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student4->name, "Neeraj", strlen("Neeraj"));
    student4->year_of_birth = 1998;
    student4->height = 167;
    student4->weight = 76;
    student4->total_marks = 67;


    dll_t *student_db1 = get_new_dll();
    add_data_to_dll(student_db1, student1);
    add_data_to_dll(student_db1, student2);
    add_data_to_dll(student_db1, student3);
    add_data_to_dll(student_db1, student4);


    /*Student database list 2*/
    student_t *student5 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student5->name, "Abhishek", strlen("Abhishek"));
    student5->year_of_birth = 2000;
    student5->height = 167;
    student5->weight = 80;
    student5->total_marks = 90;

    student_t *student6 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student6->name, "Sagar", strlen("Sagar"));
    student6->year_of_birth = 2001;
    student6->height = 170;
    student6->weight = 82;
    student6->total_marks = 80;

    student_t *student7 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student7->name, "Vineet", strlen("Vineet"));
    student7->year_of_birth = 2002;
    student7->height = 161;
    student7->weight = 62;
    student7->total_marks = 72;

    student_t *student8 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student8->name, "Neeraj", strlen("Neeraj"));
    student8->year_of_birth = 1998;
    student8->height = 167;
    student8->weight = 76;
    student8->total_marks = 67;

    dll_t *student_db2 = get_new_dll();
    add_data_to_dll(student_db2, student5);
    add_data_to_dll(student_db2, student6);
    add_data_to_dll(student_db2, student7);
    add_data_to_dll(student_db2, student8);

    /*Step 6*/

    if(diff((void *)student_db1->head, (void *)student_db2->head, list_iterator, student_comparator, get_app_data_from_list_node) == 0)
        printf("Data sructures are equal\n");
    else
        printf("Data sructures are not equal\n");
    return 0;
}
