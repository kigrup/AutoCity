#include "building.h"

Building::Building(int id, std::vector<std::string>& recovery, int max, std::string path, SDL_Renderer * gRenderer)
{
	this->id = id;
	this->recovery = recovery;
	MAX_PEOPLE = max;
	bRenderer = gRenderer;
    
    for (int i = 0; i < MAX_PEOPLE; ++i) {
        bVillager.push_back(NULL);
    }

	sprite.loadFromFile(path,gRenderer);
}

void Building::villagerIn(Villager * bVillager) {
    if (lastVillager < MAX_PEOPLE - 1) {
        ++lastVillager;
        this->bVillager[lastVillager] = bVillager;
    }
}

void Building::villagerOut(Villager * bVillager) {
    bool found = false;
    for (int i = 0; i <= lastVillager; ++i) {
        if (this->bVillager[i] == bVillager) {
            found = true;
            this->bVillager[i] = NULL;
            --lastVillager;
            //funcion ordenar
            break;
        }
    }
    if (!found)
        std::cout << "No se ha encontrado el villager dentro del edificio #" << id << std::endl;
}

void Building::render(int x, int y) {
    sprite.render(x, y, NULL, bRenderer);
}

void Building::free() {
    sprite.free();
    bRenderer = NULL;
}

Building::~Building() {
    free();
}
