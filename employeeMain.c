//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
//gcc employeeMain.c employeeTable.c employeeTwo.c 
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhoneNumber);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Toney Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-111-1111");
    if(matchPtr != NULL)
        printf("Employee phone 714-111-1111 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee phone is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
    if(matchPtr != NULL)
        printf("Employee phone 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee phone is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 20.0);
    if(matchPtr != NULL)
        printf("Employee salary 20.0 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee salary is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL)
        printf("Employee salary 4.50 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee salary is NOT found in the record\n");
    
    return EXIT_SUCCESS;
}