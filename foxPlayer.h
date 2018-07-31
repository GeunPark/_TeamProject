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
	bool isLeft;
	bool isRight;
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

	//함수들
	void keySetting();
	void camera();

	// get, set함수들
	float getX() { return _player.x; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	RECT getPlayerCam() { return _camera.rc; }


	foxPlayer() {}
	~foxPlayer() {}

};

