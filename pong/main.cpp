#include <iostream>
#include "App.hpp"

#undef main

int main(void)
{
	App app;
	app.run();
	app.stop();
	return 0;
}