#pragma once
#include "gameNode.h"
#include "arrow.h"


#define MAX_HEIGHT 2500
#define MAX_WIDTH 10000
#define MAX_STATE 16

class enemyManager;
class UI;
class shop;
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
	WEATHER,
	DEATH
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
	float arrowAngle2, arrowAngle3;
	float radian;
	bool isJump;
	bool isLeft;
	bool isRight;
	bool isFoxLeft;
	//bool isFoxRight;
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
	UI * _ui;
	shop * _shop;

	// �������� �� ������ �����ϴ� ����
	

	image* nick[MAX_STATE];
	image* _bfx;
	image* _twinkle;
	RECT attRc, attRc2, attRc3, attRc4;	//�ӽ� ���ݷ�Ʈ(�� �Ǹ� �ַ� ���)
	RECT twinkleRc;
	//image* _bpx;
	int count, index, actionCount, actionIndex, weatherIndex, effectIndex, effectCount;
	int jumpCount, jumpAttCount;
	bool ang = false;
	//image* _bpx2;
	int hitCount;
	int unDamage;
	
	bool chk = false;
	bool _a;
	bool eftChk;
public:


	
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();
	//void render(float FX, float FY);

	//�Լ���
	void imageSetting();
	void frameMove();
	void collisionRcChange();
	void foxState();
	void keySetting();
	void attRect();
	void camera();
	void pixelCollision();
	void enemyCollision();
	void enemyAttCollision();
	void removeArrow(int index);

	// get, set�Լ���
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	bool getLeft() { return _player.isLeft; }
	bool getRight() { return _player.isRight; }
	RECT getPlayerCam() { return _camera.rc; }
	RECT getAttRc() { return attRc; }
	RECT getAttRc2() { return attRc2; }

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
	void setUIManager(UI* ui) { _ui = ui; }
	void setShopManager(shop * shop) { _shop = shop; }

	// ���� �� ����
	//void setVShopItem(vector<shop> shop) { _shopItem = shop; }
	//vector<shop> getVShopItem() { return _shopItem;  }

	tagPlayer getTag() { return _player; }

	// ������ ��ȭ���״��� �ƴ��� �Ǻ� Ang~��
	bool getAng() { return ang; }
	
	void setIsAttack(bool _isAttack) { _player.isAtt = _isAttack; }
	//������^^~ �ұ��ε� ����Ƽ� �ƽ��� ~~ �����ϳ� ���ϱ� ���� ���� �Ʒ� ���Լ� �ϳ� ������µ�~~ �̾Ⱦ� -HG-
	
	arrow* getArrow() { return _arrow; }
	RECT getCollisionRc() { return _player.collisionRc; }
	//tagCam getCamera(tagCam camera) { return _camera; }

	bool getEftChk() { return eftChk; }
	void setEftChk(bool eC) { eftChk = eC; }


	// �׽�Ʈ �Լ�
	void test();
	void playerUI();

	foxPlayer() {}
	~foxPlayer() {}

};

