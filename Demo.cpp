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
	T.addFather("Yaakov", "Isaac");
	// T.addMother("Yaakov", "Rivka");
	T.addFather("Isaac", "Avraham");
	T.addFather("Avraham", "Terah");
	// T.addFather("Rachel", "Lavane");
	// T.addFather("Lavane", "Betuel");

	cout << "result:" << endl;

	
	cout << T.relation("Terah") << endl;  // prints "unrelated"

	cout << T.relation("Yaakov") << endl;  // prints "father"
	cout << T.relation("Rachel") << endl;  // prints "mother"
	cout << T.relation("Rivka") << endl;  // prints "grandmother"
	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
	cout << T.relation("Yosef") << endl;  // prints "me"
	cout << T.find("great-great-grandfather") << endl;  // prints "Terah"
	cout << T.relation("xyz") << endl;  // prints "unrelated"
	
	cout << T.find("me") << endl;
	cout << T.find("father") << endl;
	cout << T.find("grandfather") << endl;
	cout << T.find("great-grandfather") << endl;

	
	/**
	 * 						Yosef	
	 * 				Yaakov		  		Rachel
	 * 			Isaac	Rivka    	Lavane
	 *		Avraham				 Betuel
	 *	 Terah
	 */

	cout << T.find("mother") << endl;  // prints "Rachel"
	
	cout << "Display:" << endl;  // prints "Rachel"
	T.display();                        // displays the tree in a human-friendly format.


	try {
		cout << T.find("uncle") << endl;  // throws an exception
	} catch (const exception& ex) {
	 	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
	}


    return 0;
}
