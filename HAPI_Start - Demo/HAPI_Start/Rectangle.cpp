#include "Rectangle.h"

void Rectangle::Translate(int dX, int dY)
{
	//translate the top,bottom,left and right sides of the triangle
	left += dX;
	right += dX;
	top += dY;
	bottom += dY;
}

void Rectangle::Animation(int frameWidth, int frameNum)
{
	right = right - (frameWidth * 1);
	left = left + (frameWidth * 1);
}

void Rectangle::ClipTo(const Rectangle& other)
{
	//check the right,bottom,left and top sides with the other rectangle to see if we have clipped

	if (right > other.right)
		right = other.right;

	if (left < other.left)
		left = other.left;

	if (top < other.top)
		top = other.top;

	if (bottom > other.bottom)
		bottom = other.bottom;
}
