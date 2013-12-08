#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <stdlib.h>

#include "game.h"
#include "timer.h"

bool initilize();
void main_loop();

game mGame;

GLFWwindow* mWindow;

int main(int argc, char* argv[]);

bool initilize();
void main_loop();