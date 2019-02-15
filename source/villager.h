#ifndef villager_h
#define villager_h

#include "item.h"

struct Properties {
    /*
     *  hambre
     *  sueño
     *  aseo
     *  relaciones
     *  ocio
     *
     *
     */
};

struct Info {
    //id, nombre, edad, genero, edad maxima
};

class Villager {
private:
    //id, stats
    Item money;
    
public:
    Villager();
    ~Villager();
};

#endif /* villager_h */
