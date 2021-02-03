#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Rectangle
{
private:

public:
	int left, right, top, bottom;

	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}

	int Width() const
	{
		return right - left;
	}

	int Height() const
	{
		return bottom - top;
	}

	bool IsOutSideOf(const Rectangle &other)
	{
		if (left > other.right)
			return true;

		if (bottom < other.top)
			return true;

		if (right < other.left)
			return true;

		if (top > other.bottom)
			return true;
		return false;
	}

	void Translate(int dX, int dY);

	void Animation(int frameWidth, int frameNum);

	void ClipTo(const Rectangle& other);
};

