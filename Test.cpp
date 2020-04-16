#include <iostream>
#include <string>

#include "doctest.h"
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

//////////////////////////////////////////////////////
/////////////////////// FAMILLY //////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


Tree build(string n){
    Tree t(n);
    t.addFather(n, "Emmanuel");
    t.addMother(n, "Lea");
    t.addFather("Emmanuel", "Meir");
    t.addMother("Emmanuel", "Tali");
    t.addFather("Meir", "Chalom");
    t.addMother("Meir", "Yvette");
    t.addFather("Lea", "Sarah");
    t.addMother("Lea", "Avraham");
    t.addFather("Tali", "Marcell");
    t.addMother("Tali", "Michael");
    t.addMother("Michael", "Shoshana");
    return t;
}
Tree t = build("shany");

TEST_CASE("test of function relation"){
    CHECK(t.relation("Shany") == string("me"));
    CHECK(t.relation("Emmanuel") == string("father"));
    CHECK(t.relation("Lea") == string("mother"));
    CHECK(t.relation("Sarah") == string("grandmother"));
    CHECK(t.relation("Avraham") == string("grandfather"));
    CHECK(t.relation("Meir") == string("grandfather"));
    CHECK(t.relation("Yvette") == string("great-grandmother"));
    CHECK(t.relation("Michael") == string("great-grandfather"));
}

TEST_CASE("test of function find"){
    CHECK(t.find("me") == string("Shany"));
    CHECK(t.find("father") == string("Emmanuel"));
    CHECK(t.find("mother") == string("Lea"));
    CHECK((t.find("grandmother") == string("Tali") || t.find("grandmother") == string("Sarah")));
    CHECK((t.find("grandfather") == string("Meir") || t.find("grandfather") == string("Avraham")));
    CHECK((t.find("great-grandfather") == string("Yvette") || t.find("great-grandfather") == string("Marcell")));
    CHECK(t.find("great-great-grandmother") == string("Shoshana"));
}

TEST_CASE("test if remove worked"){
    t.remove("Emmanuel");
    CHECK(t.relation("Meir") == string("unrelated"));
    CHECK(t.relation("Tali") == string("unrelated"));
    CHECK(t.relation("Yvette") == string("unrelated"));
    CHECK(t.relation("Shoshana") == string("unrelated"));
    CHECK(t.relation("Michael") == string("unrelated"));
}

TEST_CASE("test of wrong find"){
    CHECK(t.find("uncle") == string("unrelated"));
    CHECK(t.find("cousin") == string("unrelated"));
    CHECK(t.find("brother") == string("unrelated"));
    CHECK(t.find("sister") == string("unrelated"));
}



//////////////////////////////////////////////////////
/////////////////////// Israel ///////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


Tree Israelbuild(string n){
    Tree t(n);
    t.addFather(n, "Yaakov");
    t.addMother(n, "Lea");
    t.addFather("Yaakov", "Itshak");
    t.addMother("Yaakov", "Rivka");
    t.addFather("Itshak", "Avraham");
    t.addMother("Itshak", "Sarah");
    t.addFather("Avraham", "Terah");
    t.addFather("Rivka", "Betuel");
    return t;
}

Tree Israel = Israelbuild("Reuven");

TEST_CASE("test of function relation"){
    CHECK(Israel.relation("Reuven") == string("me"));
    CHECK(Israel.relation("Yaakov") == string("father"));
    CHECK(Israel.relation("Lea") == string("mother"));
    CHECK(Israel.relation("Rivka") == string("grandmother"));
    CHECK(Israel.relation("Itzhak") == string("grandfather"));
    CHECK(Israel.relation("Avraham") == string("great-grandfather"));
    CHECK(Israel.relation("Lavane") == string("grandfather"));
    CHECK(Israel.relation("betuel") == string("great-great-grandfather"));
}

TEST_CASE("test of function find"){
    CHECK(Israel.find("me") == string("Reuven"));
    CHECK(Israel.find("father") == string("Yaakov"));
    CHECK(Israel.find("mother") == string("Lea"));
    CHECK(Israel.find("grandmother") == string("Rivka"));
    CHECK((Israel.find("grandfather") == string("Itshak") || t.find("grandfather") == string("Lavane")));
    CHECK((Israel.find("great-grandfather") == string("Avraham") || t.find("great-grandfather") == string("Betuel")));
    CHECK(Israel.find("great-great-grandfather") == string("Terah"));
}

TEST_CASE("test if remove worked"){
    Israel.remove("Itshak");
    CHECK(Israel.relation("Itshak") == string("unrelated"));
    CHECK(Israel.relation("Avraham") == string("unrelated"));
    CHECK(Israel.relation("Sarah") == string("unrelated"));
    CHECK(Israel.relation("Terah") == string("unrelated"));
    CHECK(Israel.relation("Betuel") == string("unrelated"));
}

//////////////////////////////////////////////////////
/////////////////////// KINGDOM //////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

Tree Kingdombuild(string n){
    Tree t(n);
    t.addFather(n, "Assa");
    t.addFather("Assa", "Avia");
    t.addFather("Avia", "Rehavam");
    t.addFather("Rehavam", "Shelomo");
    t.addFather("Shelomo", "David");
    t.addFather("Shelomo", "Elisheva");
    return t;
}

Tree Kingdom = Kingdombuild("Yehoshfat");
    
TEST_CASE("test of function relation"){
    CHECK(Kingdom.relation("Yehoshfat") == string("me"));
    CHECK(Kingdom.relation("Assa") == string("father"));
    CHECK(Kingdom.relation("Avia") == string("grandfather"));
    CHECK(Kingdom.relation("Rehavam") == string("great-grandfather"));
    CHECK(Kingdom.relation("Shelomo") == string("great-great-grandfather"));
    CHECK(Kingdom.relation("David") == string("great-great-great-grandfather"));
    CHECK(Kingdom.relation("Elisheva") == string("great-great-great-grandmother"));
}

TEST_CASE("test of function find"){
    CHECK(Kingdom.find("me") == string("Yehoshfat"));
    CHECK(Kingdom.find("father") == string("Assa"));
    CHECK(Kingdom.find("grandfather") == string("Avia"));
    CHECK(Kingdom.find("great-grandfather") == string("Rehavam"));
    CHECK(Kingdom.find("great-great-grandfather") == string("Shelomo"));
    CHECK(Kingdom.find("great-great-great-grandfather") == string("David"));
    CHECK(Kingdom.find("great-great-great-grandmother") == string("Elisheva"));
}

TEST_CASE("test of wrong relation"){
    CHECK(Kingdom.relation("Shmouel") == string("unrelated"));
    CHECK(Kingdom.relation("Noa") == string("unrelated"));
    CHECK(Kingdom.relation("Yeoshoua") == string("unrelated"));
    CHECK(Kingdom.relation("Shimon") == string("unrelated"));
    CHECK(Kingdom.relation("Eliezer") == string("unrelated"));
    CHECK(Kingdom.relation("Binyamin") == string("unrelated"));
    CHECK(Kingdom.relation("Shaoul") == string("unrelated"));
    CHECK(Kingdom.relation("Yerovam") == string("unrelated"));
    CHECK(Kingdom.relation("Yshay") == string("unrelated"));
}

TEST_CASE("test of wrong find"){
    CHECK(Kingdom.find("mother") == string("unrelated"));
    CHECK(Kingdom.find("uncle") == string("unrelated"));
    CHECK(Kingdom.find("cousin") == string("unrelated"));
    CHECK(Kingdom.find("brother") == string("unrelated"));
    CHECK(Kingdom.find("sister") == string("unrelated"));
    CHECK(Kingdom.find("grandmother") == string("unrelated"));
    CHECK(Kingdom.find("great-grandmother") == string("unrelated"));
    CHECK(Kingdom.find("great-great-grandmother") == string("unrelated"));
}


/////////////////////////////////////////////////////
//////////////////// KookFamilly ////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


Tree Kookmbuild(string n){
    Tree t(n);
    t.addFather(n, "Avraham");
    t.addMother(n, "Rivka");
    t.addFather("Avraham", "Shelomo");
    t.addMother("Avraham", "Farel");
    t.addFather("Shelomo", "Nahume");
    return t;
}

Tree KookFamilly = Kookmbuild("Tzvi");

TEST_CASE("test of function relation"){
    CHECK(KookFamilly.relation("Tzvi") == string("me"));
    CHECK(KookFamilly.relation("Avraham") == string("father"));
    CHECK(KookFamilly.relation("Rivka") == string("Mother"));
    CHECK(KookFamilly.relation("Shelomo") == string("grandfather"));
    CHECK(KookFamilly.relation("Farel") == string("grandmother"));
    CHECK(KookFamilly.relation("Nahume") == string("great-grandfather"));
}

TEST_CASE("test of function find"){
    CHECK(KookFamilly.find("me") == string("Tzvi"));
    CHECK(KookFamilly.find("father") == string("Avraham"));
    CHECK(KookFamilly.find("mother") == string("Rivka"));
    CHECK(KookFamilly.find("grandfather") == string("Shelomo"));
    CHECK(KookFamilly.find("grandmother") == string("Farel"));
    CHECK(KookFamilly.find("great-grandfather") == string("Nahume"));
}

TEST_CASE("test of wrong relation"){
    CHECK(KookFamilly.relation("Emmanuel") == string("unrelated"));
    CHECK(KookFamilly.relation("Lea") == string("unrelated"));
    CHECK(KookFamilly.relation("Moshe") == string("unrelated"));
    CHECK(KookFamilly.relation("Natan") == string("unrelated"));
    CHECK(KookFamilly.relation("Rahel") == string("unrelated"));
    CHECK(KookFamilly.relation("Aaron") == string("unrelated"));
    CHECK(KookFamilly.relation("Adam") == string("unrelated"));
}

TEST_CASE("test of wrong find"){
    CHECK(KookFamilly.find("uncle") == string("unrelated"));
    CHECK(KookFamilly.find("cousin") == string("unrelated"));
    CHECK(KookFamilly.find("brother") == string("unrelated"));
    CHECK(KookFamilly.find("sister") == string("unrelated"));
    CHECK(KookFamilly.find("great-grandmother") == string("unrelated"));
    CHECK(KookFamilly.find("great-great-grandmother") == string("unrelated"));
}
