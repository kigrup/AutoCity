#include "item.h"

Item::Item(int id, std::string name, int count) {
    this->id = id;
    this->name = name;
    this->count = count;
}

void Item::Add(int c){
    count += c;
}


