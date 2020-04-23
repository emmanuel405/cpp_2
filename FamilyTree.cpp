
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

static string EXIT = "unrelated";
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
			Tree* newTree = new Tree(parent, this);
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
			Tree* newTree = new Tree(parent, this);
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
	if(this->name == string(name)) return "me";
	if(this->father->name == string(name)) return "father";
	if(this->mother->name == string(name)) return "mother";

	Tree* t = personInTree(this, name);
	if (t == NULL) return EXIT;
	Tree* tmp = t;
	int count = 0;
	while(tmp->child != NULL){
		count++;
		tmp = tmp->child;
	}

	if(count == 2){
		if(t->gender == 1) return "grandfather";
		return "grandmother";
	}
	string answer = "";
	if(count > 2){
		for(int i=2; i<count; i++)
			answer += "great-";

		if(t->gender == 1)
			 answer += "grandfather";
		else answer += "grandmother";
	return answer;
	}
	return EXIT;
}

string Tree::find(string relat){
	if(relat == string("me"))
		return this->name;
	
	if(relat == string("father")){
		if(this->father != NULL)
			return this->father->name;
		throw runtime_error("Not find");
	}

	if(relat == string("mother")){
		if(this->mother != NULL)
			return this->mother->name;
		throw runtime_error("Not find");
	}

	if(goodRelation(relat)){
		size_t f = relat.find("grandfather");
		if((f >= 0) && (f < relat.length())){
			f = f/6; // How many times "great-" appear
			f = f + 2;
			ans = findRelation(this,f,1);
			if(ans != "")
				return ans;
			throw runtime_error("failed");
		}
		else{
			size_t m = relat.find("grandmother");
			if((m >= 0) && m < relat.length()){
				m = m/6; // How many times "great-" appear
				m += 2;
				ans = findRelation(this,m,2);
				if(ans != "")
					return ans;
				throw runtime_error("failed");
			}
			else throw runtime_error("Wrong relation !"); 
		}
	}
	else throw runtime_error("Wrong relation !"); 
	
}

void Tree::remove(string name){
	if(this->name == string(name))
		throw runtime_error("Can't remove root");
	
	Tree* t = personInTree(this, name);
	Tree* tmp;
	tmp = t->child;
	int g = t->gender;

	delete t;
	if(g == 1) tmp->father = NULL;
	else tmp->mother = NULL;
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
 * Check if put a correct string of relation
 *
 * CALLED BY -> Tree::find 
 */
bool Tree::goodRelation(string relat){
	if((relat == string("grandfather")) || (relat == string("grandmother")))
		return true;
	size_t m = relat.find("grandmother");
	if((m >= 0) && (m < relat.length())) {
		for (int i = 0; i < m; i++){
			if(i%6 == 0){
				if(relat[i] != 'g') return false;
			}
			else if(i%6 == 1){
				if(relat[i] != 'r') return false;
			}
			else if(i%6 == 2){
				if(relat[i] != 'e') return false;
			}
			else if(i%6 == 3){
				if(relat[i] != 'a') return false;
			}
			else if(i%6 == 4){
				if(relat[i] != 't') return false;
			}
			else if(i%6 == 5){
				if(relat[i] != '-') return false;
			}
		}
	}
	m = relat.find("grandfather");
	if((m >= 0) && (m < relat.length())){
		for (int i = 0; i < m; i++){
			if(i%6 == 0){
				if(relat[i] != 'g') return false;
			}
			else if(i%6 == 1){
				if(relat[i] != 'r') return false;
			}
			else if(i%6 == 2){
				if(relat[i] != 'e') return false;
			}
			else if(i%6 == 3){
				if(relat[i] != 'a') return false;
			}
			else if(i%6 == 4){
				if(relat[i] != 't') return false;
			}
			else if(i%6 == 5){
				if(relat[i] != '-') return false;
			}
		}
	} 
	return true;
}

/**
 * findRelation
 * @param num => define how many times I need to jump
 * @param gender => 1 for man, 2 for woman
 * @example
 * if I want to fing the grandfather.
 * I need to jump a first time to father/mother
 * and one more time to grandfather
 * 
 * CALLED BY -> Tree::find
 * @return The name of who I am looking for
 */
string Tree::findRelation(Tree* t, size_t num, unsigned int gender){ 
	
	switch(num)
	{
		case 1:
		if(gender == 1){ // man
			if(t->father != NULL)
				return t->father->name;
			num++;
			return "";
		}
		else{ // gender == 2 -> woman
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

/**
 * personInTree
 * @param name
 * like post-order
 * 
 * CALLED BY -> Tree::relation
 * @return Tree* who I search 
 */
Tree* Tree::personInTree(Tree* t, string name){
	if(t->father != NULL)
		t = personInTree(t->father, name);
	if(t->mother != NULL)
		t = personInTree(t->mother, name);
	if(t->name == string(name))
		return t;
	return t->child;
}

// // Function to print binary tree in 2D
// // It does reverse inorder traversal
// // from www.geeksforgeeks.org
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
// // from www.geeksforgeeks.org
// void print2D(Tree *root){
//     // Pass initial space count as 0
//     print2DUtil(root, 0);
// }
