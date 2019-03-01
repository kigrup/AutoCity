#include <iostream>
#include "LTexture.h"
#include "LTimer.h"
#include "villager.h"
#include "building.h"
#include "game.h"

int main(int argc, char * argv[]) {
    if (!init()) {
        std::cout << "Algo ha fallado" << std::endl;
        return 0;
    }
    
    Info info;
    Properties properties;
    Item money;
    
    properties.hunger = 0;
    properties.sleep = 0;
    properties.toilet = 0;
    properties.fun = 0;
    properties.sick = false;
    
    std::vector<Recovery> rec;
    Recovery rect;
    rect.name = "hunger";
    rect.speed = 1;
    rec.push_back(rect);
    
    Villager villager(0, 0, info, properties, money, "assets/sprites/owo.png", gRenderer);
    Building building(0, rec, 2, "assets/sprites/owo.png", gRenderer);
    
    building.villagerIn(&villager);
    
    int x = 0;
    int y = 0;
    
    SDL_Event e;
    
    LTimer fpsTimer;
    
    bool quit = false;
    
    while (!quit) {
        
        fpsTimer.start();
        
        while (SDL_PollEvent( &e ) != 0) {
            
            //std::cout << "Event loop starts!" << std::endl;
            
            if( e.type == SDL_QUIT ) quit = true;
            
            if (e.type == SDL_KEYDOWN) {
                building.villagerOut(NULL);
            }
        
            /*SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);
        
            villager.Render(gRenderer);
            
            SDL_RenderPresent(gRenderer);*/
            
            int frameTicks = fpsTimer.getTicks();
            if( frameTicks < TICK_PER_FRAME )
            {
                //Wait remaining time
                SDL_Delay( TICK_PER_FRAME - frameTicks );
            }
        }
        ++x; ++y;
        villager.SetPos(x, y);
        building.recover();
        
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);
    
        building.render(10, 10);
        villager.Render(gRenderer);
    
        SDL_RenderPresent(gRenderer);
        
        int frameTicks = fpsTimer.getTicks();
        if( frameTicks < TICK_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( TICK_PER_FRAME - frameTicks );
        }
    }
    
    IMG_Quit();
    SDL_Quit();
    return 0;
}
