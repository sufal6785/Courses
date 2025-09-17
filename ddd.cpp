// #include <iostream>
// #include <fstream>
// #include <string>
// #include <conio.h>
// #include <sstream>
// using namespace std;

// class DateTime
// {
// };

// class Quiz
// {
// private:
//     int id;
//     /*Questions* questions[100];*/
//     int num_questions;
//     int max_time;
//     DateTime start_time;
//     DateTime end_time;
//     /*professor generated_by;*/
// public:
//     void grade()
//     {

//         cout << " You have Scored 8/10 in Quiz # 1 " << endl;
//         cout << " Max Time for Quiz was 30 Minutes" << endl;
//         cout << " Start Date = 14/05/2023 " << endl;
//         cout << " End Date = 14/05/2023 " << endl;
//         cout << endl;
//         cout << "-------------------------------------------" << endl;
//         cout << endl;
//         cout << " You have Scored 10/10 in Quiz # 2 " << endl;
//         cout << " Max Time for Quiz was 15 Minutes" << endl;
//         cout << " Start Date = 14/05/2023 " << endl;
//         cout << " End Date = 14/05/2023 " << endl;
//     }

//     /*QuizStatistics getStatistics() {

//     }*/

//     void createQuiz()
//     {
//         ifstream inputFile("./Questions.txt");

//         if (!inputFile.is_open())
//         {
//             cout << "Failed to open file!" << endl;
//         }
//         string line;
//         const int ROWS = 1; // Maximum number of rows
//         int row = 0;
//         while (getline(inputFile, line))
//         {
//             if (row >= ROWS)
//             {
//                 cout << "Maximum number of rows exceeded!" << endl;
//                 break;
//             }

//             stringstream lineStream(line);
//             string cell;
//             while (getline(lineStream, cell, ','))
//             {
//                 cout << cell << "";
//             }
//             cout << endl;
//         }
//         inputFile.close();
//     }
// };

// class students
// {
//     // Course *enrolledCources[1000];
//     int numEnrolledcourses;

// public:
//     students()
//     {
//         numEnrolledcourses = 0;
//     }

//     void takeQuiz()
//     {

//         ifstream inputFile("./Questions.txt");

//         if (!inputFile.is_open())
//         {
//             cout << "Failed to open file!" << endl;
//         }
//         string line;
//         const int ROWS = 1; // Maximum number of rows
//         int row = 0;
//         while (getline(inputFile, line))
//         {
//             if (row >= ROWS)
//             {
//                 cout << "Maximum number of rows exceeded!" << endl;
//                 break;
//             }

//             stringstream lineStream(line);
//             string cell;
//             while (getline(lineStream, cell, ','))
//             {
//                 cout << cell << "";
//             }
//             cout << endl;
//         }
//         inputFile.close();
//     }
// };

// class User
// {
// private:
//     int id;
//     string name;
//     string userName;
//     string password;

// public:
//     Quiz a;
//     students b;

//     void ExitProgram()
//     {
//         exit(0);
//     }

//     void CreateAccount()
//     {
//         fstream file;
//         file.open("./Course Registration Data.csv", ios::out | ios::app);

//         if (file.is_open())
//         {
//             string name, userName, password;
//             int id;

//             cout << "Enter ID: ";
//             cin >> id;
//             cout << "Enter name: ";
//             cin.ignore();
//             getline(cin, name);
//             cout << "Enter username: ";
//             getline(cin, userName);

//             cout << "Enter password: ";
//             char ch;
//             while ((ch = _getch()) != '\r')
//             {

//                 password.push_back(ch);
//                 cout << "*";
//             }
//             cout << endl;

//             file << id << "," << name << "," << userName << "," << password << "\n";
//             file.close();

//             cout << "Account created successfully!" << endl;
//         }
//         else
//         {
//             cout << "Unable to open the file." << endl;
//         }
//     }

//     void AvailableCourses()
//     {

//         ifstream inputFile("./Courses.txt");

//         if (!inputFile.is_open())
//         {
//             cout << "Failed to open file!" << endl;
//         }
//         string line;
//         const int ROWS = 1; // Maximum number of rows
//         int row = 0;
//         while (getline(inputFile, line))
//         {
//             if (row >= ROWS)
//             {
//                 cout << "Maximum number of rows exceeded!" << endl;
//                 break;
//             }

//             stringstream lineStream(line);
//             string cell;
//             while (getline(lineStream, cell, ','))
//             {
//                 cout << cell << "";
//             }
//             cout << endl;
//         }
//         inputFile.close();
//     }

//     bool login()
//     {
//         int user;
//         cout << "------------------------------------- " << endl;
//         cout << "|                                   | " << endl;
//         cout << "|    1. Login as Professor          |" << endl;
//         cout << "|    2. Login as Student            |" << endl;
//         cout << "|    3. Back                        |" << endl;
//         cout << "|                                   | " << endl;
//         cout << "------------------------------------- " << endl;
//         cout << "Enter your choice: ";
//         cin >> user;

//         switch (user)
//         {
//         case 1:
//             ProfessorMenu();
//             break;
//         case 2:
//             StudentsMenu();
//             break;
//         case 3:
//             int main();
//             break;
//         default:
//             cout << "Invalid choice!" << endl;
//             break;
//         }
//         return true;
//     }

//     void enrolledStudents()
//     {

//         ifstream inputFile("./Course Registration Data.csv");

//         if (!inputFile.is_open())
//         {
//             cout << "Failed to open file!" << endl;
//         }
//         string line;
//         const int ROWS = 1; // Maximum number of rows
//         int row = 0;
//         while (getline(inputFile, line))
//         {
//             if (row >= ROWS)
//             {
//                 cout << "Maximum number of rows exceeded!" << endl;
//                 break;
//             }
//             stringstream lineStream(line);
//             string cell;
//             while (getline(lineStream, cell, ','))
//             {
//                 cout << cell << "";
//             }
//             cout << endl;
//         }
//         inputFile.close();
//     }

//     void ProfessorMenu()
//     {
//         cout << "------------------------------------ " << endl;
//         cout << "|          Welcome Professor!      |" << endl;
//         cout << "|                                  | " << endl;
//         cout << "|      1. Enrolled Students        |" << endl;
//         cout << "|      2. Create Quiz              |" << endl;
//         cout << "|      3. View Quiz Statistics     |" << endl;
//         cout << "|      4. Back                     |" << endl;
//         cout << "------------------------------------ " << endl;
//         cout << "Enter your choice: ";

//         int choice;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             enrolledStudents();
//             break;
//         case 2:
//             a.createQuiz();
//             break;
//         case 3:
//             // View Quiz Statistics
//             cout << "Viewing Quiz Statistics..." << endl;
//             break;
//         case 4:
//             login();
//             break;
//         default:
//             cout << "Invalid choice!" << endl;
//             break;
//         }
//     }

//     void StudentsMenu()
//     {
//         cout << "------------------------------------ " << endl;
//         cout << "|          Welcome Student!        | " << endl;
//         cout << "|                                  | " << endl;
//         cout << "|    1. View Courses               | " << endl;
//         cout << "|    2. Take Quiz                  | " << endl;
//         cout << "|    3. View Grades                | " << endl;
//         cout << "|    4. Back                       | " << endl;
//         cout << "------------------------------------ " << endl;
//         cout << "Enter your choice: ";

//         int choice;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             AvailableCourses();
//             break;
//         case 2:
//             b.takeQuiz();
//             break;
//         case 3:
//             a.grade();
//             break;
//         case 4:
//             login();
//             break;
//         default:
//             cout << "Invalid choice!" << endl;
//             break;
//         }
//     }
// };

// class Questions
// {
//     int id;
//     string topic;
//     string text;
//     string answer;

// public:
// };

// class professor
// {
// private:
//     int numCourses;

// public:
//     professor()
//     {
//         numCourses = 0;
//     }

//     void questionBank() {

//     };
// };

// class QuestionsStatistics
// {
// private:
//     Questions *questions;
//     float correctPercent;
// };

// class QuizStatistics
// {
// private:
//     QuizStatistics *questionStats[1000];
//     int numQuestions;
// };

// class AnswerKey
// {
//     Quiz *quiz;
//     string answers[1000];
// };

// class Course
// {
// private:
//     string name;
//     professor instructor;
//     students enrolledStudents[1000];
//     int numStudents_enrolled;

// public:
// };

// class MCQs : public Questions
// {
// private:
//     string options[4];
// };

// class TrueFlase : public Questions
// {
// private:
//     bool correctAnswer;
// };

// int main()
// {
//     User person;
//     int choice;

//     while (true)
//     {
//         cout << "------------------------------------ " << endl;
//         cout << "|                                  | " << endl;
//         cout << "|       1. Create Account          | " << endl;
//         cout << "|       2. Login                   | " << endl;
//         cout << "|       3. Exit                    | " << endl;
//         cout << "|                                  | " << endl;
//         cout << "------------------------------------ " << endl;
//         cout << "Enter your choice:" << endl;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             person.CreateAccount();
//             break;
//         case 2:
//             person.login();
//             break;
//         case 3:
//             person.ExitProgram();
//             break;
//         default:
//             cout << "Invalid choice!" << endl;
//             break;
//         }
//     }
//     return 0;
// }