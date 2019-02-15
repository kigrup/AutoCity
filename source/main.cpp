#include <iostream>
#include "LTexture.h"
#include "LTimer.h"
#include "villager.h"
#include "game.h"

int main(int argc, char * argv[]) {
    if (!init()) {
        std::cout << "Algo ha fallado" << std::endl;
        return 0;
    }
    
    Info info;
    Properties properties;
    Item money;
    
    Villager villager(0, 0, info, properties, money, "assets/sprites/owo.png", gRenderer);
    
    SDL_Event e;
    
    LTimer fpsTimer;
    
    bool quit = false;
    
    while (!quit) {
        
        fpsTimer.start();
        
        while (SDL_PollEvent( &e ) != 0) {
            
            //std::cout << "Event loop starts!" << std::endl;
            
            if( e.type == SDL_QUIT ) quit = true;
            
            if (e.type == SDL_KEYDOWN) {}
        
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);
        
            villager.Render(gRenderer);
            
            SDL_RenderPresent(gRenderer);
            
            int frameTicks = fpsTimer.getTicks();
            if( frameTicks < TICK_PER_FRAME )
            {
                //Wait remaining time
                SDL_Delay( TICK_PER_FRAME - frameTicks );
            }
        }
        
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);
    
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
