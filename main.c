#include<stdio.h>
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
struct Student {
    int id;
    char name[50];
    char address[100];
    char contactNumber[15];
};
int main() 
{
    int choice;
    do {
        printf("=====================================");
        printf("\nWelcome to Hostel Management System\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("------------------\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                addStudent();//Calling Function to add student
                break;
            case 2:
                displayStudents();//Calling Function to display student
                break;
            case 3:
                searchStudent();//Calling Function to search student
                break;
            case 4:
                deleteStudent();//Calling Function to delete student
                break;
            case 5:
                printf("Exiting the program..ThankYou!!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
//Code For Adding New Student
    struct Student hostel[1000];
    int totalStudents = 0;
  void addStudent() {
    int select;
    printf("Choose Your Block:\n");
    printf("------------------\n");
    printf("1.A-Block(₹1l)\n2.B-Block(₹1.5l)\n3.C-Block(₹2l)\n4.D-Block(₹2.5l)\n");
    printf("------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &select);
    printf("------------------\n");
      if (totalStudents < 100) {
        
          printf("Enter Student ID: ");
          scanf("%d", &hostel[totalStudents].id);

          printf("Enter Student Name: ");
          scanf("%s", hostel[totalStudents].name);

          printf("Enter Student Address: ");
          scanf("%s", hostel[totalStudents].address);

          printf("Enter Student Contact Number: ");
          scanf("%s", hostel[totalStudents].contactNumber);

          totalStudents++;
          printf("Student added successfully!\n");
      } else {
          printf("Hostel is full. Cannot add more students.\n");
      }
  }
//Code For Displaying All Students
void displayStudents() 
{
    if (totalStudents == 0) 
    {
        printf("No students in the hostel.\n");
    } else
    {
        printf("\nStudent Information:\n");
        for (int i = 0; i < totalStudents; i++) {
            printf("ID: %d\n", hostel[i].id);
            printf("Name: %s\n", hostel[i].name);
            printf("Address: %s\n", hostel[i].address);
            printf("Contact Number: %s\n", hostel[i].contactNumber);
            printf("------------------------\n");
        }
    }
}
//Code For Searching Student
void searchStudent() 
{
    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < totalStudents; i++)
      {
        if (hostel[i].id == searchId) 
        {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", hostel[i].id);
            printf("Name: %s\n", hostel[i].name);
            printf("Address: %s\n", hostel[i].address);
            printf("Contact Number: %s\n", hostel[i].contactNumber);
            return;
        }
    }
    printf("Student with ID %d not found.\n", searchId);
}
void deleteStudent() 
{
  int deleteId;
  printf("Enter Student ID to delete: ");
  scanf("%d", &deleteId);
  for (int i = 0; i < totalStudents; i++) 
  {
      if (hostel[i].id == deleteId) 
      {
          for (int j = i; j < totalStudents - 1; j++) 
          {
              hostel[j] = hostel[j + 1];
          }
          totalStudents--;
          printf("Student with ID %d deleted successfully!\n", deleteId);
          return;
      }
  }
  printf("Student with ID %d not found. Deletion failed.\n", deleteId);
}