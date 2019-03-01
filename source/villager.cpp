#include "villager.h"

Villager::Villager(int x, int y, Info info, Properties& properties, Item& money, std::string SpritePath, SDL_Renderer * gRenderer) {
    pos_x = x;
    pos_y = y;
    this->info = info;
    vProperties = properties;
    this->money = money;
    
    sprite.loadFromFile(SpritePath, gRenderer);
}

Villager::~Villager() {
    sprite.free();
}

int Villager::getProperty(std::string property) {
    if (property == "hunger") return vProperties.hunger;
    else if (property == "sleep") return vProperties.sleep;
    else if (property == "toilet") return vProperties.toilet;
    else return vProperties.fun;
}

void Villager::setProperty(std::string property, int value) {
    if (property == "hunger") vProperties.hunger = value;
    else if (property == "sleep") vProperties.sleep = value;
    else if (property == "toilet") vProperties.toilet = value;
    else vProperties.fun = value;
}

bool Villager::isSick() {
    return vProperties.sick;
}

void Villager::SetPos(int x, int y) {
    pos_x = x;
    pos_y = y;
}

void Villager::Render(SDL_Renderer * gRenderer) {
    sprite.render(pos_x, pos_y, NULL, gRenderer);
}

void Villager::CheckProperties() {
    if (vProperties.hunger <= 0) Die();
}

void Villager::Die() {
    this->~Villager();
}
