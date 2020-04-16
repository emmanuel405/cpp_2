#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Client{
public:
    string name;
    int age;
    char clr; // 'R', 'B', 'G', 'W'

    Client(string n, int a, char c){
        this->name = n;
        this->age = a;
        this->clr = c;
    }

    Client(string n, int a){
        this->name = n;
        this->age = a;
        this->clr = 'A';
    }

    ~Client(){
    
    }
};

int main(){
    Client c = Client("Emmanuel", 23, 'B');
    cout << c.name << endl;
    Client *cptr = &c;
    cout << cptr->age << endl;
    delete cptr;
    return 0;
}

