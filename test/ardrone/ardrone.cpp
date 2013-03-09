#include "kovan/kovan.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	ARDrone *drone = ARDrone::instance();
	if(!drone->connect()) {
		return EXIT_FAILURE;
	}

	drone->flatTrim();
	msleep(1000);
	
	std::cout << "flying? " << (drone->state() == ARDrone::Flying) << std::endl;
	
	drone->takeoff();
	msleep(5000);
	
	std::cout << "flying? " << (drone->state() == ARDrone::Flying) << std::endl;
	
	// drone->move(0.0f, 0.0f, 0.0f, 1.0f);
	// msleep(10000);
	
	// drone->hover();
	// msleep(10000);
	
	drone->land();
	msleep(2000);

	drone->disconnect();
	
	return EXIT_SUCCESS;
}