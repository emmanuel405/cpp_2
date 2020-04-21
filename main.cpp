#include "FamilyTree.hpp"
#include <iostream>

using namespace std;
using namespace family;


int main() {
    Tree t = Tree("Emmanuel");
    // t.remove("Emmanuel");
    t.addFather("Emmanuel", "Meir");
    

    cout << "result:" << endl;
    cout << "E = " << t.name << endl;
    cout << "M = " << t.father->name << endl;
    cout << t.relation("Meir") << endl;

    return 0;
}