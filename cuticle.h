#pragma once
#include "gameNode.h"


struct tagCuticle
{
	image* cuticleImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	bool isFire;
	int count;
};



class cuticle : public gameNode
{
private:
	vector<tagCuticle> _vCuticle;


private:
	int _cuticleMax;
	float _range;
	int fireNum;

public:

	HRESULT init(float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float cuticleMax);

	void move();

	void removeCuticle(int index);

	vector<tagCuticle> getCuticle() { return _vCuticle; }


	cuticle() {}
	~cuticle() {}
};

