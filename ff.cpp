#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> lst;
    lst.pop_back();
    lst.push_back(1);
    cout<<lst.front()<<endl;
}