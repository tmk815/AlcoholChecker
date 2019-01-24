#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxState.h"
#include "SharedData.h"
#include "ofxXmlSettings.h"

class GetDrunkAvg : public itg::ofxState<SharedData>{ //ofxStateを継承{

public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    string getName(); //状態の名前を返す関数

private:
    ofImage getDrunkAvg_image; //全体画像
    ofxXmlSettings resultXml; //XMLの設定用
    int time;
    string year[255],month[255],day[255];
    string bloodAlcoholConcentration[255];
    double deadDrunk=0.0;
};
