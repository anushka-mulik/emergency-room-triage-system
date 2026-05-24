#include <stdio.h>
#include "functions.h"

int main() {

    loadFromFile();

    int role = login();

    if(role == 0)
        return 0;

    int choice;

    while(1) {

        clearScreen();

        dashboard();

        printf("\n [1] Add Patient\n");

        printf(" [2] Display Patients\n");

        printf(" [3] Treat Patient\n");

        printf(" [4] Search Patient\n");

        printf(" [5] Exit\n");

        printf(" [6] Generate Emergency Report\n");

        printf("\nEnter Choice: ");


        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                treatPatient();
                break;

            case 4:
                searchPatient();
                break;

            case 5:

                printf(GREEN "\nExiting System...\n" RESET);

                return 0;

            case 6:
                generateReport();
                break;

            default:

                printf(RED "\nInvalid Choice!\n" RESET);
        }

        printf("\nPress Enter To Continue...");
        getchar();
        getchar();
    }

    return 0;
}