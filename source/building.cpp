#include "building.h"

Building::Building(int id, std::vector<Recovery>& recovery, int max, std::string path, SDL_Renderer * gRenderer)
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

void Building::reordenar() 
{
    //Funcion que reorganiza el bVillager para que los
    //NULL se queden al final
    int count = 0;
    unsigned long n = bVillager.size();
    for (int i = 0; i < n; i++) 
        if (bVillager[i] != NULL)
            bVillager[count++] = bVillager[i];
    while (count < n) 
        bVillager[count++] = NULL;
} 

void Building::villagerIn(Villager * bVillager) {
    if (lastVillager < MAX_PEOPLE - 1) {
        this->bVillager[lastVillager++] = bVillager;
    }
}

void Building::villagerOut(Villager * bVillager) {
    bool found = false;
    for (int i = 0; i <= lastVillager; ++i) {
        if (this->bVillager[i] == bVillager) {
            found = true;
            this->bVillager[i] = NULL;
            --lastVillager;
            reordenar();
            break;
        }
    }
    if (!found)
        std::cout << "No se ha encontrado el villager dentro del edificio #" << id << std::endl;
}

void Building::recover() {
    for (int i = 0; i < recovery.size(); ++i) {
        for (int j = 0; j <= lastVillager; ++j) {
            int rec = bVillager[i]->getProperty(recovery[i].name);
            if (rec < 100) rec += recovery[i].speed;
            if (rec > 100) rec = 100;
            bVillager[i]->setProperty(recovery[i].name, rec);
        }
    }
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
