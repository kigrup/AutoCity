#include "item.h"

Item::Item() {
    id = 0;
    name = "item";
    count = 1;
}

Item::Item(int id, std::string name, int count) {
    this->id = id;
    this->name = name;
    this->count = count;
}

void Item::Add(int c){
    count += c;
}


