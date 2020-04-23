#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace family{
    class Tree{
    public:
        string name;
		int gender;
        Tree* mother;
        Tree* father;
        Tree* child;

    // constructor
    Tree(){
        this->name = "";
        this->father = NULL;
        this->mother = NULL;
        this->child = NULL;
    }

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
    ~Tree();
    	// delete this->father;
    	// delete this->mother;
      

Tree& addFather(string son, string father);
Tree& addMother(string son, string mother);

string relation(string);
string find(string);

void remove(string name);
// void display();


private:
bool goodRelation(string);
string findRelation(Tree*, size_t, unsigned int);
Tree* personInTree(Tree*, string);

    };
}