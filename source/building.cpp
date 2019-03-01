#include "building.h"

Building::Building(int id; std::vector<std::string>& recovery, int max, std::string path, SDL_Renderer * gRenderer) 
{
	this->id = id;
	this->recovery = recovery;
	MAX_PEOPLE = max;
	bRenderer = gRenderer;


	sprite.loadFromFile(path,gRenderer);


}