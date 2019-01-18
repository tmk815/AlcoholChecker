#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxState.h"
#include "SharedData.h"

class Top : public itg::ofxState<SharedData>{ //ofxStateを継承{

public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);

    string getName(); //状態の名前を返す関数

private:
    ofImage top_image; //全体画像
};
