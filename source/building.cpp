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

void Building::reordenar() 
{ 
    int count = 0;  // Count of non-zero elements 
    int n = vec.size();
    // Traverse the array. If element encountered is non- 
    // zero, then replace the element at index 'count'  
    // with this element 
    for (int i = 0; i < n; i++) 
        if (vec[i] != NULL) 
            vec[count++] = vec[i]; // here count is  
                                   // incremented 
  
    // Now all non-zero elements have been shifted to  
    // front and  'count' is set as index of first 0.  
    // Make all elements 0 from count to end. 
    while (count < n) 
        vec[count++] = NULL; 
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
            reordenar();
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
