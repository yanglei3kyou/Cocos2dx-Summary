//
//  ChapterSecond.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/9.
//
//

#include "ChapterSecond.h"

USING_NS_CC;

Scene * ChapterSecond::createScene() {
    auto scene = Scene::create();
    auto layer = ChapterSecond::create();
    scene->addChild(layer);
    return scene;
}

bool ChapterSecond::init() {
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(300, 300));
    this->addChild(sprite);
    return true;
}