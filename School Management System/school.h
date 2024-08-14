/*
 ============================================================================
 Name        : school.h
 Author      : BISHOY KAMEL
 Version     : 1
 Copyright   : Your copyright notice
 Description : Header file for the project
 ============================================================================
 */

#ifndef SCHOOL_H_
#define SCHOOL_H_

/*******************************************************************************
 *                              Global Variables	                            *
 *******************************************************************************/

static int password = 1234;

#define maxNameChar 20

/* define the boolean data type */
typedef enum {
	False = 0, True = 1
} bool;

/* structure for Student data */
typedef struct student {
	char name[maxNameChar];
	int id;
	int age;
	float gpa;
	struct student *next;
} student;

/* global pointer to structure to make the linked-list */
extern student *studentList;

/*******************************************************************************
 *                              Functions Prototypes                            *
 *******************************************************************************/

/* welcome screen.*/
void welcome(void);


/* password for the system.*/
int pass(void);


/*• Add a Student: Prompts the user for new student details and adds them to the system.
  • Display All Students: Shows a list of all stored student records.
  • Search for a Student by ID: Allows the user to find a specific student using their unique ID.
  • Update Student Information: Facilitates the updating of details for an
    existing student identified by their ID.
  • Delete a Student: Removes a student's record based on their ID.
  • Calculate Average GPA: Computes and displays the average GPA of all students.
  • Find Student with Highest GPA: Identifies and displays the student with the highest GPA.
  • Exit: Terminates the program.*/
void menu(void);


/*• It adds a new student to the linked list. It first checks if the student's ID already exists.
  • If the ID exists, it prints an error message and returns. If the ID does not exist,
    it attempts to allocate memory for a new node.
  • If memory allocation fails, it prints an error message and returns.
  • If memory allocation is successful, it copies the student data to the new
    node and adds the node to the end of the linked list.*/
void addStudent(const struct student *const ptr);


/*• Displays all students in the linked list.
  • If the list is empty, it prints a message indicating no students are present.
    Otherwise, it traverses the list and prints the details of each student.*/
void displayStudents(void);


/*• It searches for a student by their ID in the linked list.
  • If the student is found, it prints their details.
  • If the student is not found, it prints a message indicating the student was not found.*/
void searchStudentByID(int id);


/*• Updates the details of a student with a given ID in the linked list.
  • If the student is found, then update the student's information (student name, age, GPA).
  • If the student is not found, it prints a message indicating the student was not found.*/
void updateStudent(int id);


/*• Calculates and returns the average GPA of all students in the linked list.
  • It traverses the list to sum the GPAs of all students and counts the number of students.
  • If the list is empty, it returns 0.0.
  • Otherwise, it computes and returns the average GPA by dividing the total
    sum of GPAs by the number of students.*/
float calculateAverageGPA(void);


/*• Searches for the student with the highest GPA in the linked list.
  • It traverses the list, keeping track of the student with the highest GPA encountered.
  • If the list is empty, it prints a message indicating that there are no students.
  • After finding the student with the highest GPA, it prints the details of that student.*/
void searchHighestGPA(void);


/*• Iterates through the linked list of students starting with the Head of it to
    find the student with the given ID.
  • If the student is found, it adjusts the pointers to remove the node from the
    list, frees the memory allocated for the node, and prints a success message.
  • If the student is not found, it prints a message indicating the student was ot found.*/
void deleteStudent(int id);


#endif /* SCHOOL_H_ */
