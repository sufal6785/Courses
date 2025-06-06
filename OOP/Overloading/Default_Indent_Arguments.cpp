//Default Arguments
#include <iostream>
#include <string>
using namespace std;

//default value must be at the right of the arguments
// void iputs(int indent = -1; const string &str)  => wrong declaration
void iputs(const string &str, int indent = -1) 
{
    static int i = 0; // holds previous value

    if (indent >= 0)
        i = indent;
    else
        indent = i; // reuse previous value

    while (indent)
    {
        cout << " ";
        indent--;
    }
    cout << str << endl;
}

int main()
{
    iputs("Hello worlds", 10); // for 10 spaces
    iputs("This will be indented 10 spaces by default");
    iputs("This will takes 5 spaces", 5);
    iputs("This will take no spaces", 0);

    return 0;
}