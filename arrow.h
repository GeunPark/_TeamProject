#pragma once
#include "gameNode.h"


struct tagArrow
{
	image* arrowImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	bool isFire;
	bool isLeft;
	int count;
};


class arrow : public gameNode
{
private:
	vector<tagArrow> _vArrow;
	vector<tagArrow>::iterator _viArrow;

private:
	int _arrowMax;
	float _range;

public:
	HRESULT init(int arrowMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle);

	void move();

	void animation();
	
	void removeArrow(int index);

	vector<tagArrow> getArrow() { return _vArrow; }
	

	arrow() {}
	~arrow() {}
};

