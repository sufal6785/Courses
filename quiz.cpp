#include <iostream>

#include <fstream>

#include <windows.h>

#include <ctime>

#include <stdlib.h>

#include <queue>

#include <string>

using namespace std;
void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
struct linklist
{
    string data;
    linklist *next;
};
linklist *QuestionTF;
linklist *QuestionMC;
linklist *QuestionSA;
linklist *answerTF;
linklist *answerMC;
linklist *answerSA;
class Question
{
public:
    void questionTF(linklist *node, linklist *ans);
    void questionMC(linklist *node, linklist *ans);
    void questionSA(linklist *node, linklist *ans);
};
void Question::questionTF(linklist *node, linklist *ans)
{
    if (QuestionTF == NULL)
    {
        QuestionTF = node;
        answerTF = ans;
        QuestionTF->next = NULL;
        answerTF->next = NULL;
    }
    else
    {
        node->next = QuestionTF;
        QuestionTF = node;
        ans->next = answerTF;
        answerTF = ans;
    }
}
void Question::questionMC(linklist *node, linklist *ans)
{
    if (QuestionMC == NULL)
    {
        QuestionMC = node;
        answerMC = ans;
        QuestionMC->next = NULL;
        answerMC->next = NULL;
    }
    else
    {
        node->next = QuestionMC;
        QuestionMC = node;
        ans->next = answerMC;
        answerMC = ans;
    }
}
void Question::questionSA(linklist *node, linklist *ans)
{
    if (QuestionSA == NULL)
    {
        QuestionSA = node;
        answerSA = ans;
        QuestionSA->next = NULL;
        answerSA->next = NULL;
    }
    else
    {
        node->next = QuestionSA;
        QuestionSA = node;
        ans->next = answerSA;
        answerSA = ans;
    }
}
void load_questions(string file)
{
    Question q;
    string data;
    string check;
    string ques;
    ifstream Qfile;
    Qfile.open("questions.txt");
    if (Qfile.is_open())
    {
        getline(Qfile, ques);
        while (Qfile.good())
        {
            getline(Qfile, check);
            if (check[0] == 'T' && check[1] == 'F')
            {
                linklist *node = new linklist();
                linklist *ans = new linklist();
                string question;
                string answer;
                getline(Qfile, question);
                getline(Qfile, answer);
                ans->data = answer;
                node->data = question;
                q.questionTF(node, ans);
            }
            else if (check[0] == 'M' && check[1] == 'C')
            {
                linklist *node = new linklist();
                linklist *ans = new linklist();
                string question, opA, opB, opC, opD, answer;
                getline(Qfile, question);
                getline(Qfile, opA);
                getline(Qfile, opB);
                getline(Qfile, opC);
                getline(Qfile, opD);
                getline(Qfile, answer);
                ans->data = answer;
                node->data = question + "\n" + opA + "\n" + opB + "\n" + opC + "\n" + opD;
                q.questionMC(node, ans);
            }
            else if (check[0] == 'S' && check[1] == 'A')
            {
                linklist *node = new linklist();
                linklist *ans = new linklist();
                string question, answer;
                getline(Qfile, question);
                getline(Qfile, answer);
                ans->data = answer;
                node->data = question;
                q.questionSA(node, ans);
            }
        }
        Qfile.close();
    }
}
string input_question(linklist *node, int total)
{
    linklist *temp = node;
    while (total != 0)
    {
        temp = temp->next;
        total--;
    }
    return temp->data;
}
string input_answer(linklist *node, int total)
{
    linklist *temp = node;
    while (total != 0)
    {
        temp = temp->next;
        total--;
    }
    return temp->data;
}
int questionC(linklist *node)
{
    int count = 0;
    linklist *temp = node;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
class graphics
{
private:
    char x = 220;

public:
    graphics()
    {
        for (int i = 0; i < 35; i++)
        {
            cout << x;
            if (i < 10)
                Sleep(300);
            if (i >= 10 && i < 20)
                Sleep(150);
            if (i >= 10)
                Sleep(25);
        }
        cout << " 100%";
    }
};
int main()
{
    SetColor(5);
    cout << "\n\t\t\t                ---------------------------------------" << endl;
    cout << "\t\t\t                |      QUIZZER MANAGEMENT SYSTEM      |" << endl;
    cout << "\t\t\t                ---------------------------------------" << endl;
    SetColor(4);
    cout << "\n\n                             \t\t\t>>>Important Note<<<" << endl;
    cout << "________________________________________________________________________________________________________________________" << endl;
    cout << "1) Question bank contains MCQs, True/False and Short questions." << endl;
    cout << "2) Select the question numbers that you want to answer only in numeric form." << endl;
    cout << "3) Question numbers that you want to answers must be less than or equal to the total questions number." << endl;
    cout << "4) Kindly read the <<<Important Note>>> carefully." << endl;
    cout << "________________________________________________________________________________________________________________________" << endl;
    queue<int> gquiz;
    srand(time(0));
    int total_marks = 0;
    int obtained = 0;
    Question q;
    string first, last, file;
    ifstream Qfile;
    string data;
    string type;
    int question;
    int choice;
    SetColor(5);
    cout << "What is your first name: ";
    SetColor(3);
    cin >> first;
    SetColor(5);
    cout << "What is your last name: ";
    SetColor(3);
    cin >> last;
    SetColor(5);
    cout << "What file stores your question: ";
    SetColor(3);
    cin >> file;
    cout << endl;
    SetColor(4);
    cout << "Loading File..." << endl;
    SetColor(02);
    graphics obj1;
    cout << endl;
    if (file == "questions.txt")
    {
        Qfile.open("questions.txt");
        if (Qfile.is_open())
        {
            Qfile >> question;
        }
        Qfile.close();
        load_questions(file);
    }
    else
    {
        SetColor(4);
        cout << "\nQuestion bank file is not found!!!" << endl;
        return 0;
    }
    while (true)
    {
        cout << "\nHow many question would you like (out of " << question << " ): ";
        SetColor(4);
        cin >> choice;
        cout << endl;
        SetColor(4);
        cout << "Loading Questions..." << endl;
        SetColor(02);
        graphics obj2;
        cout << endl;
        SetColor(11);
        if (choice <= question)
        {
            int countTF = questionC(QuestionTF);
            int countMC = questionC(QuestionMC);
            int countSA = questionC(QuestionSA);
            int totalTF, totalMC, totalSA = 0;
            while (choice != 0)
            {
                int ques_type = rand() % 3 + 1;
                cout << "\n";
                if (ques_type == 1)
                {
                    if (totalTF < countTF)
                    {
                        string result;
                        string question = input_question(QuestionTF, totalTF);
                        string answer = input_answer(answerTF, totalTF);
                        cout << "Points : 5" << endl;
                        cout << "Question : " << question << endl;
                        cin >> result;
                        if (result == "SKIP")
                        {
                            cout << "skipped" << endl;
                        }
                        else if (result == answer)
                        {
                            cout << "Correct answer! you got 5 points" << endl;
                            gquiz.push(5);
                            total_marks = total_marks + 5;
                            obtained = obtained + 5;
                        }
                        else
                        {
                            cout << "Incorrect! the correct answer is " << answer << ".\nYou loose 5 points" << endl;
                            total_marks = total_marks + 5;
                            gquiz.push(0);
                        }
                        choice--;
                        totalTF++;
                    }
                }
                else if (ques_type == 2)
                {
                    if (totalMC < countMC)
                    {
                        string result;
                        string question = input_question(QuestionMC, totalMC);
                        string answer = input_answer(answerMC, totalMC);
                        cout << "Points : 10" << endl;
                        cout << "Question : " << question << endl;
                        cin >> result;
                        if (result == "SKIP")
                        {
                            cout << "skipped" << endl;
                        }
                        else if (result == answer)
                        {
                            cout << "Correct answer! You got 10 points" << endl;
                            total_marks = total_marks + 10;
                            gquiz.push(10);
                            obtained = obtained + 10;
                        }
                        else
                        {
                            cout << "Incorrect! the correct answer is " << answer << ".\nYou loose 10 points" << endl;
                            total_marks = total_marks + 10;
                            gquiz.push(0);
                        }
                        choice--;
                        totalMC++;
                    }
                }
                else if (ques_type == 3)
                {
                    if (totalSA < countSA)
                    {
                        string result;
                        string question = input_question(QuestionSA, totalSA);
                        string answer = input_answer(answerSA, totalSA);
                        cout << "Points : 20" << endl;
                        cout << "Question : " << question << endl;
                        cin >> result;
                        if (result == "SKIP")
                        {
                            cout << "skipped" << endl;
                        }
                        else if (result == answer)
                        {
                            cout << "Correct answer! you got 20 points" << endl;
                            total_marks = total_marks + 20;
                            gquiz.push(20);
                            obtained = obtained + 20;
                        }
                        else
                        {
                            cout << "Incorrect! the correct answer is " << answer << ".\nYou loose 20 points" << endl;
                            total_marks = total_marks + 20;
                            gquiz.push(0);
                        }
                        choice--;
                        totalSA++;
                    }
                }
            }
            break;
        }
        else if (choice > question)
        {
            cout << "Sorry! this is too many." << endl;
        }
    }
    cout << endl;
    SetColor(4);
    cout << "Compiling Result..." << endl;
    SetColor(02);
    graphics obj3;
    cout << endl;
    ofstream endFile("result.txt");
    if (endFile.is_open())
    {
        /// endFile<<"\n\n\t\t*****Quiz Report***"<<endl;
        endFile << "\n\t\t\t                            ---------------------------------------" << endl;
        endFile << "\t\t\t                            |             QUIZ REPORT             |" << endl;
        endFile << "\t\t\t                            ---------------------------------------" << endl;
        endFile << "First Name: " << first << endl;
        endFile << "Last Name: " << last << endl
                << endl;
        int i = 1;
        while (!gquiz.empty())
        {
            endFile << "Marks obtained in Question No. " << i << " are: " << gquiz.front();
            gquiz.pop();
            i++;
            endFile << "\n";
        }
        endFile << "\nTotal Obtained Marks: " << obtained << "/" << total_marks << endl;
    }
    endFile.close();
    SetColor(4);
    cout << "\nCreating Result File..." << endl;
    SetColor(02);
    graphics obj4;
    cout << endl;
    SetColor(5);
    cout << "\nCongratulations! Result file created successfully.";
}