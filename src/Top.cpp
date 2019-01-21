#include "Top.h"

void Top::setup(){
    alcohol.loadFile("alcohol.xml");
    top_image.load("image/top.png");

    alcholAmount = alcohol.getValue("data:alcholAmount", 0.0);
}


//--------------------------------------------------------------
void Top::update(){
    bloodAlcoholConcentration = alcholAmount / 50 * 0.7;
}

//--------------------------------------------------------------
void Top::draw(){
    top_image.draw(0,0, 500*2,720*2);

    ofSetColor(0, 0, 0); //色を黒に変更
    getSharedData().font.drawString(std::to_string(bloodAlcoholConcentration)+"mg/ml",350,720);
    ofSetColor(255, 255, 255); //色の初期化

    ofSetColor(255, 0, 0); //色を赤に変更
    if(bloodAlcoholConcentration >= 0.5){
        getSharedData().font.drawString("規則順守ができない",350,500);
    }else if(bloodAlcoholConcentration >= 0.4){
        getSharedData().font.drawString("視線の固定が困難",350,500);
    }else if(bloodAlcoholConcentration >= 0.3){
        getSharedData().font.drawString("ハンドル操作が困難",350,500);
    }else if(bloodAlcoholConcentration >= 0.2){
        getSharedData().font.drawString("反応時間の低下",350,500);
    }else if(bloodAlcoholConcentration >= 0.05){
        getSharedData().font.drawString("注意の集中が困難",350,500);
    }
    ofSetColor(255, 255, 255); //色の初期化
}

void Top::mousePressed(int x, int y, int button){
    if(y>=60*21){
        if(x>=0 && x<=330){
            alcohol.loadFile("alcohol.xml");
            alcholAmount = alcohol.getValue("data:alcholAmount", 0.0);
        }else if(x>=330 && x<=660){
            changeState("Intake");
        }else if(x>=660 && x<=1000){
            changeState("GetDrunkAvg");
        }
    }
}

void Top::mouseReleased(int x, int y, int button){
    if(y>=60*21){
        if(x>=0 && x<=330){
            alcohol.loadFile("alcohol.xml");
            alcholAmount = alcohol.getValue("data:alcholAmount", 0.0);
        }
    }
}

string Top::getName(){
    return "Top";
}
