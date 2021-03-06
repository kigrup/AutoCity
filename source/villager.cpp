#include "villager.h"

Villager::Villager(int x, int y, Info info, Properties& properties, Item& money, std::string SpritePath, SDL_Renderer * gRenderer) {
    pos_x = x;
    pos_y = y;
    this->info = info;
    vProperties = properties;
    this->money = money;
    
    vRenderer = gRenderer;
    
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

void Villager::setPos(int x, int y) {
    pos_x = x;
    pos_y = y;
}

void Villager::render() {
    sprite.render(pos_x, pos_y, NULL, vRenderer);
}

void Villager::checkProperties() {
    if (vProperties.health <= 0) die();
    if (!vProperties.sick) {
        if (vProperties.hunger <= 0) vProperties.sick = true;
        if (vProperties.sleep <= 0) vProperties.sick = true;
        if (vProperties.toilet <= 0) vProperties.sick = true;
        if (vProperties.fun <= 0) vProperties.sick = true;
    }
}

bool Villager::checkAllPropertiesOK() {
    return (vProperties.fun > 0) and (vProperties.hunger > 0) and (vProperties.sleep > 0) and (vProperties.toilet > 0);
}

void Villager::goToHospital() {
    if (vProperties.sick) {
        if (vProperties.health > 0 and checkAllPropertiesOK()) vProperties.sick = false;
    }
}

void Villager::die() {
    this->~Villager();
}
