#pragma once
#include "gameNode.h"
#include "arrow.h"
#include "UI.h"

#define MAX_HEIGHT 2500
#define MAX_WIDTH 10000
#define MAX_STATE 14

enum tagState
{
	IDLE=0,
	RUN,
	SIT,
	JUMP,
	DOUBLEJUMP,
	FALL,
	FALL2,
	//WEATHER1,
	//WEATHER2,
	FIRE,
	UPATT,
	SITATT,
	JUMPATT,
	JUMPATT2,
	DOWNATT,
	HIT
};

struct tagPlayer
{
	RECT rc;
	RECT collisionRc;
	float x, y;
	float speed;
	float gravity;
	float angle;
	float arrowAngle;
	float radian;
	bool isJump;
	bool isLeft;
	bool isRight;
	//bool isFoxLeft;
	//bool isFoxRight;
	bool isUp;
	bool isDown;
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
	tagState _state;

	arrow* _arrow;
	UI * _ui;
	image* nick[MAX_STATE];
	image* _bfx;
	
	RECT attRc;	//임시 공격렉트(잘 되면 주로 사용)
	image* _bpx;
	int count, index, actionCount, actionIndex;
	int jumpCount;
	//image* _bpx2;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	//함수들
	void imageSetting();
	void frameMove();
	void collisionRcChange();
	void foxState();
	void keySetting();
	void camera();
	void pixelCollision();
	void removeArrow(int index);

	// get, set함수들
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }

	tagPlayer getTag() { return _player; }

	//세원쓰^^~ 나 형구쓰 이거 내가 추가했스스 ^^~ ♡
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }

	//tagCam getCamera(tagCam camera) { return _camera; }

	foxPlayer() {}
	~foxPlayer() {}

};

