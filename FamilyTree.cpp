
#include <iostream>
#include <string>

#include "FamilyTree.hpp"

using namespace std;

string toRelateFather(string relat);
string toRelateMother(string relat);

Tree& Tree::addFather(string son, string father){
    
}

Tree& Tree::addMother(string son, string mother){
    
}

string Tree::relation(string name){
    // if tree == null -> return "unrelated";
    // search inorder(name)
    // return name[node]->relation
}

string Tree::find(string relation){
    // if tree = null -> return "unrelated";
    // go to father or mother תלוי
    // if I find return the name of this node
}

void Tree::remove(string name){
    // if tree = null -> return "unrelated";
    // search inorder(name)
    
}

void Tree::display(Tree t){

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

/*
addFather
addMother
relation(string name) -> relation
find(string relation) -> name
display(תצוגה)
remove(string name)
*/