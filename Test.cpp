#include <iostream>
#include <string>

#include "doctest.h"
#include "FamilyTree.cpp"

using namespace std;


//////////////////////////////////////////////////////
/////////////////////// FAMILLY //////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


family::Tree t ("Shany");
    t.addFather("Shany", "Emmanuel"));
    .addMother("Shany", "Lea"));
    .addFather("Emmanuel", "Meir"));
    .addMother("Emmanuel", "Tali"));
    .addFather("Meir", "Chalom"));
    .addMother("Meir", "Yvette"));
    .addFather("Lea", "Sarah"));
    .addMother("Lea", "Avraham"));
    .addFather("Tali", "Marcell"));
    .addMother("Tali", "Michael"));
    .addMother("Michael", "Shoshana"));

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
    CHECK(t.find("grandfather") == string("Meir") t.find("grandfather") == string("Avraham"));
    CHECK((t.find("great-grandfather") == string("Yvette") || t.find("great-grandfather") == string("Marcell")));
    CHECK(t.find("great-great-grandmother") == string("Shoshana"));
}

TEST_CASE("test if remove worked"){
    t.remove("Emmanuel");
    CHECK(t.find("Meir") == string("unrelated"));
    CHECK(t.find("Tali") == string("unrelated"));
    CHECK(t.find("Yvette") == string("unrelated"));
    CHECK(t.find("Shoshana") == string("unrelated"));
    CHECK(t.find("Michael") == string("unrelated"));
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


family::Tree Israel ("Reuven");
    Israel.addFather("Reuven", "Yaakov");
    .addMother("Reuven", "Lea");
    .addFather("Yaakov", "Itshak");
    .addMother("Yaakov", "Rivka");
    .addFather("Itshak", "Avraham");
    .addMother("Itshak", "Sarah");
    .addFather("Avraham", "Terah");
    .addFather("Rivka", "Betuel");

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
    CHECK(Israel.find("Itshak") == string("unrelated"));
    CHECK(Israel.find("Avraham") == string("unrelated"));
    CHECK(Israel.find("Sarah") == string("unrelated"));
    CHECK(Israel.find("Terah") == string("unrelated"));
    CHECK(Israel.find("Betuel") == string("unrelated"));
}

//////////////////////////////////////////////////////
/////////////////////// KINGDOM //////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


family::Tree Kingdom ("Yehoshfat");
    Kingdom.addFather("Yehoshfat", "Assa");
    .addFather("Assa", "Avia");
    .addFather("Avia", "Rehavam");
    .addFather("Rehavam", "Shelomo");
    .addFather("Shelomo", "David");
    .addFather("Shelomo", "Elisheva");

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
    CHECK(Kingdom.find("Shmouel") == string("unrelated"));
    CHECK(Kingdom.find("Noa") == string("unrelated"));
    CHECK(Kingdom.find("Yeoshoua") == string("unrelated"));
    CHECK(Kingdom.find("Shimon") == string("unrelated"));
    CHECK(Kingdom.find("Eliezer") == string("unrelated"));
    CHECK(Kingdom.find("Binyamin") == string("unrelated"));
    CHECK(Kingdom.find("Shaoul") == string("unrelated"));
    CHECK(Kingdom.find("Yerovam") == string("unrelated"));
    CHECK(Kingdom.find("Yshay") == string("unrelated"));
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

family::Tree KookFamilly ("Tzvi");
    KookFamilly.addFather("Tzvi", "Avraham");
    .addMother("Tzvi", "Rivka");
    .addFather("Avraham", "Shelomo");
    .addMother("Avraham", "Farel");
    .addFather("Shelomo", "Nahume");


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
    CHECK(KookFamilly.find("Emmanuel") == string("unrelated"));
    CHECK(KookFamilly.find("Lea") == string("unrelated"));
    CHECK(KookFamilly.find("Moshe") == string("unrelated"));
    CHECK(KookFamilly.find("Natan") == string("unrelated"));
    CHECK(KookFamilly.find("Rahel") == string("unrelated"));
    CHECK(KookFamilly.find("Aaron") == string("unrelated"));
    CHECK(KookFamilly.find("Adam") == string("unrelated"));
}

TEST_CASE("test of wrong find"){
    CHECK(KookFamilly.find("uncle") == string("unrelated"));
    CHECK(KookFamilly.find("cousin") == string("unrelated"));
    CHECK(KookFamilly.find("brother") == string("unrelated"));
    CHECK(KookFamilly.find("sister") == string("unrelated"));
    CHECK(KookFamilly.find("great-grandmother") == string("unrelated"));
    CHECK(KookFamilly.find("great-great-grandmother") == string("unrelated"));
}
