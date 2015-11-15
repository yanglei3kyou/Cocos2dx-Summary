//
//  ChapterFourth.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/11.
//
//

#include <stdio.h>

#include "ChapterFourth.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::ui;
using namespace cocostudio;


Scene * ChapterFourth::createScene() {
    auto scene = Scene::create();
    auto layer = ChapterFourth::create();
    scene->addChild(layer);
    return scene;
}

bool ChapterFourth::init() {
    if (!Layer::init()) {
        return false;
    }
    
    AddSomeKnowledgeAboutLoadingBar();
    
    return true;
}

void ChapterFourth::AddSomeKnowledgeAboutPlayMusic() {
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("SkyCity.mp3",true);
    //    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(const char *filePath)
}

void ChapterFourth::AddSomeKnowledgeAbout9Sprite() {
//    Scale9Sprite *nineGirl = Scale9Sprite::create("CloseNormal.png");
//    nineGirl->setContentSize(Size(200, 100));
//    nineGirl->setPosition(Vec2(200, 200));
//    this->addChild(nineGirl);
    
    Scale9Sprite * btnNormal = Scale9Sprite::create("CloseNormal.png");
    Scale9Sprite * btnSelected = Scale9Sprite::create("CloseSelected.png");
    
    Label *title = Label::createWithSystemFont("Touch Me!", "Marker Felt", 30);
    
    ControlButton *controlBtn = ControlButton::create(title, btnNormal);
    controlBtn->setBackgroundSpriteForState(btnSelected, Control::State::HIGH_LIGHTED);
    
    controlBtn->setPosition(Vec2(200, 200));
    this->addChild(controlBtn);
    
}

void ChapterFourth::AddSomeKnowledgeAboutCocoStudio() {
    auto rootNode = CSLoader::createNode("Scene.csb");
    
    rootNode->setPosition(Vec2(10, 10));
    this->addChild(rootNode);
    
    
    Button *xiaoRuoBun = rootNode->getChildByName<Button *>("xiaoruoBtn");
    xiaoRuoBun->addTouchEventListener(Widget::ccWidgetTouchCallback(CC_CALLBACK_2(ChapterFourth::onClick,this)));
    
    m_xiaoruoImg = rootNode->getChildByName<ImageView *>("xiaoruoImg");
}

void ChapterFourth::onClick(Ref* psender, cocos2d::ui::Widget::TouchEventType type) {
    
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            if (m_xiaoruoImg->isVisible()) {
                m_xiaoruoImg->setVisible(false);
            } else {
                m_xiaoruoImg->setVisible(true);
            }

            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            break;
            
        default:
            break;
    }
}

void ChapterFourth::AddSomeKnowledgeAboutLoadingBar() {
    auto rootNode = CSLoader::createNode("MoreUI.csb");
    rootNode->setPosition(Vec2(0, 0));
    this->addChild(rootNode);
    
    m_loadingBar = rootNode->getChildByName<LoadingBar *>("hpBar");
    m_loadingBar->addTouchEventListener(Widget::ccWidgetTouchCallback(CC_CALLBACK_2(ChapterFourth::moveLoadingBar, this)));

    
//    m_loadingBar->setPosition(Vec2(200, 200));
//    this->addChild(m_loadingBar);
}


void ChapterFourth::moveLoadingBar(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
    log("Is going!");
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            log("Is Running!");
            m_loadingBar->setPercent(m_loadingBar->getPercent()+1);
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            break;
            
        default:
            break;
    }
}

