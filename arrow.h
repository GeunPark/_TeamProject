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

struct tagArrow2
{
	image* arrowImage;
	image* arrowImage2;
	image* arrowImage3;
	RECT rc, rc2, rc3;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle, angle2, angle3;
	bool isFire;
	bool isLeft;
	int count;
};

class arrow : public gameNode
{
private:
	vector<tagArrow> _vArrow;
	vector<tagArrow>::iterator _viArrow;

	vector<tagArrow2> _vPoison;
	vector<tagArrow2>::iterator _viPoison;


private:
	int _arrowMax;
	float _range;
	int count = 0;
public:
	HRESULT init(int arrowMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle);

	void fire2(float x, float y, float angle);

	

	void move();
	void move2();

	void animation();
	void animation2();
	
	void removeArrow(int index);
	void removePoison(int index);

	vector<tagArrow> getVArrow() { return _vArrow; }
	vector<tagArrow2> getVPoison() { return _vPoison; }
	

	arrow() {}
	~arrow() {}
};

