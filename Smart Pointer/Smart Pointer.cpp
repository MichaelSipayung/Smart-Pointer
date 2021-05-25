// Smart Pointer.cpp : Defines the entry point for the application.
//

#include "Smart Pointer.h"


int main()
{
	std::cout << "Hello smart pointer." << std::endl;
	std::cout << "Review smart Pointer" << std::endl;
	std::shared_ptr<int> p1;
	std::shared_ptr<std::string> p2;
	std::shared_ptr<std::list<std::string>> p3;
	std::cout << "Test if the current pointer is null \t:["; 

	if (p2 && p2->empty()) {
		*p2 = "michael";
		std::cout << "Size after testing condition \t:[ " << p2->size() << "]" << std::endl;

	}
	else {
		std::cout << "Current pointer is null \t:  address [ " << p2 << "]" << std::endl;
	}
	std::cout << "the make shared functions " << std::endl;

	std::shared_ptr<int> nameVar = std::make_shared<int>(12);
	if (nameVar) {
		std::cout << "Pointer is initialized ,and it's not null , address \t: [" << nameVar << "]" << std::endl;
	}
	else {
		std::cout << "Null pointer" << std::endl;
	}

	auto nameVec = std::make_shared<std::vector<int>>(6);
	nameVec->push_back(98);
	nameVec->push_back(41);
	nameVec->push_back(87);
	std::cout << "name vec, size \t:[ " << nameVec->size() << "]" << std::endl;
	std::cout << "Access member , dynamic memory \t: [";
	for (auto i = nameVec->begin(); i !=nameVec->end(); ++i)
	{
		std::cout << *i << "|" << "Address \t: [" << nameVec << "]" << std::endl;
	}
	std::cout << "]" << std::endl;
	std::cout << "Copy and assigning shared_ptr" << std::endl;
	std::cout << "1.How many nameVec share \t: [ " << nameVec.use_count() << "]" << std::endl;
	auto shareTwo(nameVec);
	std::cout << "2.How many nameVec share \t: [ " << nameVec.use_count() << "]" << std::endl;
	
	std::cout << "Decremented counter " << std::endl;
	auto makeDec = std::make_shared<int>(42);
	auto r = std::make_shared<int>(42);
	std::cout << "1. test object r point to  \t: [" << r << "]" << std::endl;
	r = makeDec; //destroy the object r
	std::cout << "1. test object r point to  \t: [" << r << "]" << std::endl;
	std::cout << "1. test object makeDec point to [" <<makeDec << "]" << std::endl;
	int* pracOne = new int(12);
	int* pracTwo = new int(13);
	pracTwo = pracOne;
	std::cout << "1. test object r point to  \t: [" << pracTwo << "]" << std::endl;
	std::cout << "1. test object r point to  \t: [" << pracOne << "]" << std::endl;
	std::cout << "Automatically freed the current local object using shared_ptr" << std::endl;
	use_factory();
	problem();





	return 0;
}
