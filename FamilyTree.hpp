#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace family{
    class Tree{
        public:
        string name;
        string relat;
        Tree* mother;
        Tree* father;
        Tree* child;

    // constructor
    Tree(string name){
        this->name = name;
        this->father = NULL;
        this->mother = NULL;
        this->child = NULL;
    }

    Tree(string name, Tree *child){
        this->name = name;
        this->child = child;
        this->father = NULL;
        this->mother = NULL;
    }

    // destructor
    ~Tree(string name){
        cout << "Dstor" << endl;
    }
    
public:

Tree& addFather(string son, string father);
Tree& addMother(string son, string mother);

string relation(string name);
string find(string relation);

void remove(string name);
void display(Tree *t);


private:

Tree find_the_name(Tree t, string name2find);

string find_with_name(Tree t, string name2find);
string toRelateFather(string relat);
string toRelateMother(string relat);

void preorder(Tree *t);
    };
}