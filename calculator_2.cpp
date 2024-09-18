#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double num1, num2, result;
    char operation, choice='\0';

    cout << "Enter the first number: \n";
    cin >> num1;

    cout << "Enter the second number: \n";
    cin >> num2;

    cout << "Enter an operation (+, -, *, /): \n";
    cin >> operation;


    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':

            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error: Cannot divide by zero." << endl;

            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;

            break;
    }

       cout << num1 << " " << operation << " " << num2 << " = " << result << endl;

       return 0;
}
