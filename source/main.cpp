#include <iostream>
#include "game.h"

int main(int argc, const char * argv[]) {
    if (!init()) {
        std::cout << "Algo ha fallado" << std::endl;
        return 0;
    }
    
}
