#include "main.h"

int main(int argc, char* argv[])
{
	if (initilize()			== false) return EXIT_FAILURE;
	if (mGame.initilize()	== false) return EXIT_FAILURE;

	main_loop();

	glfwTerminate();
	return EXIT_SUCCESS;
}

bool initilize()
{
	if (!glfwInit()) return false;

	mWindow = glfwCreateWindow(800, 600, "Window", NULL, NULL);
	if (!mWindow)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(mWindow);

	return true;
}
void main_loop()
{
	const double MIN_DELTA_TIME = 1.0 / 60.0;
	const double MAX_DELTA_TIME = 0.1;

	timer mTimer;
	mTimer.reset();
	while (!glfwWindowShouldClose(mWindow))
	{
		if (mGame.is_running())
		{
			double mFrameTime, mDeltaTime;
			mFrameTime = mDeltaTime = mTimer.time_elapsed();
			mTimer.reset();

			if		(mDeltaTime > MAX_DELTA_TIME) mDeltaTime = MAX_DELTA_TIME;
			else if (mDeltaTime < MIN_DELTA_TIME) mDeltaTime = MIN_DELTA_TIME;

			glfwPollEvents();

			mGame.update(mDeltaTime);
			mGame.draw(mDeltaTime);

			glfwSwapBuffers(mWindow);

			if (mFrameTime < MIN_DELTA_TIME) mTimer.sleep(MIN_DELTA_TIME - mFrameTime);
		}
		else break;

	}
}