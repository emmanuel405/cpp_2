#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace family{
    class Tree{
    public:
        string name;
		int relat;
        Tree* mother;
        Tree* father;

    // constructor
    Tree(){
        this->name = "";
		this->relat = 0;
        this->father = NULL;
        this->mother = NULL;
    }

    Tree(string name){
        this->name = name;
		this->relat = 0;
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

// void remove(string name);
// void display();


private:
void print2DUtil(Tree*, int);
void print2D(Tree*);

// Tree& findName(Tree&,string,string);
// Tree find_the_name(Tree t, string name2find);

// string find_with_name(Tree t, string name2find);
// string toRelateFather(string relat);
// string toRelateMother(string relat);

// void preorder(Tree *t);
    };
}