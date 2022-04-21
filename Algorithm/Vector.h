#pragma once
#include<iostream>
class Vector2
{
public:
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float _x,float _y)
	{
		x = _x;
		y = _y;
	}
	float x,y;
};