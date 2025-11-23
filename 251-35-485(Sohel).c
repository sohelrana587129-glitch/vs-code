#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to store patient information
typedef struct
{
    int id;
    char name[51];
    char diagnosis[41];
    int age;
} Patient;

// Function prototypes
void displayAllPatients();
void searchPatientByID(int patientID);
void addNewPatient();

// Helper function to remove newline character from fgets input
void removeNewline(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

// ============================================================================
// TASK 1: Display All Patient Records (5 Points)
// ============================================================================
// HINTS:
// 1. Open "patients.txt" in read mode using fopen()
// 2. Check if file pointer is NULL (file opening failed)
// 3. Print the table header with proper formatting
// 4. Use a Patient structure variable to read each record
// 5. Don't forget to close the file with fclose()
// ============================================================================

void displayAllPatients()
{
    // TODO: Implement this function
    FILE *file_one = fopen("patients.txt", "r");
    if(file_one == NULL){
        printf("File Open unseccesfull");
                return;
    }
    Patient patient;
    char line[1000];
     printf("================================================================================\n");
    printf("%-7s %-25s %-25s %-3s\n", "ID", "Name", "Diagnosis", "Age");
    printf("================================================================================\n");

    while(fgets(line, 1000, file_one)){


        if(sscanf(line, "%d|%[^|]|%[^|]|%d" , &patient.id, patient.name, patient.diagnosis, &patient.age)){ //likhle hoy nah kn;

        printf("%-7d %-25s %-25s %-3d\n", patient.id, patient.name, patient.diagnosis, patient.age);
    }
}
//    while(fscanf(file_one, "%d %s %s %d", &Patient.id, typedef(struct.Patient.name), typedef(Patient.diagnosis), &Patient.age)){
//        printf("%d %s %s %d", Patient.id, Patient.name, Patient.diagnosis, Patient.age);
//    }
    fclose(file_one);

}

// ============================================================================
// TASK 2: Search Patient by ID (5 Points)
// ============================================================================
// HINTS:
// 1. Open "patients.txt" in read mode
// 2. Check if file opened successfully
// 3. Create a Patient structure variable to store each record
// 4. Compare each patient's ID with the patientID parameter
// 5. If match found:
//    - Print "Patient Found:" and display all details
//    - Close file and return from function
// 6. If loop ends without finding the patient:
//    - Print "Patient with ID [patientID] not found."
// 7. Close the file
// ============================================================================

void searchPatientByID(int patientID)
{
    // TODO: Implement this function
    FILE *file_one =fopen("patients.txt", "r");
    if(file_one == NULL){
        printf("File Open Unsuccessfully");
        return;
    }
    Patient patient;
    char line[1000];
    int found = 0;
     printf("================================================================================\n");
    printf("%-7s %-25s %-25s %-3s\n", "ID", "Name", "Diagnosis", "Age");
    printf("================================================================================\n");

    while(fgets(line, 1000, file_one)){


        if(sscanf(line, "%d|%[^|]|%[^|]|%d" , &patient.id, patient.name, patient.diagnosis, &patient.age)){ //likhle hoy nah kn;
                if(patient.id == patientID){
                    printf("Patient Found: \n");
                    printf("ID: %d\n", patient.id);
                    printf("Name: %s\n", patient.name);
                    printf("Diagnosis: %s\n", patient.diagnosis);
                    printf("Age: %d\n", patient.age);
                    found = 1;
                    break;
                }
            }

}
}

// ============================================================================
// TASK 3: Add New Patient Record (5 Points)
// ============================================================================
// HINTS:
// 1. Create a Patient structure variable
// 2. Prompt user: "Enter Patient ID: " and use scanf() to read integer
// 3. Use getchar() to consume the newline left by scanf()
// 4. Prompt user: "Enter Patient Name: " and use fgets() to read string
// 5. Call removeNewline() function to clean the name string
// 6. Prompt user: "Enter Diagnosis: " and use fgets() to read string
// 7. Call removeNewline() function to clean the diagnosis string
// 8. Prompt user: "Enter Age: " and use scanf() to read integer
// 9. Open "patients.txt" in APPEND mode ("a") - this adds to end without deleting
// 10. Check if file opened successfully
// 11. Use fprintf() to write: fprintf(file, "%d|%s|%s|%d\n", ...)
// 12. Print "Patient record added successfully!"
// 13. Close the file
// ============================================================================

void addNewPatient()
{
    // TODO: Implement this function
     FILE *file_one;
     Patient patient;
     printf("Enter patient ID: ");
     scanf("%d", &patient.id);

     getchar();

     printf("Enter patient Name: ");
     fgets(patient.name, 51, stdin);

     printf("Enter patient  Diagnosis: ");
     fgets(patient.diagnosis, 41, stdin);

     printf("Enter patient age: ");
     scanf("%d", &patient.age);

     file_one = fopen("patients.txt", "a");

     if(file_one == NULL){
        printf("File Open Unsuccessfully");
        return;
    }
    fprintf(file_one, "%d|%s|%s|%d\n", patient.id, patient.name, patient.diagnosis, patient.age);
    printf("patient record added successfully!\n");

    fclose(file_one);



}

// ============================================================================
// MAIN FUNCTION - DO NOT MODIFY THIS
// ============================================================================
int main()
{
    int choice, patientID;

    printf("========================================\n");
    printf("   HOSPITAL PATIENT MANAGER\n");
    printf("========================================\n\n");

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Display All Patient Records\n");
        printf("2. Search Patient by ID\n");
        printf("3. Add New Patient Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n");
            displayAllPatients();
            break;

        case 2:
            printf("Enter Patient ID to search: ");
            scanf("%d", &patientID);
            printf("\n");
            searchPatientByID(patientID);
            break;

        case 3:
            printf("\n--- Add New Patient Record ---\n");
            addNewPatient();
            break;

        case 4:
            printf("\nThank you for using the Hospital Patient Manager!\n");
            printf("Goodbye!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
