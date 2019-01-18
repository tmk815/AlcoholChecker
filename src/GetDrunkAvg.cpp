#include "GetDrunkAvg.h"

void GetDrunkAvg::setup(){
    getDrunkAvg_image.load("image/GetDrunkAvg.png");
}


//--------------------------------------------------------------
void GetDrunkAvg::update(){

}

//--------------------------------------------------------------
void GetDrunkAvg::draw(){
    getDrunkAvg_image.draw(0,0, 500*2,720*2);
}

void GetDrunkAvg::mousePressed(int x, int y, int button){
    if(y>=60*21){
        if(x>=0 && x<=330){
            changeState("Top");
        }else if(x>=330 && x<=660){
            changeState("Intake");
        }
    }
}

string GetDrunkAvg::getName(){
    return "GetDrunkAvg";
}
