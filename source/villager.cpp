#include "villager.h"

Villager::Villager(int x, int y, Info info, Properties properties, Item& money, std::string SpritePath, SDL_Renderer * gRenderer) {
    pos_x = x;
    pos_y = y;
    this->info = info;
    this->properties = properties;
    this->money = money;
    
    sprite.loadFromFile(SpritePath, gRenderer);
}

Villager::~Villager() {
    sprite.free();
}

void Villager::Render(SDL_Renderer * gRenderer) {
    sprite.render(pos_x, pos_y, NULL, gRenderer);
}

void Villager::CheckProperties() {
    if (properties.hunger <= 0) Die();
}

void Villager::Die() {
    this->~Villager();
}
