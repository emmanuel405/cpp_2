
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "FamilyTree.hpp"


using namespace std;
using namespace family;

#define COUNT 10

static string ex = "unrelated";

Tree& Tree::addFather(string son, string parent){
	int r=0; // for relation of the parent
	if(this->name == string(son)){
		if(this->father){ // this son has already a father.
			cout << "this son" << son << "has already a father" << endl;
			throw runtime_error("We can't to add this father !");
		}
		else{ 
			Tree* newTree = new Tree(parent);
			this->father = newTree;
			this->father->relat = ++r;
			return *this;
		}
	}
	else{ // Recursive addFather
		if(this->father != NULL) {
			this->father->addFather(son, parent);
			this->father->relat = ++r;
		}
		if(this->mother != NULL) {
			this->mother->addFather(son, parent);
			this->father->relat = ++r;
		}
		return *this;
	}

}

Tree& Tree::addMother(string son, string parent){
	int r=0; // for relation of the parent
	if(this->name == string(son)){
		if(this->mother){ // this son has already a mother.
            cout << "this son " << son << " has already a mother" << endl;
			throw runtime_error("We can't to add this father !");
		}
		else{ 
			Tree* newTree = new Tree(parent);
			this->mother = newTree;
			return *this;
		}
	}
	else{ // Recursive addMother
		if(this->father != NULL) {
			this->father->addMother(son, parent);
			this->father->relat = ++r;
		}
		if(this->mother != NULL) {
			this->mother->addMother(son, parent);
			this->father->relat = ++r;
		}
		return *this;
	}
}

string Tree::relation(string name){
	if(this->name == string(name)){
		// relation in vector etc
	}
	else{
		if(this->father != NULL) {
			this->father->relation(name);
		}
		if(this->mother != NULL) this->mother->relation(name);
	}
	return ex;
}

string Tree::find(string relation){
    
        return ex;
    // size_t pos = str.find("mother"); ??
    // go to mother and father תלוי
    // if I find return the name of this node
}

// void Tree::remove(string name){
// 	Tree& t = *(this);
// 	if(t.name == string(name)){
// 		delete t;
// 	}
// 	else{
// 		t.remove(t.father->name);
// 		t.remove(t.mother->name);
// 	}
//     throw runtime_error("This person " + name + " don't find So we can't remove him !");

// }

// void Tree::display(){
//     cout << "display" << endl;
//     print2D(this);
// }

////////////////////////////////////////
/////////// private function ///////////
////////////////////////////////////////
////////////////////////////////////////

// Function to print binary tree in 2D
// It does reverse inorder traversal
// from www.geeksforgeeks.org
void print2DUtil(Tree *root, int space){
    // Base case  
    if (NULL == root) return;

    // Increase distance between levels
    space += COUNT;
  
    // Process father first
    print2DUtil(root->father, space);
  
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " " << root->name << "\n";
  
    // Process mother
    print2DUtil(root->mother, space);
}

// Wrapper over print2DUtil()
void print2D(Tree *root){
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// Tree& findName(Tree& root, string son, string father){
	
// 	return *this;
// }
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