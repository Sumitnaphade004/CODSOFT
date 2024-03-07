#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char opp;

    cout << "Enter the Operator (+ - * / ): ";
    cin >> opp;

    cout << "Enter the two numbers one by one : ";
    cin >> num1 >> num2;

    switch (opp)
    {
    case '+':  //addition
       cout << num1 << opp << num2 << " = " << num1 + num2 << endl;
        break;

    case '-':  //substraction
       cout << num1 << opp << num2 <<  " = " << num1 - num2 << endl;
        break;

        case '*': //multiplication
       cout << num1 << opp << num2 <<  " = " << num1 * num2 << endl;
        break;

        case '/': //division
         if (num2 == 0.0)
         {
            cout << "Divide by zero"<< endl;
         }
         else 
         {
            cout << num1 << opp << num2 << " = " << num1 / num2 << endl;
         }
        break;

        default:
         cout << " Invalid Operator" <<endl;
    }

}