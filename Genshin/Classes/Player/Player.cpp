#include "Player.h"

bool Player::init()
{
	if (!Node::init())
	{
		return false;
	}
	//��������
	m_body = Sprite::create("me/front.png");
	//��������ӵ��ڵ�
	this->addChild(m_body);

	//���������
	this->scheduleUpdate();

	//�����ʼ�ո��澫��
	//auto follow = Follow::create(m_body);
	//this->runAction(follow);

	//�����¼�����
	auto eventListener = EventListenerKeyboard::create();
	//��������ʱ����
	eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
		{
			switch (keyCode)
			{
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW] = true;
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] = true;
				break;
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_UP_ARROW] = true;
				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_DOWN_ARROW] = true;
				break;
			default:
				break;
			}
		};
	//����̧��ʱ����
	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
		{
			switch (keyCode)
			{
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW] = false;
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] = false;
				break;
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_UP_ARROW] = false;
				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				keyMap[EventKeyboard::KeyCode::KEY_DOWN_ARROW] = false;
				break;
			default:
				break;
			}
		};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);//�Ѽ��������뵽�¼��ַ����У��������������󶨵Ķ�����������ȼ��趨Ϊ��������ȼ�






	return true;
}

void Player::update(float dt)
{
	//ʵ�ְ������ƾ����ƶ�
	auto left = EventKeyboard::KeyCode::KEY_LEFT_ARROW;//���
	auto right = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;//�Ҽ�
	auto up = EventKeyboard::KeyCode::KEY_UP_ARROW;//�ϼ�
	auto down = EventKeyboard::KeyCode::KEY_DOWN_ARROW;//�¼�

	if (keyMap[left])//����������
	{
		if (m_body->getNumberOfRunningActionsByTag(1) == 0)
		{
			m_body->stopAllActions();//ֹͣ���ж���
			//����
			auto animation_left = Animation::create();
			animation_left->setDelayPerUnit(0.2f);//����ÿһ֡��ʱ����
			animation_left->addSpriteFrameWithFile("me/walk_left1.png");//���һ֡
			animation_left->addSpriteFrameWithFile("me/walk_left2.png");//���һ֡
			animation_left->setLoops(-1);//����ѭ��������-1��ʾ����ѭ��
			Animate* animate = Animate::create(animation_left);//����һ������������һ��animation
			animate->setTag(1);//���ñ�ǩ
			m_body->runAction(animate);//ִ���������
		}
		this->setPositionX(this->getPositionX() - 5);//�����ƶ�10������
	}
	if (keyMap[right])//����Ҽ�����
	{
		if (m_body->getNumberOfRunningActionsByTag(2) == 0)
		{
			m_body->stopAllActions();//ֹͣ���ж���
			//����
			auto animation_right = Animation::create();
			animation_right->setDelayPerUnit(0.2f);//����ÿһ֡��ʱ����
			animation_right->addSpriteFrameWithFile("me/walk_right1.png");//���һ֡
			animation_right->addSpriteFrameWithFile("me/walk_right2.png");//���һ֡
			animation_right->setLoops(-1);//����ѭ��������-1��ʾ����ѭ��
			Animate* animate = Animate::create(animation_right);//����һ������������һ��animation
			animate->setTag(2);//���ñ�ǩ
			m_body->runAction(animate);//ִ���������
		}
		this->setPositionX(this->getPositionX() + 5);//�����ƶ�10������
	}
	if (keyMap[up])//����ϼ�����
	{
		if (m_body->getNumberOfRunningActionsByTag(3) == 0)
		{
			m_body->stopAllActions();//ֹͣ���ж���
			//����
			auto animation_up = Animation::create();
			animation_up->setDelayPerUnit(0.2f);//����ÿһ֡��ʱ����
			animation_up->addSpriteFrameWithFile("me/walk_back1.png");//���һ֡
			animation_up->addSpriteFrameWithFile("me/walk_back2.png");//���һ֡
			animation_up->setLoops(-1);//����ѭ��������-1��ʾ����ѭ��
			Animate* animate = Animate::create(animation_up);//����һ������������һ��animation
			animate->setTag(3);//���ñ�ǩ
			m_body->runAction(animate);//ִ���������
		}
		this->setPositionY(this->getPositionY() + 5);//�����ƶ�10������
	}
	if (keyMap[down])//����¼�����
	{
		if (m_body->getNumberOfRunningActionsByTag(4) == 0)
		{
			m_body->stopAllActions();//ֹͣ���ж���
			//����
			auto animation_down = Animation::create();
			animation_down->setDelayPerUnit(0.2f);//����ÿһ֡��ʱ����
			animation_down->addSpriteFrameWithFile("me/walk_front1.png");//���һ֡
			animation_down->addSpriteFrameWithFile("me/walk_front2.png");//���һ֡
			animation_down->setLoops(-1);//����ѭ��������-1��ʾ����ѭ��
			Animate* animate = Animate::create(animation_down);//����һ������������һ��animation
			animate->setTag(4);//���ñ�ǩ
			m_body->runAction(animate);//ִ���������
		}
		this->setPositionY(this->getPositionY() - 5);//�����ƶ�10������
	}
}