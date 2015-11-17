//
//  CSiTollagteScene.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#include "CSiTollagteScene.h"
#include "CSiMonsterManager.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::ui;
using namespace cocostudio;

Scene * CSiTollgateScene::createScene() {
    auto scene = Scene::create();
    auto layer = CSiTollgateScene::create();
    scene->addChild(layer);
    return scene;
}

bool CSiTollgateScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
//    visibleSize = Size(568, 320);
    
    Sprite * titleSprite = Sprite::create("title.png");
    titleSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height-30));
    this->addChild(titleSprite,2);
    
    m_player = CSiPlayer::create();
    m_player->bindSprite(Sprite::create("sprite.png"));
    m_player->setPosition(Vec2(90, 50));
    this->addChild(m_player, 3);
    
    
    loadUI();
    
//    initBG();

    
    this->scheduleUpdate();
    
    CSiMonsterManager *monsterMgr = CSiMonsterManager::create();
    monsterMgr->bindPlayer(m_player);
    this->addChild(monsterMgr, 4);
    
    return true;
}

void CSiTollgateScene::update(float dt) {
    int posX1 = m_bgSprite1->getPositionX();
    int posX2 = m_bgSprite2->getPositionX();
    
//    log("x1 = %d \n x2 = %d",posX1,posX2);
    
    int iSpeed = 1;
    
    posX1 -= iSpeed;
    posX2 -= iSpeed;
    
    Size mapSize = m_bgSprite1->getContentSize();
    
    if (posX1 <= -mapSize.width/2) {
        posX1 = mapSize.width + mapSize.width/2;
    }
    
    if (posX2 <= -mapSize.width/2) {
        posX2 = mapSize.width + mapSize.width/2;
    }
    
    m_bgSprite1->setPositionX(posX1);
    m_bgSprite2->setPositionX(posX2);
    
    m_iScore += 1;
    m_scoreLab->setString(Value(m_iScore).asString());
    m_hpBar->setPercent(m_player->getiHP() / 1000.0 * 100);
}

void CSiTollgateScene::initBG() {
    m_bgSprite1 = Sprite::create("tollgateBG.jpg");
    m_bgSprite1->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(m_bgSprite1, 0);
    
    m_bgSprite2 = Sprite::create("tollgateBG.jpg");
    m_bgSprite2->setPosition(Vec2(visibleSize.width+visibleSize.width/2, visibleSize.height/2));
    m_bgSprite2->setFlippedX(true);
    this->addChild(m_bgSprite2, 0);
    
    log("visibleSize width = %f height = %f",visibleSize.width,visibleSize.height);

    
}

void CSiTollgateScene::loadUI() {
    auto rootNode = CSLoader::createNode("RunnerScene.csb");
    rootNode->setContentSize(visibleSize);
    ui::Helper::doLayout(rootNode);
    this->addChild(rootNode);
    
    Button *jumpBtn = rootNode->getChildByName<Button *>("JumpBtn");
    jumpBtn->addTouchEventListener(Widget::ccWidgetTouchCallback(CC_CALLBACK_2(CSiTollgateScene::jumpEven, this)));
    
    m_scoreLab = rootNode->getChildByName<Text *>("scoreLab");
    Text *textTip = rootNode->getChildByName<Text *>("scoreTip");
    
    textTip->setPosition(Vec2(50, visibleSize.height-50));
    m_scoreLab->setPosition(Vec2(55, visibleSize.height-70));
    
    m_hpBar = rootNode->getChildByName<LoadingBar *>("hpProgress");
    
    m_bgSprite1 = rootNode->getChildByName<Sprite *>("bgImageView");
    m_bgSprite2 = rootNode->getChildByName<Sprite *>("bgImageViewSec");

    Size bgSize = m_bgSprite1->getContentSize();
    
    
    m_bgSprite1->setPositionX(bgSize.width/2);
    m_bgSprite2->setPositionX(bgSize.width/2*3);
}

void CSiTollgateScene::jumpEven(cocos2d::Ref *psender, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
        case Widget::TouchEventType::ENDED:
            m_player->jump();
            break;
        default:
            break;
    }
}