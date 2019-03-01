#ifndef villager_h
#define villager_h

#include <iostream>
#include "item.h"
#include "LTexture.h"

struct Properties {
    int hunger;
    int sleep;
    int toilet;
    int fun;
    bool sick;
    //relaciones
};

struct Info {
    int id;
    std::string name;
    int age;
    int gender; //1 = male, 2 = female, 3 = others
    //edad maxima
};

class Villager {
private:
    Item money;
    Info info;
    Properties vProperties;
    
    LTexture sprite;
    
    int pos_x, pos_y;
    
    SDL_Renderer * vRenderer;
    
public:
    Villager(int x, int y, Info info, Properties& properties, Item& money, std::string SpritePath, SDL_Renderer * gRenderer);
    ~Villager();
    
    int getProperty(std::string property);
    
    void setProperty(std::string property, int value);
    
    bool isSick();
    
    void setPos(int x, int y);
    
    void render();
    
    void checkProperties();
    
    void die();
};

#endif /* villager_h */
