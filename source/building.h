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
    
    std::vector<Villager*> b_Villager;
    
public:
    Building(int id, std::vector<std::string>& recovery, int max, std::string path);
    
    void villagerIn(Villager * bVillager);
};


#endif /* building_h */
