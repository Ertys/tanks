#pragma once

#include "render_context.h"

class game
{
public:
	game();
	~game();
	void update(double pDeltaTime);
	void draw(double pDeltaTime);
	bool is_running();
	bool initilize();
protected:
private:
	bool running;
	render_context mRenderContext;
};

