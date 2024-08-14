/*
 ============================================================================
 Name        : school.c
 Author      : BISHOY KAMEL
 Version     : 1
 Copyright   : Your copyright notice
 Description : Source file for the project
 ============================================================================
 */

/*******************************************************************************
 *                                  Inclusions                                  *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "school.h"

/*******************************************************************************
 *                              Global Variables	                            *
 *******************************************************************************/

/* global pointer to structure to make the linked-list */
student *studentList = NULL;

/*******************************************************************************
 *                             Functions definition                             *
 *******************************************************************************/

void welcome(void) {
	printf("###############################################################\n");
	printf("###############################################################\n");
	printf("##          Welcome to our School Management System          ##\n");
	printf("###############################################################\n");
	printf("###############################################################\n");
}

int pass(void) {
	int trials = 3;
	for (int i = 0; i < 3; i++) {
		printf("Please Enter Password: ");
		scanf("%d", &password);
		printf("\n");
		if (password == 1234) {
			return 1;
		} else {
			trials--;
			printf("You have %d trials left...\n", trials);
		}
	}
	printf("\nRestart the program,the system is updating...\n\n");
	return 0;
}

void menu(void) {
	int n, id;
	printf("\nMenu Options: \n");

	printf("1) Add a Student\n");
	printf("2) Display All Students\n");
	printf("3) Search for a Student by ID\n");
	printf("4) Update Student Information\n");
	printf("5) Delete a Student\n");
	printf("6) Calculate Average GPA\n");
	printf("7) Find Student with Highest GPA\n");
	printf("8) Exit\n");
	printf("Enter Choice: \n");
	scanf("%d", &n);
	printf("\n");

	switch (n) {
	case 1: {
		student *newStudent = (student*) malloc(sizeof(student));
		if (newStudent != NULL) {
			printf("Enter new Student information: \n");
			printf("Enter Student Name: \n");
			scanf("%s", newStudent->name);
			printf("Enter Student ID: \n");
			scanf("%d", &newStudent->id);
			printf("Enter Student Age: \n");
			scanf("%d", &newStudent->age);
			printf("Enter Student GPA: \n");
			scanf("%f", &newStudent->gpa);
			printf("\n");
			addStudent(newStudent);
		} else {
			printf("Memory allocation failed.\n");
		}
		break;
	}

	case 2:
		displayStudents();
		break;

	case 3:
		printf("Enter Student ID: ");
		scanf("%d", &id);
		searchStudentByID(id);
		break;

	case 4:
		printf("Enter Student ID: ");
		scanf("%d", &id);
		updateStudent(id);
		break;

	case 5:
		printf("Enter Student ID: ");
		scanf("%d", &id);
		deleteStudent(id);
		break;

	case 6:
		printf("Average GPA = %f\n", calculateAverageGPA());
		break;

	case 7:
		searchHighestGPA();
		break;

	case 8:
		printf("Exiting the program...\n");
		exit(0);

	default:
		printf(
				"You may have some errors while using the program ,Loading...\n\n");
	}
	printf("\n");
	printf("###############################################################\n");
	printf("###############################################################\n");
}

void addStudent(const struct student *const ptr) {

	student *current = studentList;

	while (current != NULL) {
		if (current->id == ptr->id) {
			printf("\nStudent with ID: %d ,already exists.\n", ptr->id);
			free(ptr);
			return;
		}
		current = current->next;
	}

	if (studentList == NULL) {
		studentList = ptr;
		printf("Student record added successfully.\n");
		return;
	} else {

		current = studentList;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = ptr;
	}
	printf("Student record added successfully.\n");
}

void displayStudents(void) {
	if (studentList == NULL) {
		printf("No students yet.\n");
		return;
	}

	student *current = studentList;

	while (current != NULL) {
		printf("Student Name: %s\n", current->name);
		printf("Student ID: %d\n", current->id);
		printf("Student Age: %d\n", current->age);
		printf("Student GPA: %f\n\n", current->gpa);

		current = current->next;
	}

}

void searchStudentByID(int id) {
	if (studentList == NULL) {
		printf("No students yet.\n");
		return;
	}

	student *current = studentList;

	while (current != NULL) {
		if (current->id == id) {
			printf("Student Name: %s\n", current->name);
			printf("Student ID: %d\n", current->id);
			printf("Student Age: %d\n", current->age);
			printf("Student GPA: %f\n\n", current->gpa);
			return;
		}
		current = current->next;
	}
	printf("Student not found.\n");
}

void updateStudent(int id) {
	if (studentList == NULL) {
		printf("No students yet.\n");
		return;
	}

	student *current = studentList;

	while (current != NULL) {
		if (current->id == id) {
			printf("Student Name : %s\n", current->name);
			printf("Student ID: %d\n", current->id);
			printf("Student Age: %d\n", current->age);
			printf("Student GPA: %f\n\n", current->gpa);
			printf("Enter Student edited information: \n");
			printf("Name: ");
			scanf("%s", current->name);
			printf("Age: ");
			scanf("%d", &current->age);
			printf("GPA: ");
			scanf("%f", &current->gpa);
			return;
		}
		current = current->next;
	}

	printf("Student not found.\n");
}

void deleteStudent(int id) {
	student *current = NULL;
	student *prev = NULL;
	student *delete_node = NULL;

	if (studentList == NULL) {
		printf("No students yet.\n");
		return;
	}

	if (studentList->id == id) {
		delete_node = studentList;
		studentList = studentList->next;
		printf("ID: %d ,Found and deleted \n", id);
		free(delete_node);
		return;
	}

	current = studentList->next;
	prev = studentList;
	while (current != NULL) {
		if (current->id == id) {
			delete_node = current;
			prev->next = current->next;
			printf("ID: %d ,Found and deleted \n", id);
			free(delete_node);
			return;
		}
		prev = current;
		current = current->next;
	}

	if (delete_node == NULL) {
		printf("ID: %d not found.", id);
	}
}

float calculateAverageGPA(void) {
	float average = 0;
	int count = 0;
	float sum = 0;
	if (studentList == NULL) {
		printf("No students yet.\n");
		return 0;
	}

	student *current = studentList;

	while (current != NULL) {
		sum += current->gpa;
		current = current->next;
		count++;
	}
	average = sum / count;
	return average;
}

void searchHighestGPA(void) {
	if (studentList == NULL) {
		printf("No students yet.\n");
		return;
	}

	student *maxptr = studentList;
	student *current = studentList->next;

	while (current != NULL) {
		if (maxptr->gpa < current->gpa) {
			maxptr->gpa = current->gpa;
		}
		current = current->next;
	}
	printf("Student with Highest GPA: \n");
	printf("Student Name : %s\n", maxptr->name);
	printf("Student ID: %d\n", maxptr->id);
	printf("Student Age: %d\n", maxptr->age);
	printf("Student GPA: %f\n\n", maxptr->gpa);
}
