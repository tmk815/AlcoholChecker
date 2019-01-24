#include "GetDrunkAvg.h"

void GetDrunkAvg::setup(){
    getDrunkAvg_image.load("image/GetDrunkAvg.png");

    resultXml.loadFile("result.xml");
    time = resultXml.getValue("time", 0);
    for (int i = 0; i < time; i++) {
        string xmlYear,xmlMonth,xmlDay,xmlBloodAlcoholConcentration; //文字列格納用
        stringstream ss_year,ss_month,ss_day,ss_bloodAlcoholConcentration; //StringStream
        ss_year << "data" << to_string(i) << ":year"; //xmlの指定用文字列を生成
        ss_year >> xmlYear; //書き込み
        year[i] = resultXml.getValue(xmlYear, "0"); //xmlから取得

        ss_month << "data" << to_string(i) << ":month"; //xmlの指定用文字列を生成
        ss_month >> xmlMonth; //書き込み
        month[i] = resultXml.getValue(xmlMonth, "0"); //xmlから取得

        ss_day << "data" << to_string(i) << ":day"; //xmlの指定用文字列を生成
        ss_day >> xmlDay; //書き込み
        day[i] = resultXml.getValue(xmlDay, "0"); //xmlから取得

        ss_bloodAlcoholConcentration << "data" << to_string(i) << ":bloodAlcoholConcentration"; //xmlの指定用文字列を生成
        ss_bloodAlcoholConcentration >> xmlBloodAlcoholConcentration; //書き込み
        bloodAlcoholConcentration[i] = resultXml.getValue(xmlBloodAlcoholConcentration, "0.0"); //xmlから取得

        deadDrunk += std::atof(bloodAlcoholConcentration[i].c_str());
    }
    deadDrunk = deadDrunk/(time+1);
    resultXml.setValue("deadDrunkAvg",deadDrunk);
    resultXml.saveFile("result.xml"); //保存
}


//--------------------------------------------------------------
void GetDrunkAvg::update(){

}

//--------------------------------------------------------------
void GetDrunkAvg::draw(){
    getDrunkAvg_image.draw(0,0, 500*2,720*2);

    ofSetColor(0,0,0);
    for(int i=0;i<time;i++){
        getSharedData().font.drawString(bloodAlcoholConcentration[i], 110, 30 + (i * 100)); // 文字とポジションを指定して描画
    }
    ofSetColor(255,255,255);
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

void GetDrunkAvg::mouseReleased(int x, int y, int button){
    if(y>=60*21){
        if(x>=660 && x<=990){
            resultXml.loadFile("result.xml");
            time = resultXml.getValue("time", 0);
            for (int i = 0; i < time; i++) {
                string xmlYear,xmlMonth,xmlDay,xmlBloodAlcoholConcentration; //文字列格納用
                stringstream ss_year,ss_month,ss_day,ss_bloodAlcoholConcentration; //StringStream
                ss_year << "data" << to_string(i) << ":year"; //xmlの指定用文字列を生成
                ss_year >> xmlYear; //書き込み
                year[i] = resultXml.getValue(xmlYear, "0"); //xmlから取得

                ss_month << "data" << to_string(i) << ":month"; //xmlの指定用文字列を生成
                ss_month >> xmlMonth; //書き込み
                month[i] = resultXml.getValue(xmlMonth, "0"); //xmlから取得

                ss_day << "data" << to_string(i) << ":day"; //xmlの指定用文字列を生成
                ss_day >> xmlDay; //書き込み
                day[i] = resultXml.getValue(xmlDay, "0"); //xmlから取得

                ss_bloodAlcoholConcentration << "data" << to_string(i) << ":bloodAlcoholConcentration"; //xmlの指定用文字列を生成
                ss_bloodAlcoholConcentration >> xmlBloodAlcoholConcentration; //書き込み
                bloodAlcoholConcentration[i] = resultXml.getValue(xmlBloodAlcoholConcentration, "0.0"); //xmlから取得

                deadDrunk += std::atof(bloodAlcoholConcentration[i].c_str());
            }
            deadDrunk = deadDrunk/(time+1);
            resultXml.setValue("deadDrunkAvg",deadDrunk);
            resultXml.saveFile("result.xml"); //保存
        }
    }
}

string GetDrunkAvg::getName(){
    return "GetDrunkAvg";
}
