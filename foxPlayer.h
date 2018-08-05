#pragma once
#include "gameNode.h"
#include "arrow.h"


#define MAX_HEIGHT 2500
#define MAX_WIDTH 10000
#define MAX_STATE 15

class enemyManager;
class UI;
enum tagState
{
	IDLE=0,
	RUN,
	SIT,
	JUMP,
	DOUBLEJUMP,
	FALL,
	FALL2,
	FIRE,
	UPATT,
	SITATT,
	JUMPATT,
	JUMPATT2,
	DOWNATT,
	HIT,
	WEATHER
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

	float mana;
	float maxMana;
	int HP;
	int MaxHp;
};

struct tagCam
{
	RECT rc;
	float x, y;
};



class foxPlayer : public gameNode
{
private:
	enemyManager * _enemyManger;

	tagPlayer _player;
	tagCam _camera;
	tagState _state;

	arrow* _arrow;
	UI * _ui;



	image* nick[MAX_STATE];
	image* _bfx;
	
	RECT attRc, attRc2, attRc3, attRc4;	//임시 공격렉트(잘 되면 주로 사용)
	image* _bpx;
	int count, index, actionCount, actionIndex;
	int jumpCount;
	bool ang = false;
	//image* _bpx2;
	int hitCount;
	int unDamage;

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
	void enemyCollision();
	void removeArrow(int index);

	// get, set함수들
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }

	float getMana() { return _player.mana; }
	float getMaxMana() { return _player.maxMana; }

	// 플레이어 HP
	int getHp() { return _player.HP; }
	int getMaxHp() { return _player.MaxHp; }

	void setEnemyManager(enemyManager* enemyManager) { _enemyManger = enemyManager; }
	tagPlayer getTag() { return _player; }
	// 계절을 변화시켰는지 아닌지 판별 Ang~♡
	bool getAng() { return ang; }
	
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }
	//세원쓰^^~ 불금인데 못놀아서 아쉽지 ~~ 월요일날 보니깐 힘내 내가 아래 겟함수 하나 만들었는데~~ 미안쓰 -HG-
	
	arrow* getArrow() { return _arrow; }
	RECT getCollisionRc() { return _player.collisionRc; }
	//tagCam getCamera(tagCam camera) { return _camera; }

	void setUIManager(UI* ui) { _ui = ui; }

	foxPlayer() {}
	~foxPlayer() {}

};

