//
//  ChapterFifth.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/13.
//
//

#include <stdio.h>
#include "ChapterFifth.h"

USING_NS_CC;

Scene * ChapterFifth::createScene() {
    auto scene = Scene::create();
    auto layer = ChapterFifth::create();
    scene->addChild(layer);
    return scene;
}

bool ChapterFifth::init() {
    
    if (!Layer::init()) {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    //    xiaoRuo = Sprite::create("sprite.png");
    //    xiaoRuo->setPosition(Vec2(50, visibleSize.height/2));
    //    this->addChild(xiaoRuo);
    
    AddFunctionAboutTouchEventSample3();
    
    return true;
}

void ChapterFifth::AddFunctionAboutMoveTo() {
    auto moveTo = MoveTo::create(0.9, Vec2(250, 150));
    xiaoRuo->runAction(moveTo);
}

void ChapterFifth::AddFunctionAboutMoveBy() {
    auto moveBy = MoveBy::create(2, Vec2(250, 150));
    xiaoRuo->runAction(moveBy);
}

void ChapterFifth::AddFunctionAboutScaleTo() {
    auto scaleTo = ScaleTo::create(2.8, 0.4, 1.0);
    xiaoRuo->runAction(scaleTo);
}

void ChapterFifth::AddFunctionAboutScaleBy() {
    auto scaleBy = ScaleBy::create(2.8, 0.4, 1.0);
    xiaoRuo->runAction(scaleBy);
}

void ChapterFifth::AddFunctionAboutBlink() {
    auto blink = Blink::create(3.0, 3);
    xiaoRuo->runAction(blink);
}

void ChapterFifth::AddFunctionAboutBezierTo() {
    
    ccBezierConfig config;
    config.controlPoint_1 = Vec2(100, 0);
    config.controlPoint_2 = Vec2(200, 250);
    config.endPosition = Vec2(300, 50);
    
    auto bezierTo = BezierTo::create(4.0, config);
    xiaoRuo->runAction(bezierTo);
}

void ChapterFifth::AddFunctionAboutBezierBy() {
    ccBezierConfig config;
    config.controlPoint_1 = Vec2(100, 0);
    config.controlPoint_2 = Vec2(200, 250);
    config.endPosition = Vec2(300, 50);
    
    auto bezierBy = BezierBy::create(4.0, config);
    xiaoRuo->runAction(bezierBy);
}

void ChapterFifth::AddFunctionAboutRepeatForever() {
    JumpBy *jup = JumpBy::create(3.0, Vec2(50, 1), 100, 1);
    //    RepeatForever *repeatAction = RepeatForever::create(jup);
    Repeat *repeat = Repeat::create(jup, 3);
    
    xiaoRuo->runAction(repeat);
}

void ChapterFifth::AddFunctionAboutSequenceAndSpawn() {
    MoveBy *moveBy = MoveBy::create(2.2, Vec2(40, 20));
    JumpBy *jumpBy = JumpBy::create(3.0, Vec2(50, 1), 100, 5);
    RotateBy *rotateBy = RotateBy::create(2.5, 220, 10);
    Action *actions = Sequence::create(moveBy,jumpBy,rotateBy, NULL);
    xiaoRuo->runAction(actions);
}

void ChapterFifth::AddFunctionAboutActionCallBack() {
    MoveTo *moveToHome = MoveTo::create(10.0, Vec2(visibleSize.width, visibleSize.height/2));
    auto callbackFunc = [&](){
        backHome();
    };
    CallFunc *callFunc = CallFunc::create(callbackFunc);
    Action *actions = Sequence::create(moveToHome,callFunc, NULL);
    xiaoRuo->runAction(actions);
}

void ChapterFifth::backHome() {
    Label *label = Label::createWithSystemFont("I am home!", "Arial", 35);
    label->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(label);
}

void ChapterFifth::AddFunctionAboutTouchEvent() {
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch *touch, Event *event) {
        Point pos1 = touch->getLocation();
        Point pos2 = touch->getLocationInView();
        Point pos3 = Director::getInstance()->convertToGL(pos2);
        
        log("HelloWorldScene OnTouchBegan! pos1 x = %f, y = %f",pos1.x,pos1.y);
        log("HelloWorldScene OnTouchBegan! pos2 x = %f, y = %f",pos2.x,pos1.y);
        log("HelloWorldScene OnTouchBegan! pos3 x = %f, y = %f",pos3.x,pos1.y);
        
        return true;
    };
    
    listener->onTouchMoved = [](Touch *touch, Event *event) {
        log("HelloWorldScene OnTouchMoved");
    };
    
    listener->onTouchEnded = [](Touch *touch, Event *event){
        log("HelloWorldScene OnTouchEnded");
    };
    
    EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

void ChapterFifth::AddFunctionAboutTouchEventSample2() {
    Sprite *sp1 = Sprite::create("sprite1.png");
    Sprite *sp2 = Sprite::create("sprite2.png");
    
    sp1->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    sp2->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    this->addChild(sp1);
    this->addChild(sp2);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch *touch, Event *event){
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
        
        if (target->getBoundingBox().containsPoint(pos)) {
            target->setOpacity(100);
            return true;
        }
        
        return false;
    };
    
    listener->onTouchEnded = [](Touch *touch, Event *event){
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        target->setOpacity(255);
    };
    
    EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sp1);
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sp2);
    
}

void ChapterFifth::AddFunctionAboutTouchEventSample3() {
    Label * logText1 = Label::createWithSystemFont("", "Arial", 24);
    Label * logText2 = Label::createWithSystemFont("", "Arial", 24);
    Label * logText3 = Label::createWithSystemFont("", "Arial", 24);
    
    logText1->setPosition(Vec2(visibleSize.width/2, 280));
    logText2->setPosition(Vec2(visibleSize.width/2, 200));
    logText3->setPosition(Vec2(visibleSize.width/2, 100));
    
    this->addChild(logText1, 1, 1);
    this->addChild(logText2, 1, 2);
    this->addChild(logText3, 1, 3);
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = [&](const std::vector<Touch*>& touches, Event* event){
        auto logText = (Label *)this->getChildByTag(1);
        int num = int(touches.size());
        logText->setString(Value(num).asString() + " Touches:");
    };
    
    listener->onTouchesMoved = [&](const std::vector<Touch*>& touches, Event* event){
        auto logText = (Label *)this->getChildByTag(2);
        int num = int(touches.size());
        std::string text = Value(num).asString() + " Touches:";
        for (auto &touch :touches) {
            auto location = touch->getLocation();
            text += "[touchID" + Value(touch->getID()).asString() + "],";
        }
        
        logText->setString(text);
    };
    
    listener->onTouchesEnded = [&](const std::vector<Touch*>& touches, Event* event){
        auto logText = (Label *)this->getChildByTag(3);
        int num = int(touches.size());
        logText->setString(Value(num).asString() + "Touches:");
    };
    
    EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}






