
#include <iostream>
#include <string>

#include "FamilyTree.hpp"

using namespace std;
using namespace family;

Tree& Tree::addFather(string son, string father){
    if(this == NULL){ // if tree == null -> return "unrelated";
        cout << "unrelated" << endl;
        return throw "The tree is empty";
    }
    Tree& s = find_the_name(this, son);
    if(s == NULL){
        cout << "unrelated" << endl;
        return throw "The son not find";
    }
    else {
        Tree newFather = Tree(father);
        s.father = newFather;
        return this;
    }
}

Tree& Tree::addMother(string son, string mother){
    if(this == NULL){ // if tree == null -> return "unrelated";
        cout << "unrelated" << endl;
        return throw "The tree is empty";
    }
    Tree& s = find_the_name(this, son);
    if(s == NULL){
        cout << "unrelated" << endl;
        return throw "The son not find";
    }
    else {
        Tree newMother = Tree(mother);
        s.mother = newMother;
        return this;
    }
}

string Tree::relation(string name){
    if(this == NULL){ // if tree == null -> return "unrelated";
        cout << "unrelated" << endl;
        return throw "The tree is empty";
    }
    string ans = find_with_name(this, name); // search like inorder with this name and return the relation of this name
    return ans;  
}

string Tree::find(string relation){
    if(this == NULL){ // if tree == null -> return "unrelated";
        cout << "unrelated" << endl;
        return throw "The tree is empty";
    }
    // size_t pos = str.find("mother"); ??
    // go to mother and father תלוי
    // if I find return the name of this node
}

void Tree::remove(string name){
    if(this == NULL){ // if tree == null -> return "unrelated";
        cout << "unrelated" << endl;
        return throw "The tree is empty";
    }
    // search with inorder(name)
}

void Tree::display(Tree t){
    preorder(t);
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

void preorder(Tree *t){
    if(t==NULL)
        return;
    cout << t.name << endl;
    preorder(t->mother);
    preorder(t->father);
}

string find_with_name(Tree *t, string name2find){
    if(t->name == name2find) return t->relat;
    find_with_name(t->mother, name2find);
    find_with_name(t->father, name2find);
    return "unrelated";
}

Tree& find_the_name(Tree *t, string name2find){
    if(t->name == name2find) return t;
    find_the_name(t->mother, name2find);
    find_the_name(t->father, name2find);
    return NULL;
}


/*
addFather
addMother
relation(string name) -> relation
find(string relation) -> name
display(תצוגה)
remove(string name)
*/