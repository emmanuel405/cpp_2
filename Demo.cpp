/**
 * Demo for Family Tree
 * 
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"
#include <iostream>

using namespace std;
using namespace family;

int main() {
	Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov");   // Tells the tree that the father of Yosef is Yaakov.
	T.addMother("Yosef", "Rachel");   // Tells the tree that the mother of Yosef is Rachel.
	T.addFather("Rachel", "Isaac");
	T.addMother("Rachel", "Rivka");
	T.addFather("Isaac", "Avraham");
	T.addFather("Avraham", "Terah");

	cout << "result:" << endl;
	cout << T.father->mother->name << endl;
	/**
	 * 						Yosef	
	 * 				Rachel			Yaakov
	 * 			Isaac	Rivka  
	 *		Avraham
	 *	 Terah
	 */

	cout << "find: should print Isaac" << endl;  // prints "Rachel"
	// cout << T.find("mother") << endl;  // prints "Rachel"
	cout << T.find("grandfather") << endl;
	
	// //T.display();                        // displays the tree in a human-friendly format.

	// cout << T.relation("Yaakov") << endl;  // prints "father"
	// cout << T.relation("Rachel") << endl;  // prints "mother"
	// cout << T.relation("Rivka") << endl;  // prints "grandmother"
	// cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
	// cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
	// cout << T.relation("xyz") << endl;  // prints "unrelated"
	// cout << T.relation("Yosef") << endl;  // prints "me"
	// cout << T.find("great-great-grandfather") << endl;  // prints "Avraham"

	// try {
	// 	cout << T.find("uncle") << endl;  // throws an exception
	// } catch (const exception& ex) {
	//  	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
	// }

	// T.remove("Avraham"); // removes Avraham and Terah
	// cout << T.relation("Terah") << endl;  // prints "unrelated"

    return 0;
}
