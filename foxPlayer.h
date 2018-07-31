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
	float radian;
	bool isJump;
	bool isLeft;
	bool isRight;
	bool isAtt;
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
	image* _bfx;
	RECT attRc;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	//함수들
	void keySetting();
	void camera();
	void pixelCollision();

	// get, set함수들
	float getX() { return _player.x; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }

	//세원쓰^^~ 나 형구쓰 이거 내가 추가했스스 ^^~ ♡
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }

	foxPlayer() {}
	~foxPlayer() {}

};

