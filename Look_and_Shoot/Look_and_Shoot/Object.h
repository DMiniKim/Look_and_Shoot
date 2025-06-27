#pragma once
#include <iostream>
using namespace std;

class Object
{
public:
	int x;
	int y;
	const char* shape;

public:
	virtual void Init() abstract;
	virtual void Update() abstract;

};

