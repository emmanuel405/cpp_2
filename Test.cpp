#include <iostream>
#include <string>

#include "doctest.h"
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

// Tree* tree_familly(string n){
//     Tree *t = new Tree(n);
//     CHECK_NOTHROW(t->addFather(n, "Emmanuel"));
//     CHECK_NOTHROW(t->addMother(n, "Lea"));
//     CHECK_NOTHROW(t->addFather("Emmanuel", "Meir"));
//     CHECK_NOTHROW(t->addMother("Emmanuel", "Tali"));
//     CHECK_NOTHROW(t->addFather("Meir", "Chalom"));
//     CHECK_NOTHROW(t->addMother("Meir", "Yvette"));
//     CHECK_NOTHROW(t->addFather("Lea", "Avraham"));
//     CHECK_NOTHROW(t->addMother("Lea", "Sarah"));
//     CHECK_NOTHROW(t->addFather("Tali", "Michael"));
//     CHECK_NOTHROW(t->addMother("Tali", "Marcell"));
//     CHECK_NOTHROW(t->addMother("Michael", "Shoshana"));
//     return t;
// }

// TEST_CASE("test of function display") {
//     Tree *t_display;
//     CHECK_NOTHROW(t_display = tree_familly("Shany"));
//     CHECK_NOTHROW(t_display->display()); 
// }

TEST_CASE("test of function addFather"){
    Tree l("Moshe");
    CHECK_NOTHROW(l.addFather("Moshe", "Levi"));
    CHECK_THROWS(l.addFather("Moshe", "Amram"));
    // l.remove("Levi");
    // CHECK_THROWS(l.addFather("Moshe", "Amram"));
    // CHECK_THROWS(l.addFather("Amram", "Kehat"));
    // CHECK_THROWS(l.addFather("Kehat", "Levi"));
    CHECK(l.find("me") == string("Moshe"));
    CHECK(l.find("father") == string("Amram"));
    CHECK(l.find("grandfather") == string("Kehat"));

//     CHECK(l.relation("Moshe") == string("me"));
//     CHECK(l.relation("Amram") == string("father"));
//     CHECK(l.relation("Kehat") == string("grandfather"));
//     CHECK(l.relation("Levi") == string("great-grandfather"));
}

// TEST_CASE("test of function addMother"){
//     Tree m("Sarah");
//     CHECK_NOTHROW(m.addMother("Sarah", "Hana"));
//     CHECK_NOTHROW(m.addMother("Hana", "Miryam"));
//     CHECK_NOTHROW(m.addMother("Miryam", "Lea"));
//     CHECK_NOTHROW(m.addMother("Lea", "Esther"));
//     CHECK_THROWS(m.addMother("Lea", "Rivka"));
    
//     CHECK(m.find("me") == string("Sarah"));
//     CHECK(m.find("mother") == string("Hana"));
//     CHECK(m.find("grandmother") == string("Miryam"));
//     CHECK(m.find("great-grandmother") == string("Lea"));

//     CHECK(m.relation("Sarah") == string("me"));
//     CHECK(m.relation("Hana") == string("mother"));
//     CHECK(m.relation("Miryam") == string("grandmother"));
//     CHECK(m.relation("Esther") == string("great-great-grandfather"));

//     m.remove("Lea");
//     CHECK_THROWS(m.find("Lea"));
//     CHECK_THROWS(m.find("Esther"));
// }

// TEST_CASE("test of wrong find"){
//     Tree *t_f = tree_familly("Shany");
//     CHECK(t_f->find("uncle") == string("unrelated"));
//     CHECK(t_f->find("cousin") == string("unrelated"));
//     CHECK(t_f->find("brother") == string("unrelated"));
//     CHECK(t_f->find("sister") == string("unrelated"));
// }

// //////////////////////////////////////////////////////
// /////////////////////// Israel ///////////////////////
// //////////////////////////////////////////////////////
// //////////////////////////////////////////////////////


// Tree* AmIsrael(string n){
//     Tree *a_i = new Tree(n);
//     CHECK_NOTHROW(a_i->addFather(n, "Yaakov"));
//     CHECK_NOTHROW(a_i->addMother(n, "Lea"));
//     CHECK_NOTHROW(a_i->addFather("Yaakov", "Itshak"));
//     CHECK_NOTHROW(a_i->addMother("Yaakov", "Rivka"));
//     CHECK_NOTHROW(a_i->addFather("Itshak", "Avraham"));
//     CHECK_NOTHROW(a_i->addMother("Itshak", "Sarah"));
//     CHECK_NOTHROW(a_i->addFather("Rivka", "Betuel"));
//     CHECK_NOTHROW(a_i->addFather("Avraham", "Terah"));
//     CHECK_NOTHROW(a_i->addMother("Avraham", "Amtalay"));
//     CHECK_NOTHROW(a_i->addMother("Amtalay", "Karnevo"));
//     return a_i;
// }

// TEST_CASE("test of function relation & find"){
//     Tree *Israel = tree_familly("Reuven");
//     CHECK(Israel->relation("Reuven") == string("me"));
//     CHECK(Israel->relation("Yaakov") == string("father"));
//     CHECK(Israel->relation("Lea") == string("mother"));
//     CHECK(Israel->relation("Rivka") == string("grandmother"));
//     CHECK(Israel->relation("Itzhak") == string("grandfather"));
//     CHECK(Israel->relation("Avraham") == string("great-grandfather"));
//     CHECK(Israel->relation("betuel") == string("great-great-grandfather"));
//     CHECK(Israel->relation("Terah") == string("great-great-grandfather"));

//     CHECK(Israel->find("me") == string("Reuven"));
//     CHECK(Israel->find("father") == string("Yaakov"));
//     CHECK(Israel->find("mother") == string("Lea"));
//     CHECK(Israel->find("grandmother") == string("Rivka"));
//     CHECK((Israel->find("grandfather") == string("Itshak") || Israel->find("grandfather") == string("Lavane")));
//     CHECK((Israel->find("great-grandfather") == string("Avraham") || Israel->find("great-grandfather") == string("Betuel")));
//     CHECK(Israel->find("great-great-grandfather") == string("Terah"));

//  // test if remove worked
//     Israel->remove("Itshak");
//     CHECK_THROWS(Israel->relation("Itshak"));
//     CHECK_THROWS(Israel->relation("Avraham"));
//     CHECK_THROWS(Israel->relation("Sarah"));
//     CHECK_THROWS(Israel->relation("Terah"));
//     CHECK_THROWS(Israel->relation("Betuel"));
//     CHECK_THROWS(Israel->relation("Amtalay"));
//     CHECK_THROWS(Israel->relation("Karnevo"));
// }

// //////////////////////////////////////////////////////
// /////////////////////// KINGDOM //////////////////////
// //////////////////////////////////////////////////////
// //////////////////////////////////////////////////////

// Tree* Kingdom(string n){
//     Tree *t = new Tree(n);
//     CHECK_NOTHROW(t->addFather(n, "Assa"));
//     CHECK_NOTHROW(t->addFather("Assa", "Avia"));
//     CHECK_NOTHROW(t->addFather("Avia", "Rehavam"));
//     CHECK_NOTHROW(t->addFather("Rehavam", "Shelomo"));
//     CHECK_NOTHROW(t->addFather("Shelomo", "David"));
//     CHECK_NOTHROW(t->addFather("Shelomo", "Elisheva"));
//     return t;
// }
    
// TEST_CASE("test of function relation and find"){
//     Tree Kingdom("Yehoshafat");
//     CHECK(Kingdom.relation("Yehoshafat") == string("me"));
//     CHECK(Kingdom.relation("Assa") == string("father"));
//     CHECK(Kingdom.relation("Avia") == string("grandfather"));
//     CHECK(Kingdom.relation("Rehavam") == string("great-grandfather"));
//     CHECK(Kingdom.relation("Shelomo") == string("great-great-grandfather"));
//     CHECK(Kingdom.relation("David") == string("great-great-great-grandfather"));
//     CHECK(Kingdom.relation("Elisheva") == string("great-great-great-grandmother"));

//     CHECK(Kingdom.find("me") == string("Yehoshafat"));
//     CHECK(Kingdom.find("father") == string("Assa"));
//     CHECK(Kingdom.find("grandfather") == string("Avia"));
//     CHECK(Kingdom.find("great-grandfather") == string("Rehavam"));
//     CHECK(Kingdom.find("great-great-grandfather") == string("Shelomo"));
//     CHECK(Kingdom.find("great-great-great-grandfather") == string("David"));
//     CHECK(Kingdom.find("great-great-great-grandmother") == string("Elisheva"));

//  // test of wrong relation
//     CHECK_THROWS(Kingdom.relation("Shmouel"));
//     CHECK_THROWS(Kingdom.relation("Noa"));
//     CHECK_THROWS(Kingdom.relation("Yeoshoua"));
//     CHECK_THROWS(Kingdom.relation("Shimon"));
//     CHECK_THROWS(Kingdom.relation("Eliezer"));
//     CHECK_THROWS(Kingdom.relation("Binyamin"));
//     CHECK_THROWS(Kingdom.relation("Shaoul"));
//     CHECK_THROWS(Kingdom.relation("Yerovam"));
//     CHECK_THROWS(Kingdom.relation("Yshay"));
//  // test of wrong find
//     CHECK_THROWS(Kingdom.find("mother"));
//     CHECK_THROWS(Kingdom.find("uncle"));
//     CHECK_THROWS(Kingdom.find("cousin"));
//     CHECK_THROWS(Kingdom.find("brother"));
//     CHECK_THROWS(Kingdom.find("sister"));
//     CHECK_THROWS(Kingdom.find("grandmother"));
//     CHECK_THROWS(Kingdom.find("great-grandmother"));
//     CHECK_THROWS(Kingdom.find("great-great-grandmother"));
// } // 37

// 37 + 32 + 44 = 113
