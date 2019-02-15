#ifndef villager_h
#define villager_h

#include "item.h"

struct Properties {
    int hunger;
    int sleep;
    int toilet;
    int fun;
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
    
public:
    Villager(Info info, Properties properties, Item money);
    ~Villager();
};

#endif /* villager_h */
