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
        Tree* father;
        Tree* mother;
        Tree* child;

    // Tree::Tree(){
    //     *(this)->name = "";
    //     *(this)->relat = "";
    // }

    Tree(string name){
        this->name = name;
        this-> father = NULL;
        this-> mother = NULL;
        this-> son = NULL;
    }

    ~Tree(string name){
    }
    

Tree& addFather(string son, string father);

Tree& addMother(string son, string mother);

string relation(string name);

string find(string relation);

void remove(string name);

void display(Tree t);
    };
}