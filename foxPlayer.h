#pragma once
#include "gameNode.h"
#include "arrow.h"
#include "cuticle.h"
<<<<<<< HEAD
#include "magic.h"
#include "shop.h"
=======
#include "poison.h"
>>>>>>> 6feb6882fd506c81d21945e18013937e595264f3

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
	shop * _shop;
	cuticle* _cuticle;
	poison* _poison;
	

	// �������� �� ������ �����ϴ� ����
	

	image* nick[MAX_STATE];
	image* _bpx;
	image* _twinkle;
	

	RECT attRc, attRc2, attRc3, attRc4;	//�ӽ� ���ݷ�Ʈ(�� �Ǹ� �ַ� ���)
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

	float _c[10], _d[10];

public:


	
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	//�Լ���
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8a6e72778944b18af6e679aa436a25711233bd1a
	//void fire(float angle);
=======
<<<<<<< HEAD
	void magicCollision();
=======
	void fire(float angle);
>>>>>>> c2642a7eaeac04dd17b99ec0392ef574661aa47f
<<<<<<< HEAD
=======
	void fire(float angle);
>>>>>>> parent of 380705e... 보스와 보스총알에 충돌처리 완료
=======
>>>>>>> 8a6e72778944b18af6e679aa436a25711233bd1a
	
>>>>>>> 6feb6882fd506c81d21945e18013937e595264f3

	// get, set�Լ���
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	void setX(float x) { _player.x = x; }
	void setY(float y) { _player.y = y; }

	bool getmagicUseChk() { return _magicUseChk; }
	bool getmagicUseChk2() { return _magicUseChk2; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	bool getIsAtt() { return _player.isAtt; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }
	RECT getAttRc2() { return attRc2; }

	void setState(tagState state) { _state = state; }
	tagState getPlayerState() { return _state;}

	image* getBgPixel() { return _bpx; }
	void setBgPixel(image* bpx) { _bpx = bpx; }

	// �÷��̾� ����
	float getMana() { return _player.mana; }
	float getMaxMana() { return _player.maxMana; }
	void setMana(float mana) { _player.mana = mana; }
	void setMaxMAna(float maxMana) { _player.maxMana = maxMana; }

	// �÷��̾� HP
	void setHp(int hp) { _player.HP = hp; }
	void setMaxHp(int hp) { _player.MaxHp = hp; }
	int getHp() { return _player.HP; }
	int getMaxHp() { return _player.MaxHp; }
	

	// �÷��̾� ���
	int getGold() { return _player.gold; }
	void setGold(int gold) { _player.gold = gold; }

	//���ʹ̸Ŵ����� ��ȣ����
	void setEnemyManager(enemyManager* enemyManager) { _enemyManger = enemyManager; }
	tagPlayer getTag() { return _player; }

	// ������ ��ȭ���״��� �ƴ��� �Ǻ�
	bool getAng() { return ang; }
	
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }
	//������^^~ �ұ��ε� ����Ƽ� �ƽ��� ~~ �����ϳ� ���ϱ� ���� ���� �Ʒ� ���Լ� �ϳ� ������µ�~~ �̾Ⱦ� -HG-
	
	arrow* getArrow() { return _arrow; }
	magic* getMagic() {return _magic;}
	shop* getShop() { return _shop; }

	RECT getCollisionRc() { return _player.collisionRc; }

	bool getEftChk() { return eftChk; }
	void setEftChk(bool eC) { eftChk = eC; }

	int getUnHit() { return unDamage; }
	void setUnHit(int a) { unDamage = a; }

	//tagState getState() { return _state; }
	//void setState(tagState state) { _state = state; }

	// �׽�Ʈ �Լ�
	void test();
	void playerUI();

	int getarrowNum() { return arrowNum; }
	int getarrowNumChk() { return arrowNumChk; }

	int getMagicNUm() { return magicNum; }
	int getMagicNUmChk() { return magicNumCHk; }

	foxPlayer() {}
	~foxPlayer() {}

};

