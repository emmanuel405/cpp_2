
#include <iostream>
#include <string>

#include "FamilyTree.hpp"

using namespace std;
using namespace family;

static string ex = "unrelated";

Tree& Tree::addFather(string son, string father){
    Tree t("e");
    return t;
    // if(this == NULL){ // if tree == null -> return "unrelated";
    //     cout << ex << endl;
    //     throw "The tree is empty";
    // }
    // Tree tmp = find_the_name(this, son);
    // Tree *s = &tmp;
    // if(s == NULL){
    //     cout << ex << endl;
    //     throw "The son not find";
    // }
    // else {
    //     Tree newFather = Tree(father, s);
    //     return *this;
    // }
}

Tree& Tree::addMother(string son, string mother){
    Tree t("e");
    return t;
    // if(this == NULL){ // if tree == null -> return "unrelated";
    //     cout << ex << endl;
    //     throw "The tree is empty";
    // }
    // Tree tmp = find_the_name(this, son);
    // Tree *s = &tmp;
    // if(s == NULL){
    //     cout << ex << endl;
    //     throw "The son not find";
    // }
    // else {
    //     Tree newMother = Tree(mother, s);
    //     return *this;
    // }
}

string Tree::relation(string name){
    return name;

    // if(this == NULL){ // if tree == null -> return "unrelated";
    //     cout << ex << endl;
    //     throw "The tree is empty";
    // }
    // string ans = find_with_name(this, name); // search like inorder with this name and return the relation of this name
    // return ans;  
}

string Tree::find(string relation){
    return relation;
    // if(this == NULL){ // if tree == null -> return "unrelated";
    //     cout << ex << endl;
    //     throw "The tree is empty";
    // }
    // size_t pos = str.find("mother"); ??
    // go to mother and father תלוי
    // if I find return the name of this node
}

void Tree::remove(string name){
    cout << "part a" << endl;

    // if(this == NULL){ // if tree == null -> return "unrelated";
    //     cout << ex << endl;
    //     throw "The tree is empty";
    // }
    // search with inorder(name)
}

void Tree::display(Tree *t){
    cout << "part a" << endl;
   
    // preorder(t);
}


////////////////////////////////////////
/////////// private function ///////////
////////////////////////////////////////
////////////////////////////////////////

/*
string toRelateFather(string relat){
    string ans = "";
    if(relat == string("me"))
        return "father";
    else if(relat == string("father"))
        return "grandfather";
    else{
        ans = "great-"+relat;
        return ans;
    }

}

string toRelateMother(string relat){
    string ans = "";
    if(relat == string("me"))
        return "mother";
    else if(relat == string("mother"))
        return "grandmother";
    else{
        ans = "great-"+relat;
        return ans;
    }
}

void preorder(Tree *t){
    if(t == NULL)
        return;
    cout << t->name << endl;
    preorder(t->mother);
    preorder(t->father);
}

string find_with_name(Tree t, string name2find){
    if(t.name == name2find) return t.relat;
    find_with_name(t.mother, name2find);
    find_with_name(t.father, name2find);
    return "unrelated";
}

Tree find_the_name(Tree t, string name2find){
    if(t.name == name2find) return t;
    find_the_name(t.mother, name2find);
    find_the_name(t.father, name2find);
    return NULL;
}


addFather
addMother
relation(string name) -> relation
find(string relation) -> name
display(תצוגה)
remove(string name)
*/