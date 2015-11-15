//
//  ChapterThird.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/11.
//
//

#include <stdio.h>
#include "ChapterThird.h"

USING_NS_CC;

Scene * ChapterThird::createScene() {
    auto scene = Scene::create();
    auto layer = ChapterThird::create();
    
    scene->addChild(layer);
    return scene;
    
}

bool ChapterThird::init() {
    if (!Layer::init()) {
        return false;
    }
    
    visiableSize = Director::getInstance()->getVisibleSize();
    
//    AddSomeLabel(Vec2(300, 200));
//    
//    AddSomeSprite(Vec2(100, 100));
//    
//    AddSomeMenu(Vec2(visiableSize.width/2, visiableSize.height/2));
//    
//    AddSomeKnowledgeAboutValue();
//    
//    AddSomeKnowledgeAboutVector();
    
    AddSomeKnowledgeAboutMap();
    
    return true;
}

void ChapterThird::AddSomeLabel(Vec2 position) {
    Label *label = Label::createWithSystemFont("hello , mutou?", "Arial", 40);
    label->setPosition(position);
    this->addChild(label);
}

void ChapterThird::AddSomeSprite(Vec2 position) {
    Sprite *sprite = Sprite::create("CloseNormal.png");
    sprite->setPosition(position);
    this->addChild(sprite);
}

void ChapterThird::menuCloseCallBack(cocos2d::Ref *psender) {
    log("i am touched!");
}

void ChapterThird::AddSomeMenu(Vec2 position) {
    
    MenuItemImage *pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(ChapterThird::menuCloseCallBack, this));
    Label *label = Label::createWithSystemFont("I am Label Item", "Arial", 30);
    MenuItemLabel *pLabelItem = MenuItemLabel::create(label, CC_CALLBACK_1(ChapterThird::menuCloseCallBack, this));
    
    Menu *menu = Menu::create(pCloseItem,pLabelItem, NULL);
    menu->alignItemsVertically();
    menu->setPosition(position);
    this->addChild(menu);
    
}

void ChapterThird::AddSomeKnowledgeAboutValue() {
    Value valStr = Value("Xiao Ruo is ");
    Value valInt = Value(250);
    
    log("%s%d",valStr.asString().c_str(),valInt.asInt());
}

void ChapterThird::AddSomeKnowledgeAboutVector() {
    Label *label1 = Label::createWithSystemFont("XiaoRuo No.1", "Arial", 30);
    label1->setPosition(Vec2(250, 200));
    
    Label *label2 = Label::createWithSystemFont("XiaoRuo No.2", "Arial", 30);
    label2->setPosition(Vec2(250, 100));
    
    Vector<Label *> vec;
    vec.pushBack(label1);
    vec.pushBack(label2);
    
    for (auto label : vec) {
        this->addChild(label);
    }
    
}

void ChapterThird::AddSomeKnowledgeAboutMap() {
    Map<int, Label *> xiaoRuoMap;
    
    for (int i = 1; i <= 100; i++) {
        std::string name = "XiaoRuoNo."+Value(i).asString();
        
        Label *lab = Label::createWithSystemFont(name.c_str(), "Arial", 30);
        
        xiaoRuoMap.insert(i, lab);
    }
    
    Label *xiaoRuoLab = xiaoRuoMap.at(23);
    xiaoRuoLab->setPosition(Vec2(200, 200));
    this->addChild(xiaoRuoLab);
}