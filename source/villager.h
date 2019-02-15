#ifndef villager_h
#define villager_h

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
    Properties properties;
    
    LTexture sprite;
    
    int pos_x, pos_y;
    
public:
    Villager(int x, int y, Info info, Properties properties, Item& money, std::string SpritePath, SDL_Renderer * gRenderer);
    ~Villager();
    
    void Render(SDL_Renderer * gRenderer);
    
    void CheckProperties();
    
    void Die();
};

#endif /* villager_h */
