#pragma once
#include "gameNode.h"

//�Ѿ� ����ü
struct tagBullet
{
	image* bulletImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	float gravity;
	float radius;
	bool fire;
	int count;
};

//=============================================================
//	## bullet ## (�����Ѿ� - ������� ����� �ȴ�)
//=============================================================
class bullet : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	const char* _imageName;		//�Ѿ� �̹��� �̸�(Ű��)
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��
	bool _isFrameImg;		//�̹����Ŵ����� ��� �ִ� �̹����� �������� �ֳ� ����?

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y, float angle, float speed);
	//�Ѿ˹���
	void move();

	//�Ѿ˻���
	void removeBullet(int index);

	//�Ѿ˺��� ��������
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

	bullet() {}
	~bullet() {}
};

//=============================================================
//	## missile ## (missile[0] -> �迭ó�� �̸� �����صΰ� �Ѿ˹߻�)
//=============================================================
class missile : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y);
	//�Ѿ˹���
	void move();

	missile() {}
	~missile() {}
};

//=============================================================
//	## missileM1 ## (��źó�� �ѹ߾� �߻��ϸ鼭 �����ϰ� �ڵ�����)
//=============================================================
class missileM1 : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y);
	//�Ѿ˹���
	void move();

	void removeMissileM1(int index);

	//�Ѿ˺��� ��������
	vector<tagBullet> getVBullet() { return _vBullet; }

	missileM1() {}
	~missileM1() {}
};

class ghostBullet : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	tagBullet _bullet;


private:
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��
	int _index, _count;


public:
	HRESULT init(const char * imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y, float playerX, float playerY);

	//�Ѿ˹���
	void move();

	image* getBulletImage() { return _bullet.bulletImage; }
	bool getBulletFire() { return _bullet.fire; }
	RECT getBulletRc() { return _bullet.rc; }

	ghostBullet() {}
	~ghostBullet() {}
};

class beeBullet : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	//tagBullet _bullet;

	vector<tagBullet> _vBullet;

private:
	float _range;			//�Ѿ� ��Ÿ�
	int _bulletMax;			//�Ѿ� �ִ밹��
	int _index, _count;
	bool isFire;
	int fireNum;

public:
	HRESULT init(float range);
	void release(void);
	void update(void);
	void render(void);

	//�Ѿ˹߻�
	void fire(float x, float y, int bulletMax);

	//�Ѿ˹���
	void move();

	
	
	//image* getBulletImage() { return _bullet.bulletImage; }
	vector<tagBullet> getVBullet() { return _vBullet; }


	void setBulletFire(bool _isFire) { isFire = _isFire; }
	bool getBulletFire() { return isFire; }
	int getIndex() { return _index; }
	int getBulletMax() { return _bulletMax; }
	//RECT getBulletRc() { return _bullet.rc; }

	beeBullet() {}
	~beeBullet() {}
};


