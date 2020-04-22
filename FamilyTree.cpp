
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <exception>
#include <stdexcept>
#include <vector>

#include "FamilyTree.hpp"


using namespace std;
using namespace family;

#define COUNT 10

static string ex = "unrelated";
string help = "";
string ans = "";


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
			this->father->gender = 1;
			return *this;
		}
	}
	else{ // Recursive addFather
		if(this->father != NULL) {
			this->father->addFather(son, parent);
		}
		if(this->mother != NULL) {
			this->mother->addFather(son, parent);
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
			this->mother->gender = 2;
			return *this;
		}
	}
	else{ // Recursive addMother
		if(this->father != NULL) {
			this->father->addMother(son, parent);
		}
		if(this->mother != NULL) {
			this->mother->addMother(son, parent);
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


string Tree::find(string relat){

	if(relat == string("me"))
		return this->name;
	
	else if(relat == string("father"))
		return this->father->name;

	else if(relat == string("mother"))
		return this->mother->name;

	else{
		size_t f = relat.find("grandfather");
		if((f >= 0) && (f < relat.length())){
			f = f/6; // How many times "great-" appear
			f = f + 2;
			ans = findRelation(this,f,1);
			if(ans != "")
				return ans;
			throw runtime_error("failed in f");
		}

		else{
			size_t m = relat.find("grandmother");
			if((m >= 0) && m < relat.length()){
				m = m/6; // How many times "great-" appear
				m += 2;
				ans = findRelation(this,m,2);
				if(ans != "")
					return ans;
				throw runtime_error("failed in m");
			}
			else throw runtime_error("wow"); 
		}
		
	}
}
// is not a string (great-)^*grandfather
	// size_t pos = str.find("mother"); ??
	// go to mother and father תלוי
	// if I find return the name of this node

void Tree::remove(string name){
	if(this->name == string(name)){
		this->~Tree();
	}
	else{
		this->remove(this->father->name);
		this->remove(this->mother->name);
	}
	throw runtime_error("This person " + name + " don't find So we can't remove him !");
}

// void Tree::display(){
//     cout << "display" << endl;
//     print2D(this);
// }

////////////////////////////////////////
/////////// private function ///////////
////////////////////////////////////////
////////////////////////////////////////

/**
 * findRelation
 * @param num => define how many times I need to jump
 * @param gender => 1 for man, 2 for woman
 * @example
 * if I want to fing the grandfather.
 * I need to jump a first time to father/mother
 * and one more time to grandfather
 * 
 * @return The name of who I am looking for
 */
string Tree::findRelation(Tree* t, size_t num, unsigned int gender){ 
	switch(num)
	{
		case 1:
		if(gender == 1){
			if(t->father != NULL)
				return t->father->name;
			num++;
			return "";
		}
		else{ // gender == 2
			if(t->mother != NULL)	
				return t->mother->name;
			num++;
			return "";
		}
		break;

		default:
		if(t->father != NULL){
			num--;
			help = findRelation(t->father, num, gender);
			if(help == ""){
				if(t->mother != NULL){
					num--;
					help = findRelation(t->mother, num, gender);
				}
			}
		}
		else{
			if(t->mother != NULL){
				num--;
				help = findRelation(t->mother, num, gender);
			}
		}
		return help;
		break;
	
	}


}

// Function to print binary tree in 2D
// It does reverse inorder traversal
// from www.geeksforgeeks.org
// void print2DUtil(Tree *root, int space){
//     // Base case  
//     if (NULL == root) return;

//     // Increase distance between levels
//     space += COUNT;

//     // Process father first
//     print2DUtil(root->father, space);

//     // Print current node after space
//     // count
//     cout << endl;
//     for (int i = COUNT; i < space; i++)
//         cout << " " << root->name << "\n";

//     // Process mother
//     print2DUtil(root->mother, space);
// }

// // Wrapper over print2DUtil()
// void print2D(Tree *root){
//     // Pass initial space count as 0
//     print2DUtil(root, 0);
// }

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