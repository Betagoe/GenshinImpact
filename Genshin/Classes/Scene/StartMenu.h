#ifndef __STARTMENU_SCENE_H__
#define __STARTMENU_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class StartMenu : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();//��ʼ�����������ڳ�������ʱ����
	CREATE_FUNC(StartMenu);
};

#endif // __HELLOWORLD_SCENE_H__
