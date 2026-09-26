#include <iostream>
#include <string>

struct Node
{
    std::string Name, regNo, mail;
    int phNo;
    Node* next;
};

int main()
{
    int n;
    std::cout << "************Student Record Manager************" << '\n';
    std::cout << "Enter the number of student's record you want to enter : ";
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        std::cout << "\nEnter the Name of the student : ";
        std::getline(std::cin, newNode->Name);
        std::cout << "\nEnter the register number of the student : ";
        std::getline(std::cin, newNode->regNo);
        std::cout << "\nEnter the E-mail id of the student : ";
        std::getline(std::cin, newNode->mail);
        std::cout << "\nEnter the mobile number of the student : ";
        std::cin >> newNode->phNo;
        newNode->next = NULL;
    }
    return 0;
}