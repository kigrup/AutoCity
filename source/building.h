#ifndef building_h
#define building_h

#include <iostream>
#include <string>
#include <vector>
#include "LTexture.h"
#include "villager.h"

struct Recovery {
    std::string name; ///Nombre de la propiedad a regenerar
    int speed;        ///Velocidad de recuperacion
};

class Building {
private:
    int id;
    std::vector<Recovery> recovery;
    int MAX_PEOPLE;
    int lastVillager = 0;
    
    LTexture sprite;
    
    std::vector<Villager*> bVillager;
    
    SDL_Renderer * bRenderer;
    
    void reordenar();
    
public:
    Building(int id, std::vector<Recovery>& recovery, int max, std::string path, SDL_Renderer * gRenderer);    // constructora
    
    void villagerIn(Villager * bVillager);
    
    void recover();
    
    void villagerOut(Villager * bVillager);
    
    void render(int x, int y);     // ensenamelo papi
    
    void free();  // liberar textura
    
    ~Building();    // destructora
};


#endif /* building_h */
