#ifndef __PLAYER_NODE_H__
#define __PLAYER_NODE_H__

#include "cocos2d.h"


USING_NS_CC;

class Player : public Node
{
public:
	virtual bool init();//��ʼ�����������ڳ�������ʱ����
	Sprite* getBody() { return m_body; }//��ȡ����
	//������溯��������һ��������������ʼ�ո���m_body
	void update(float dt);//���º�����ÿ֡����һ��
	CREATE_FUNC(Player);
private:
	Sprite* m_body;//����
	std::map<EventKeyboard::KeyCode, bool> keyMap;//����һ��map�������洢������״̬
};

#endif // __HELLOWORLD_SCENE_H__