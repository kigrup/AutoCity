#ifndef building_h
#define building_h

#include <iostream>
#include <string>
#include <vector>
#include "LTexture.h"
#include "villager.h"

class Building {
private:
    int id;
    std::vector<std::string> recovery;
    int MAX_PEOPLE;
    
    LTexture sprite;
    
    std::vector<Villager*> bVillager;
    
    SDL_Renderer * bRenderer;
    
public:
    Building(int id, std::vector<std::string>& recovery, int max, std::string path, SDL_Renderer * gRenderer);    // constructora
    
    void villagerIn(Villager * bVillager);
    
    void recover();
    
    void villagerOut(Villager * bVillager);
    
    void render();     // ensenamelo papi
    
    void free();  // liberar textura
    
    ~Building();    // destructora
};


#endif /* building_h */
