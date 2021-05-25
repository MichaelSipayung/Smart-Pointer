// Smart Pointer.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <list>


//share ptr_will take care for deleting the memory
std::shared_ptr<int> factory() {
	return std::make_shared<int>();
}

//p goes out the scope , memory automatically freed
void use_factory() {
	std::shared_ptr<int> p = factory(); 
	if (p) {
		std::cout << "automatically freed" << std::endl;
	}
	else {
		std::cout << "sorry null pointer" << std::endl;
	}
}

void problem() {
	std::shared_ptr<int> notFreed;
	if (notFreed) {
		std::cout << "Automatically freed" << std::endl;
	}

	else{
		std::cout << "Sorry the object isn't freed" << std::endl;
	}
}

//p goes out the scope , the memory to which p point s is not freed
std::shared_ptr<int> notAutFredd() {
	std::shared_ptr<int> p = factory();
	return p;
}


// TODO: Reference additional headers your program requires here.
