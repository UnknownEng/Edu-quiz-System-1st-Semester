#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

// Defining all variables

int x = 0;
int j;
int i;
int totalMarks = 0;
const int MAX_QUESTIONS = 50;
const int MAX_OPTIONS_PER_QUESTION = 10;
string Q[MAX_QUESTIONS];
int optionsCount;
int marks[MAX_QUESTIONS];
int Question;
int correct_answer[MAX_QUESTIONS];
int answer;
int obt_marks = 0;
string question[MAX_QUESTIONS];
string option[MAX_QUESTIONS][MAX_OPTIONS_PER_QUESTION];
int response;
int responce;
int Quizo;

// defining Functions
void teacher();        // Function for teacher
void student();        // Function for Student
void result();         // Function for result
void quiz();           // Quiz function

// Main function
int main()
{
    cout << "Aslam o alaikum \n"
        << "welcome to Edu-Quiz System Made By \n "
        << "Unknown Engineer and M.Hashir \n "
        << "click 01 to Make New Quiz \n"
        << "click 02 to exit\n ";
    cin >> response;
    system("cls");
    if (response == 1)

    {
        cout << "click 01 for uni-Quiz \n"
            << "click 02 for multi-Quiz \n";
        cin >> responce;
        system("cls");
        if (responce == 1)
        {
            quiz();
            system("cls");
            return 0;
        }
        else if (responce == 2)
        {
            system("cls");
            cout << "how many Quiz You want to Take \n";
            cin >> Quizo;

            for (int i = 0; i < Quizo; i++)
            {
                system("cls");
                cout << "lets make Quiz No: " << i + 1 << endl;
                teacher();
            }

            for (int i = 0; i < Quizo; i++)
            {
                system("cls");
                cout << "lets take Quiz No: " << i + 1 << endl;
                student();
            }

            for (int i = 0; i < Quizo; i++)
            {
                system("cls");
                cout << "lets give the result of Quiz No: " << i + 1 << endl;
                result();
            }
        }
        else
        {
            cout << "Wrong response \n";
            cout << "closing system\n"
                << "first error cant be forgiven\n"
                << endl;
            system("cls");
            return 0;
        }
    }
    else if (response == 2)
    {
        system("pause");
        return 0;
    }
    else
    {
        cout << "wrong command \n";
        system("cls");
    }

    system("pause");
    return 0;
}

// Function for teacher
void teacher()
{
    system("cls");
    cout 	<< "Teacher's Turn \n"
			<< "lets start without delay \n"
            << "Please Enter How Many Questions You Want To Add In new Quiz \n";

    cin >> Question;
    cin.ignore();

    for (int i = 0; i < Question; i++)
    {
        system("cls");
        cout << "Enter the Marks of Question No: " << i + 1 << endl;
        cin >> marks[i];
        cin.ignore();

        cout << "Enter Question " << i + 1 << endl;
        getline(cin, Q[i]);
        question[i] = Q[i];

        cout << "Enter the Number Of Options you Want To Add in Question \n"
            << endl;
        cin >> optionsCount;
        cin.ignore();

        for (j = 0; j < optionsCount; j++)
        {
            cout << "Enter the option No: " << j + 1 << endl;
            getline(cin, option[i][j]);
        }

        cout << "Please write the correct option number (1, 2 ...)" << endl;
        cin >> correct_answer[i];

        if (correct_answer[i] < 1 || correct_answer[i] > optionsCount)
        {
            cout << "Invalid option number. Please enter a valid option." << endl;
            i--;
        }
    }
}

// Function for student
void student()
{
    system("cls");
    for (int i = 0; i < Question; i++)
    {
        cout << "Question No: " << i + 1 << " " << question[i] << endl;
        for (int j = 0; j < optionsCount; j++)
        {
            cout << option[i][j] << endl;
        }
        cout << "Please write Correct Option number (1, 2 ...)" << endl;
        cin >> answer;

        if (answer == correct_answer[i])
        {
            obt_marks += marks[i];
            x++;
        }
    }

    for (int i = 0; i < Question; i++)
    {
        totalMarks += marks[i];
    }
}

// Function for result
void result()
{
    system("cls");
    cout << "You obtained " << obt_marks << " marks " << endl
        << "Out of " << totalMarks << " marks " << endl
        << "Your Correct Answers Are  " << x << " and " << endl
        << "Your Wrong Answers Are " << Question - x << endl
        << "results are showed and now time to close \n";
    system("pause");
}

// Quiz function
void quiz()
{
    system("cls");
    cout << "Teacher Turn " << endl;
    teacher();
    system("cls");
    cout << "Student Turn " << endl;
    student();
    system("cls");
    cout << "So The Time Of Result is reached \n";
    result();
    system("cls");
    cout << "shutting down \n";
}
