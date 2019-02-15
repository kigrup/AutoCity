#ifndef item_h
#define item_h

#include <string>

class Item {
private:
    int id;
    std::string name;
    int count;
public:
    Item();
    ~Item();
};

#endif /* item_h */
