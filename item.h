#pragma once
#include "gameNode.h"


class item : public gameNode
{
protected:

	image * _image;
	image* _bfx;
	float _x, _y;
	float speed;
	float angle;
	float gravity;
	RECT _rc;
	int _currentFrameX;
	int _count;


public:

	HRESULT init(const char* ImageName, POINT position, int currentFrameX, float _angle = 0);
	void release(void);
	void update(void);
	void render(float FX, float FY);


	void animation();
	virtual void move() = 0;
	void pixelCollision();



	RECT getRect() { return _rc; }
	image* getItemImage() { return _image; }
	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	float getSpeed() { return speed; }
	void setSpeed(float _speed) { speed = _speed; }

	float getAngle() { return angle; }
	void setAngle(float _angle) { angle = _angle; }

	void setGravity(float _gravity) { gravity = _gravity; }




	item() {}
	~item() {}
};

class healthLarge : public item
{
private:


public:
	void move();

};

class healthBig : public item
{
private:


public:

	void move();
};

class manaBig : public item
{
private:


public:

	void move();
};

class manaSmall : public item
{
private:


public:

	void move();
};

class goldCoin : public item
{
private:


public:

	void move();
};
class silverCoin : public item
{
private:


public:

	void move();
};
class bronzeCoin : public item
{
private:


public:

	void move();
};