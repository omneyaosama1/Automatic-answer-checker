// automatic answer checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// 
//Year one project
//DATE: 2/1/2023


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

string firstName, lastName;

void questionbank(int n_q) //Total no of questions
{

    char question[100], answer[100];

    int x;

    ofstream questions("questions.txt");

    ofstream answers("Model answers.txt");


    if (n_q > 100)
    {
        cout << "Too many questions, Your limit is 100 questions only." << endl;

        cout << "Try again!" << endl;

        cout << "How many questions do you want to put in the exam?" << endl;

        cin >> n_q;

        questionbank(n_q); //incase of another wrong input
    }
    else if (n_q <= 100)
    {
        cin.ignore(1, '\n');

        for (int i = 0; i < n_q; i++)
        {
            cout << "Enter the question here: " << endl;

            cin.getline(question, 500);

            questions << question << endl;

            cout << "Enter the answer here: " << endl;

            cin.getline(answer, 500);

            answers << answer << endl;

        }
        cout << "Done! Thank you." << endl;
    }
    questions.close();

    answers.close();
}


void check2(string username, string password) //to check the doctor's creds.
{

    //username is admin and password is 1234

    string L1, L2;

    string reply1, reply2, reading;

    int n_q;

    ifstream read("Scores.txt");

    ifstream credentials("credentials.txt");

    getline(credentials, L1);

    getline(credentials, L2);

    string y;
    if (username == L1 && password == L2)
    {
        cout << "Do you want to create an exam?" << endl;

        cin >> reply1;

        if (reply1 == "yes")
        {
            cout << "How many questions do you want in the exam?" << endl;

            cin >> n_q;
            questionbank(n_q);
        }
        else if (reply1 == "no")
        {
            cout << "Do you want to check your student's scores?" << endl;

            cin >> reply2;
        }
        if (reply2 == "yes")
        {
            while (!read.eof())

            {
                getline(read, y);

                cout << y << endl;

                cout << endl;

            }
            cout << "That's all of the scores in the file." << endl;

            cout << endl;

            cout << "Type exit if you want to exit this page: " << endl;

        }
        else if (reply2 == "no")

            cout << "Error!" << endl;
    }
    else
    {
        cout << "Invalid input, Try again!" << endl;

        cout << "Enter your username: " << endl;

        cin >> username;

        cout << "Enter your password: " << endl;

        cin >> password;

        check2(username, password); //incase of another wrong input
    }
    credentials.close();

}
void check_person(char x) //who is entering the system
{

    string username, password;

    if (x == 'a' || x == 'A')
    {
        cout << "Welcome Doctor!" << endl;

        cout << "---------------" << endl;

        cout << "Please enter your username: " << endl;

        cin >> username;

        cout << "Please enter your password: " << endl;

        cin >> password;

        check2(username, password);
    }
    else if (x == 'b' || x == 'B')
    {
        cout << "Welcome Student!" << endl;

        cout << "----------------" << endl;

        cout << "Enter your first name: " << endl;

        cin >> firstName;

        cout << "Enter your last name: " << endl;

        cin >> lastName;

        cout << "Hello, " << firstName << " " << lastName << "." << endl;

        cout << "Your quiz starts now." << endl;

        cout << "----------------------" << endl;

        ifstream quiz;

        ofstream  ans("student's answer.txt");

        quiz.open("questions.txt");

        string x;

        char newanswers[100];

        int lines = 0;

        while (!quiz.eof())

        {
            getline(quiz, x);

            cout << x << endl;

            cout << endl;

            lines++;
        }
        cin.ignore(1, '\n');
        for (int j = 1; j < lines; j++)

        {
            cout << "Write your answer to question no." << j << " here: " << endl;

            cin.getline(newanswers, 500);

            ans << newanswers << endl;

        }

        cout << "Done! Thank you." << endl;

        cout << "1.Logout     2.Show my score." << endl;

        return;

        quiz.close();
    }
    else
    {
        cout << "Invalid input. Try again!" << endl;

        cout << "Please enter either a or b." << endl;

        cin >> x;

        check_person(x);
    }

}

void AnswerChecker(int show)
{
    ifstream marks;

    string checker[100], answer[100];

    int score = 0;

    string x;

    ifstream ans;

    ans.open("student's answer.txt");

    string y;

    marks.open("Model Answers.txt");

    ofstream grades("Scores.txt", ios::app);


    while (getline(marks, x))
    {
        getline(ans, y);
        if (x == y)
        {
            score++;
        }
    }
    grades << firstName << " " << lastName << ": ";

    grades << score << endl;

    if (show == 2)
    {
        cout << "Your Score is: " << score << endl;
    }
    marks.close();
    ans.close();
    grades.close();

}


int main()
{
    char x;

    cout << "Choose please: " << endl;
    cout << "--------------" << endl;

    cout << "a) Doctor." << endl;

    cout << "b) Student." << endl;

    cin >> x;

    check_person(x);

    int z;

    cin >> z;

    switch (z)
    {
    case 1:
        cout << "successfully logged out" << endl;

        AnswerChecker(1);
        break;

    case 2:
        AnswerChecker(2);
        break;
    }
}