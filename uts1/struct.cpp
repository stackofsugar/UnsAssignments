#include <stdio.h>

typedef struct {
    char name[100];
    int age;
} Person;

void fillPerson(Person *myPs, int size){
    printf("Please enter the name of %d. person: ", size);
    scanf("%s", myPs[size].name);
    printf("Enter the age: ");
    scanf("%d", &myPs[size].age);
    printf("\n");
}

void printPerson(Person *myPs, int size){
    printf("%s, %d\n", myPs[size].name, myPs[size].age);
}

int main() {
    int opcode;
    Person person[3];
    printf("-- Passenger Registration Program --\n");

    while (1 == 1){
        printf("  1) Fill Array \n  2) Print Array \n  3) Exit \nSelect an operation: ");
        scanf("%d", &opcode);

        if (opcode == 1){
            fillPerson(person, 0);
            fillPerson(person, 1);
            fillPerson(person, 2);
        }
        else if (opcode == 2){
            printPerson(person, 0);
            printPerson(person, 1);
            printPerson(person, 2);
        }
        else {
            break;
        }
    }
}