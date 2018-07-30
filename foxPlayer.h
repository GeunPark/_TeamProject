#pragma once
#include "gameNode.h"
#define MAX_HEIGHT 2750
#define MAX_WIDTH 20000


struct tagPlayer
{
	RECT rc;
	float x, y;
	float speed;
	float gravity;
	float angle;
	float bulletAngle;
	bool isJump;

};

struct tagCam
{
	RECT rc;
	float x, y;
};



class foxPlayer : public gameNode
{
private:
	tagPlayer _player;
	tagCam _camera;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	void move();

	float getX() { return _player.x; }


	RECT getPlayerCam() { return _camera.rc; }
	foxPlayer() {}
	~foxPlayer() {}

};

