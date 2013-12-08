#include "game.h"


game::game()
{
}


game::~game()
{
}


void game::update(double pDeltaTime)
{
}


void game::draw(double pDeltaTime)
{
	mRenderContext.begin();

	mRenderContext.set_camera(vector3(0,0,15), vector3(0,0,0), vector3(0,1,0));

	mRenderContext.draw_cube();

	mRenderContext.end();
}


bool game::is_running()
{
	return running;
}


bool game::initilize()
{
	mRenderContext.initilize();
	mRenderContext.resize(800, 600);

	running = true;
	return true;
}
