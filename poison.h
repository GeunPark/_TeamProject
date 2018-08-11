#pragma once
#include "gameNode.h"

struct tagPoison
{
	image* poisonImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	bool isFire;
};

class poison : public gameNode
{
private:

	vector<tagPoison> _vPoison;
	
private:
	
	float _range;
	int fireNum;
	int count, index;
	int indexX, indexY;
	int bCount;
	bool _isFire;
public:
	HRESULT init(float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, int maxPoison, float angle);

	void move();

	void frameMove();

	void removePoison(int index);

	int getIndexX() { return indexX; }
	int getIndexY() { return indexY; }

	vector<tagPoison> getVPoison() { return _vPoison; }



	poison() {}
	~poison() {}
};

