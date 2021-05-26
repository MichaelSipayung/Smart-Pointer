// Smart Pointer.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>

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

//container classes .. destroy v2

std::vector<int> v1;
void destroy() {
	std::vector<int> v2= { 1,2,3 };
	v1 = v2;
}

class strBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	strBlob() :data(std::make_shared<std::vector<std::string>>()){}
	//strBlob(std::initializer_list<std::string> il)	;
	strBlob::strBlob(std::initializer_list<std::string>il) :
	data(std::make_shared<std::vector<std::string>>(il)){}
	size_type size() const { return  data->size(); }
	bool empty()  const {return  data->empty(); }
	void push_back(const std::string& t) {
		data->push_back(t);
	}
	void pop_back();
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;// purpose for share data 
	void check(size_type i, const std::string& msg)const;

};

void strBlob::check(size_type i, const std::string& msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}
std::string& strBlob::front() {
	check(0, "front on empty strBlob");
	return data->front();
}
std::string &strBlob::back(){
	check(0, "back on empty strBlob");
	return data->back();
}
void strBlob::pop_back() {
	check(0, "pop back on empty strBlob");
	data->pop_back();
}

// TODO: Reference additional headers your program requires here.
