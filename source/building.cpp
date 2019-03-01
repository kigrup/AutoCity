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
    
}
