#pragma once
#include "gameNode.h"
#include "loading.h"

class loadingScene : public gameNode
{
private:
	loading * _loading;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
	void loadingImage();
	//�ε����� �Լ�(�̰��� ���带 ���� �־��)
	void loadingSound();

	void GeunHwaImage();
	void SaeWonImage();
	void SunSooImage();
	void GiHunImage();

	void GeunHwaSound();
	void SaeWonSound();
	void SunSooSound();
	void GiHunSound();




	loadingScene() {}
	~loadingScene() {}
};

