#include "stdafx.h"
#include "gdipTestScene.h"

HRESULT gdipTestScene::init(void)
{
	//png, jpg�� �̹��� ���� �� ���� �� ����
	//png���Ϻ��� jpg������ ������ ���ϱ� �� �ϴ�
	//�׷��� ������ ������ png���� �̴� �˾Ƽ��� �ϸ� �ȴ�
	GDIPLUS->addImage("ȿ����", "pngImage/ȿ��PNG.png"); //������ 40���� ������
	//GDIPLUS->addImage("ȿ����", "PNGIMAGE/ȿ��JPG.jpg"); //������ ���� �ȶ�����

	return S_OK;
}

void gdipTestScene::release(void)
{
}

void gdipTestScene::update(void)
{
}

void gdipTestScene::render(void)
{
	//���� �׽�Ʈ �� �غ���
	GDIPLUS->gdiRender("ȿ����", getMemDC());
	GDIPLUS->gdiRender("ȿ����", getMemDC(), 800, 100, 200, 200, 200, 200, 45);
	
	showTitle(getMemDC(), "GDI+ �׽�Ʈ - png,jpg ��밡��");
}
