#ifndef __STARTMENU_SCENE_H__
#define __STARTMENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;

class StartMenu : public cocos2d::Scene
{
private:
      char pauseTime; // �򵥱��������ڿ��ƶ�����ʱ��ͣ
      char loading;

      Size visibleSize;
      Vec2 origin;

      Sprite* backGround1;
      Sprite* backGround2;
      Sprite* backGround3;
      Sprite* backGround4;
      //Sprite* backGround5; // �ŵ�¼��Ϣ�Ȼ��棬������ʱ������

      Vector<SpriteFrame*> loginSceneAnimation;
      int isLoginSceneAnimation;
      Vector<SpriteFrame*> loginAnimation;
      int isLoginAnimation;

      void initialLoginIamge(Sprite* background, bool tag);
public:
      static cocos2d::Scene* createScene();
      virtual bool init();

      // �¼��ص�����
      void menuCloseCallback(cocos2d::Ref* scene);
      bool enterGame(Touch* touch, Event* event);

      // ÿ֡���º���
      void update(float delta);

      // implement the "static create()" method manually
      CREATE_FUNC(StartMenu);
};

class SpriteFadeInOut {
public:
      // ʵ���˾���ĵ��뵭��Ч��
      static bool fadeIn(Sprite* sprite, GLbyte rate);
      static bool fadeOut(Sprite* sprite, GLbyte rate);
};


#endif // __HELLOWORLD_SCENE_H__
