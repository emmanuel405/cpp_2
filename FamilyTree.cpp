#include <iostream>
#include <string>

#include "FamilyTree.hpp"

using namespace std;

struct Node{
    string name;
    string relat;
    Node father;
    Node mother;
}
Node::Node(){
    this->name = "";
    this->relat = "";
}

Node::Node(string name){
    this->name = name;
    this->relat = "";
}

Node::~Node(string name){
}

namespace family{
    struct Tree{

    }
}

void addFather(Node node){

}

void addMother(Node node){
    
}

string relation(string name){

}

string find(string relation){

}

void remove(string name){

}

string display(FamilyTree t){

}
/*
addFather
addMother
relation(string name) -> relation
find(string relation) -> name
display(תצוגה)
remove(string name)
*/