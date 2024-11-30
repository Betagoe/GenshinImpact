#include"StartMenu.h"
#include"HelloWorldScene.h"



Scene* StartMenu::createScene()
{
	return StartMenu::create();
}

bool StartMenu::init()//��ʼ�����������ڳ�������ʱ����
{

	if (!Scene::init())//�����ʼ��ʧ��
	{
		return false;//����false
	}
	//����һ�����飬����ͼƬ��GenshinStart.jpg,λ���������Ͻ�
	auto background = Sprite::create("GenshinStart.jpg");
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));//����ê��
	//�ʵ����ű���ͼƬ��ʹ������������Ļ
	background->setScale(1.25);
	this->addChild(background, 0);//������ͼƬ��ӵ�������

	//�Ӱ�ť��ʹ�����Ļ����λ�ö��ܽ���HelloWorld����
	auto listener = EventListenerTouchOneByOne::create();//����һ������������
	listener->onTouchBegan = [=](Touch* touch, Event* event)//��������ʼʱ����
		{
			Director::getInstance()->replaceScene(HelloWorld::createScene());//��ת������HelloWorld
			return true;
		};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//�����������뵽�¼��ַ�����





	return true;
}