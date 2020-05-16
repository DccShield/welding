//--------------------------------------------------------------------------------
// Weldinf light
// [welding.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include <Arduino.h>
#include "SeqLight.h"
  
unsigned long PreviosTime = 0;
unsigned long PreviosTime2 = 0;

// ArduinoNANOのデジタル出力 3,4,5,6,9,10,11 用のオブジェクトを生成
SeqLight LedA = SeqLight(3,1);
SeqLight LedB = SeqLight(5,2);
SeqLight LedC = SeqLight(6,3);
SeqLight LedD = SeqLight(9,4);
SeqLight LedE = SeqLight(10,5);
SeqLight LedF = SeqLight(11,1);

void setup() {
  Serial.begin(115200);

  PreviosTime = millis();
  PreviosTime2 = PreviosTime;
//  LedA.OnOff(ON);
//  LedB.OnOff(ON);
//  LedC.OnOff(ON);
//  LedD.OnOff(ON);
//  LedE.OnOff(ON);
}

void loop() {
  static int sel = 0;
  static int mod = 0;
  static int cnt = 0;
  static int state = 0;
    
  if( (millis() - PreviosTime ) >= 10 ){  // 10:10msec 前回から10ms経過したかチェック
    PreviosTime = millis();
    LedA.stateCheck();
    LedB.stateCheck();
    LedC.stateCheck();
    LedD.stateCheck();
    LedE.stateCheck();
    LedF.stateCheck();

  }
  if( (millis() - PreviosTime2 ) >= 100 ){  // 5000:5000msec 前回から5000ms経過したかチェック
    PreviosTime2 = millis();
              Serial.print("state:");
              Serial.println(state);
    switch(state){
      case 0:
              mod = random(0,7);
              cnt = random(10,30);
              Serial.print(mod);
              Serial.print(",");
              Serial.println(cnt);

              state = 1;
              break;
      case 1:
              switch(mod){
                case 1:
                        LedA.OnOff(ON);
                        break;
                case 2:
                        LedB.OnOff(ON);
                        break;
                case 3:
                        LedC.OnOff(ON);
                        break;
                case 4:
                        LedD.OnOff(ON);
                        break;
                case 5:
                        LedE.OnOff(ON);
                        break;                                                                        
                case 6:
                        LedF.OnOff(ON);
                        break;
                default:
                        break;
              }
              state = 2;
              break;
    case 2:
              cnt --;
              if(cnt<=0){
                switch(mod){
                  case 1:
                        LedA.OnOff(OFF);
                        break;
                  case 2:
                        LedB.OnOff(OFF);
                        break;
                  case 3:
                        LedC.OnOff(OFF);
                        break;
                  case 4:
                        LedD.OnOff(OFF);
                        break;
                  case 5:
                        LedE.OnOff(OFF);
                        break;                                                                        
                  case 6:
                        LedF.OnOff(OFF);
                        break;
                default:
                        break;

                }                
              state = 0;
              }

              break;
          
      default:
              break;
    }
  }
}
