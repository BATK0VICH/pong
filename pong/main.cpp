#include <iostream>
#include "App.hpp"
#include "Initialization.hpp"

#undef main

int main(void)
{
	initializeEverything();
	App app;
	app.run();
	return 0;
}