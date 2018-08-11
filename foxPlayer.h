#pragma once
#include "gameNode.h"
#include "arrow.h"
#include "cuticle.h"
#include "magic.h"
#include "poison.h"

#define MAX_HEIGHT 2500
#define MAX_WIDTH 10000
#define MAX_STATE 16

class enemyManager;

enum tagState
{
	IDLE = 0,
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
	WEATHER,
	DEATH
};

struct tagPlayer
{
	RECT rc;
	RECT collisionRc;
	float x, y;
	float speed;
	float jumpSpeed;
	float gravity;
	float angle;
	float arrowAngle;
	float radian;

	bool isJump;
	bool isLeft;
	bool isRight;

	bool isFoxLeft;
	bool isUp;
	bool isDown;
	bool isAtt;
	bool isChange;

	float mana;
	float maxMana;
	int HP;
	int MaxHp;
	int gold;
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
	magic* _magic;
	cuticle* _cuticle;
	poison* _poison;
	

	// 상점에서 산 아이템 저장하는 벡터
	

	image* nick[MAX_STATE];
	image* _bpx;
	image* _twinkle;
	

	RECT attRc, attRc2, attRc3, attRc4;	//임시 공격렉트(잘 되면 주로 사용)
	RECT twinkleRc;

	int count, index, index2, actionCount, weatherIndex, effectIndex, effectCount, attCount;
	int jumpCount, jumpAttCount;
	int animationSpeed;
	int hitCount;
	int unDamage;
	int alphaCount;

	int arrowNum;
	int arrowNumChk;

	int magicNum;
	int magicNumCHk;

	bool ang = false;
	bool chk = false;
	bool _a;
	bool eftChk;
	int _magicUseCount;
	bool _magicUseChk;
	bool _magicUseChk2;
	int a = 0;
	float tempX, tempY;
	bool isTouch;
	bool isArrowChange;

	float _c[10], _d[10];

public:


	
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	//함수들
	void imageSetting();
	void frameMove();
	void keySetting();
	void attRect();
	void camera();
	void pixelCollision();
	void enemyCollision();
	void enemyAttCollision();
	void removeArrow(int index);
	void foxState();
	//void fire(float angle);
	void magicCollision();

	// get, set함수들
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	void setX(float x) { _player.x = x; }
	void setY(float y) { _player.y = y; }

	bool getIsTouch() { return isTouch; }
	void setIsTouch(bool a) { isTouch = a; }

	bool getmagicUseChk() { return _magicUseChk; }
	bool getmagicUseChk2() { return _magicUseChk2; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	bool getIsAtt() { return _player.isAtt; }
	void setIsAtt(bool a) { _player.isAtt = a; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }
	RECT getAttRc2() { return attRc2; }

	void setState(tagState state) { _state = state; }
	tagState getPlayerState() { return _state;}

	image* getBgPixel() { return _bpx; }
	void setBgPixel(image* bpx) { _bpx = bpx; }

	// 플레이어 마나
	float getMana() { return _player.mana; }
	float getMaxMana() { return _player.maxMana; }
	void setMana(float mana) { _player.mana = mana; }
	void setMaxMAna(float maxMana) { _player.maxMana = maxMana; }

	// 플레이어 HP
	void setHp(int hp) { _player.HP = hp; }
	void setMaxHp(int hp) { _player.MaxHp = hp; }
	int getHp() { return _player.HP; }
	int getMaxHp() { return _player.MaxHp; }
	

	// 플레이어 골드
	int getGold() { return _player.gold; }
	void setGold(int gold) { _player.gold = gold; }

	//에너미매니저와 상호참조
	void setEnemyManager(enemyManager* enemyManager) { _enemyManger = enemyManager; }
	
	tagPlayer getTag() { return _player; }
	void setTag(tagPlayer player) { _player = player; }

	// 계절을 변화시켰는지 아닌지 판별
	bool getAng() { return ang; }
	
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }
	//세원쓰^^~ 불금인데 못놀아서 아쉽지 ~~ 월요일날 보니깐 힘내 내가 아래 겟함수 하나 만들었는데~~ 미안쓰 -HG-
	
	arrow* getArrow() { return _arrow; }
	magic* getMagic() {return _magic;}
	

	RECT getCollisionRc() { return _player.collisionRc; }

	bool getEftChk() { return eftChk; }
	void setEftChk(bool eC) { eftChk = eC; }

	int getUnHit() { return unDamage; }
	void setUnHit(int a) { unDamage = a; }

	//tagState getState() { return _state; }
	//void setState(tagState state) { _state = state; }

	// 테스트 함수
	void test();
	void playerUI();

	int getarrowNum() { return arrowNum; }
	int getarrowNumChk() { return arrowNumChk; }

	int getMagicNUm() { return magicNum; }
	int getMagicNUmChk() { return magicNumCHk; }

	void setMagicNum(int a) { magicNum = a; }

	foxPlayer() {}
	~foxPlayer() {}

};

