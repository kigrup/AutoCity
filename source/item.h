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
    Item(int id, std::string name, int count);
    void add(int c);
};

#endif /* item_h */
