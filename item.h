#pragma once
#include "gameNode.h"

enum ITEM_TYPE
{
	HEALTH_LARGE,
	HEALTH_SMALL,
	MANA_BIG,
	MANA_SMALL,
	GOLD_COIN,
	SILVER_COIN,
	BRONZE_COIN,
	ITEM_BOX

};
enum ITEM_STATE
{
	CLOSE,
	OPEN
};

class item
{
protected:

	ITEM_TYPE _type;
	ITEM_STATE _state;
	image* _image;
	image* _bfx;
	float _x, _y;
	float _speed;
	float _angle;
	float _gravity;
	RECT _rc;
	int _count, _index;
	bool _isActived;
	float _animationSpeed;


public:

	virtual void init() = 0;
	virtual void move() = 0;
	void update();
	void animation();
	void pixelCollision();

	RECT getRc() { return _rc; }
	image* getItemImage() { return _image; }
	float getX() { return _x; }
	void setX(float x) { _x = x; }

	float getY() { return _y; }
	void setY(float y) { _y = y; }

	int getIndex() { return _index; }	
	void setIndex(int index) { _index = index; }

	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }

	float getAngle() { return _angle; }
	void setAngle(float angle) {_angle = angle; }

	float getGravity() { return _gravity; }
	void setGravity(float gravity) { _gravity = gravity; }

	bool getIsActive() { return _isActived; }
	void setIsActive(bool isActive) { _isActived = isActive; }

	ITEM_TYPE getItemType() { return _type; }
	void setItemType(ITEM_TYPE type) { _type = type; }

	ITEM_STATE getItemState() { return _state; }
	void setItemState(ITEM_STATE state) { _state = state; }

	void setPosition(float x, float y) { _x = x, _y = y; }

	image* getPixelImage() { return _bfx; }

	item() {}
	~item() {}
};

class healthLarge : public item
{
private:


public:
	void init();
	void move();

};

class healthBig : public item
{
private:


public:
	void init();
	void move();
};

class manaBig : public item
{
private:


public:
	void init();
	void move();
};

class manaSmall : public item
{
private:


public:
	void init();
	void move();
};

class goldCoin : public item
{
private:


public:
	void init();
	void move();
};
class silverCoin : public item
{
private:


public:
	void init();
	void move();
};
class bronzeCoin : public item
{
private:


public:
	void init();
	void move();
};
class itemBox : public item
{
private:


public:
	void init();
	void move();
};
