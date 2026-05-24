#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX 100

// COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// PATIENT STRUCTURE
struct Patient {

    int id;
    char name[50];
    int age;
    char disease[100];
    int severity;

    int arrivalOrder;
};

// GLOBAL VARIABLES
extern struct Patient heap[MAX];
extern int size;

// FUNCTIONS
void clearScreen();

void dashboard();

int login();

void addPatient();

void displayPatients();

void treatPatient();

void searchPatient();

void saveToFile();

void loadFromFile();

void heapifyUp(int i);

void heapifyDown(int i);

#endif