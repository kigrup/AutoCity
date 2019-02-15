#include "villager.h"

Villager::Villager(Info info, Properties properties, Item money, std::string SpritePath, SDL_Renderer * gRenderer) {
    this->info = info;
    this->properties = properties;
    this->money = money;
    
    sprite.loadFromFile(SpritePath, gRenderer);
}
