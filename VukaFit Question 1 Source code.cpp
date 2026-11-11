
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Function to get non-empty text
string getRequiredText(string prompt)
{
    string value;

    do
    {
        cout << prompt;
        getline(cin, value);

        if (value.empty())
        {
            cout << "Error: This field cannot be empty.\n";
        }

    } while (value.empty());

    return value;
}

// Function to get a valid integer
int getInteger(string prompt)
{
    string input;
    int number;
    char extra;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> number && !(ss >> extra))
        {
            return number;
        }

        cout << "Error: Enter a valid whole number.\n";
    }
}

// Function to validate Yes or No
char getYesOrNo(string prompt)
{
    string answer;

    while (true)
    {
        cout << prompt;
        getline(cin, answer);

        if (answer.length() == 1)
        {
            char choice = toupper(answer[0]);

            if (choice == 'Y' || choice == 'N')
            {
                return choice;
            }
        }

        cout << "Error: Enter Y or N.\n";
    }
}

int main()
{
    // Membership prices
    const double BASIC_FEE = 220.00;
    const double ACTIVE_FEE = 350.00;
    const double WELLNESS_FEE = 480.00;
    const double ASSESSMENT_FEE = 180.00;

    string studentNumber, studentName;
    string membershipName;

    int membershipCode, months;

    double monthlyFee = 0;
    double subtotal, discountRate = 0;
    double discountAmount;
    double assessmentAmount = 0;
    double finalAmount;

    char assessmentChoice;

    cout << "====================================\n";
    cout << " VUKAFIT CAMPUS WELLNESS CENTRE\n";
    cout << " MEMBERSHIP QUOTATION\n";
    cout << "====================================\n";

    // Capture student details
    studentNumber = getRequiredText("Enter student number: ");
    studentName = getRequiredText("Enter full name: ");

    // Display membership options
    cout << "\nAvailable Memberships\n";
    cout << "1. Basic Access - R220.00\n";
    cout << "2. Active Plus - R350.00\n";
    cout << "3. Complete Wellness - R480.00\n";

    // Validate membership selection
    while (true)
    {
        membershipCode = getInteger("\nSelect membership (1-3): ");

        switch (membershipCode)
        {
        case 1:
            membershipName = "Basic Access";
            monthlyFee = BASIC_FEE;
            break;

        case 2:
            membershipName = "Active Plus";
            monthlyFee = ACTIVE_FEE;
            break;

        case 3:
            membershipName = "Complete Wellness";
            monthlyFee = WELLNESS_FEE;
            break;

        default:
            cout << "Invalid membership. Select 1, 2 or 3.\n";
            continue;
        }

        break;
    }

    // Validate number of months
    while (true)
    {
        months = getInteger("Enter number of months (1-6): ");

        if (months >= 1 && months <= 6)
        {
            break;
        }

        cout << "Invalid months. Enter between 1 and 6.\n";
    }

    // Fitness assessment selection
    assessmentChoice = getYesOrNo(
        "Add fitness assessment? (Y/N): ");

    // Calculate membership subtotal
    subtotal = monthlyFee * months;

    // Calculate discount
    if (months >= 3 && months <= 5)
    {
        discountRate = 0.07;
    }
    else if (months == 6)
    {
        discountRate = 0.12;
    }

    discountAmount = subtotal * discountRate;

    // Calculate optional assessment
    if (assessmentChoice == 'Y')
    {
        assessmentAmount = ASSESSMENT_FEE;
    }

    // Calculate final amount
    finalAmount = subtotal - discountAmount
        + assessmentAmount;

    // Display quotation
    cout << fixed << setprecision(2);

    cout << "\n====================================\n";
    cout << " VUKAFIT MEMBERSHIP QUOTATION\n";
    cout << "====================================\n";

    cout << "Student number: " << studentNumber << endl;
    cout << "Student name: " << studentName << endl;
    cout << "Membership: " << membershipName << endl;
    cout << "Months: " << months << endl;
    cout << "Monthly fee: R" << monthlyFee << endl;
    cout << "Subtotal: R" << subtotal << endl;
    cout << "Discount rate: " << discountRate * 100 << "%\n";
    cout << "Discount amount: R" << discountAmount << endl;

    cout << "Fitness assessment: "
        << (assessmentChoice == 'Y' ? "Yes" : "No")
        << endl;

    cout << "Assessment fee: R" << assessmentAmount << endl;

    cout << "------------------------------------\n";
    cout << "FINAL AMOUNT: R" << finalAmount << endl;
    cout << "====================================\n";

    cout << "Thank you for choosing VukaFit!\n";

    return 0;
}

