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

    // constructor
    Tree(){
        this->name = "";
		this->gender = 0;
        this->father = NULL;
        this->mother = NULL;
    }

    Tree(string name){
        this->name = name;
		this->gender = 0;
        this->father = NULL;
        this->mother = NULL;
    }

    // Tree(string name, Tree *child){
    //     this->name = name;
    //     this->child = child;
    //     this->father = NULL;
    //     this->mother = NULL;
    // }

    // destructor
    ~Tree(){
    	delete this->father;
    	delete this->mother;
    }
    

Tree& addFather(string son, string father);
Tree& addMother(string son, string mother);

string relation(string);
string find(string);

void remove(string name);
// void display();


private:

string findRelation(Tree* , size_t, unsigned int);

    };
}