/*
#include <iostream>
#include <string>

#include "FamilyTree.hpp"

using namespace std;

string toRelateFather(string relat);
string toRelateMother(string relat);

struct Node{
    public:
    string name;
    string relat;
    Node father;
    Node mother;
    Node child;

}
Node::Node(){
    *(this)->name = "";
    *(this)->relat = "";
}

Node::Node(string name){
    *(this)->name = name;
    *(this)->relat = "";
}

Node::~Node(string name){
}

namespace family{
    class Tree{
    private:
        Node root(string name);
    public:
        Tree(string name){
            root(name);
        }
        ~Tree();
    };
    
    Tree::Tree(/* args *//*){

    }
    
    Tree::~Tree(){

    }
    
}

void addFather(string son, string father){
    Node n = new Node(father);
    string relation_son = 
    
}

void addMother(string son, string mother){
    Node n = new Node(mother);
}

string relation(string name){
    // if tree = null -> return "unrelated";
    // search inorder(name)
    // return name[node]->relation
}

string find(string relation){
    // if tree = null -> return "unrelated";
    // go to father or mother תלוי
    // if I find return the name of this node
}

void remove(string name){
    // if tree = null -> return "unrelated";
    // search inorder(name)
    
}

string display(Tree t){

}

string toRelateFather(string relat){
    if(relat == string("me"))
        return "father";
    else if(relat == string("father"))
        return "grandfather";
    else{
        string ans = "great-"+relat;
        return ans;
    }

}

string toRelateMother(string relat){
    if(relat == string("me"))
        return "mother";
    else if(relat == string("mother"))
        return "grandmother";
    else{
        string ans = "great-"+relat;
        return ans;
    }
        

}
*/
/*
addFather
addMother
relation(string name) -> relation
find(string relation) -> name
display(תצוגה)
remove(string name)
*/