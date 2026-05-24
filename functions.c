#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct Patient heap[MAX];
int size = 0;

int arrivalCounter = 0;

// CLEAR SCREEN
void clearScreen() {

    system("cls");
}

// SWAP
void swap(struct Patient *a, struct Patient *b) {

    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

// HEAPIFY UP
void heapifyUp(int i) {

    while(i > 0 && (

        heap[(i - 1)/2].severity < heap[i].severity ||

       (heap[(i - 1)/2].severity == heap[i].severity &&
        heap[(i - 1)/2].arrivalOrder > heap[i].arrivalOrder)

    )) {

        swap(&heap[(i - 1)/2], &heap[i]);

        i = (i - 1)/2;
    }
}

// HEAPIFY DOWN
void heapifyDown(int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && (

       heap[left].severity > heap[largest].severity ||

      (heap[left].severity == heap[largest].severity &&
       heap[left].arrivalOrder < heap[largest].arrivalOrder)

    )) {

        largest = left;
    }

    if(right < size && (

       heap[right].severity > heap[largest].severity ||

      (heap[right].severity == heap[largest].severity &&
       heap[right].arrivalOrder < heap[largest].arrivalOrder)

    )) {

        largest = right;
    }

    if(largest != i) {

        swap(&heap[i], &heap[largest]);

        heapifyDown(largest);
    }
}

// SAVE TO FILE
void saveToFile() {

    FILE *fp = fopen("patients.txt", "w");

    if(fp == NULL) {

        printf("File Error!\n");
        return;
    }

    for(int i = 0; i < size; i++) {

        fprintf(fp,
                "%d,%s,%d,%s,%d,%d\n",

                heap[i].id,
                heap[i].name,
                heap[i].age,
                heap[i].disease,
                heap[i].severity,
                heap[i].arrivalOrder);
    }

    fclose(fp);
}

// LOAD FROM FILE
void loadFromFile() {

    FILE *fp = fopen("patients.txt", "r");

    if(fp == NULL)
        return;

    while(fscanf(fp,
          "%d,%49[^,],%d,%99[^,],%d,%d\n",

          &heap[size].id,
          heap[size].name,
          &heap[size].age,
          heap[size].disease,
          &heap[size].severity,
          &heap[size].arrivalOrder) == 6) {

        size++;
    }

    arrivalCounter = size;

    fclose(fp);
}

// DASHBOARD
void dashboard() {

    printf(BLUE);
    printf("\n====================================================\n");
    printf("          EMERGENCY ROOM TRIAGE SYSTEM\n");
    printf("====================================================\n");
    printf(RESET);

    printf(GREEN "Patients in Queue : %d\n" RESET, size);

    if(size > 0) {

        printf(RED "Highest Priority  : %s\n" RESET,
               heap[0].name);

        printf(YELLOW "Severity Level    : %d\n" RESET,
               heap[0].severity);
    }
    else {

        printf("No patients waiting\n");
    }

    printf(BLUE "====================================================\n" RESET);
}

// LOGIN
int login() {

    char user[20];
    char pass[20];

    printf("\n=========== LOGIN SYSTEM ===========\n");

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    if(strcmp(user, "doctor") == 0 &&
       strcmp(pass, "1234") == 0) {

        printf(GREEN "\nDoctor Login Successful!\n" RESET);

        return 1;
    }

    if(strcmp(user, "nurse") == 0 &&
       strcmp(pass, "1234") == 0) {

        printf(YELLOW "\nNurse Login Successful!\n" RESET);

        return 2;
    }

    printf(RED "\nLogin Failed!\n" RESET);

    return 0;
}

// ADD PATIENT
void addPatient() {

    if(size >= MAX) {

        printf(RED "\nQueue Full!\n" RESET);
        return;
    }

    struct Patient p;

    printf(BLUE "\n=========== ADD NEW PATIENT ===========\n" RESET);

    printf("Enter ID: ");
    scanf("%d", &p.id);

    getchar();

    printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &p.age);

    getchar();

    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    printf("Enter Severity (1-5): ");
    scanf("%d", &p.severity);

    p.arrivalOrder = arrivalCounter++;

    heap[size] = p;

    heapifyUp(size);

    size++;

    saveToFile();

    if(p.severity == 5) {

        printf(RED "\n!!! CRITICAL EMERGENCY ALERT !!!\n" RESET);
    }

    printf(GREEN "\nPatient Added Successfully!\n" RESET);
}

// DISPLAY PATIENTS
void displayPatients() {

    if(size == 0) {

        printf(RED "\nNo Patients Available!\n" RESET);
        return;
    }

    printf(BLUE "\n=============================================================================\n" RESET);

    printf(BLUE " ID\tNAME\t\tAGE\tSEVERITY\tARRIVAL\tDISEASE\n" RESET);

    printf(BLUE "=============================================================================\n" RESET);

    for(int i = 0; i < size; i++) {

        printf(" %d\t%-15s\t%d\t%d\t\t%d\t\t%s\n",

               heap[i].id,
               heap[i].name,
               heap[i].age,
               heap[i].severity,
               heap[i].arrivalOrder,
               heap[i].disease);
    }

    printf(BLUE "=============================================================================\n" RESET);
}

// TREAT PATIENT
void treatPatient() {

    if(size == 0) {

        printf(RED "\nNo Patients Available!\n" RESET);
        return;
    }

    printf(RED "\n=========== TREATING PATIENT ===========\n" RESET);

    printf("ID       : %d\n", heap[0].id);

    printf("Name     : %s\n", heap[0].name);

    printf("Severity : %d\n", heap[0].severity);

    heap[0] = heap[size - 1];

    size--;

    heapifyDown(0);

    saveToFile();

    printf(GREEN "\nPatient Treated Successfully!\n" RESET);
}

// SEARCH PATIENT
void searchPatient() {

    int id;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < size; i++) {

        if(heap[i].id == id) {

            printf(GREEN "\n=========== PATIENT FOUND ===========\n" RESET);

            printf("ID        : %d\n", heap[i].id);

            printf("Name      : %s\n", heap[i].name);

            printf("Age       : %d\n", heap[i].age);

            printf("Disease   : %s\n", heap[i].disease);

            printf("Severity  : %d\n", heap[i].severity);

            printf("Arrival   : %d\n", heap[i].arrivalOrder);

            return;
        }
    }

    printf(RED "\nPatient Not Found!\n" RESET);
}