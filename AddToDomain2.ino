#include "Keyboard.h"
char cmdstr[] = "cmd";
char sysstr[] = "sysdm.cpl";
#define Debug 1
//GetSchoolVia IP??
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_ENTER       0xB0
#define KEY_ESC         0xB1
#define KEY_CAPS_LOCK   0xC1
#define KEY_LEFT_GUI    0x83
#define KEY_END         0xD5
#define KEY_DELETE      0xD4 
#define KEY_F3          0xC4

void repeatKey(byte key, int num)
{
  for(int i=0;i<num;i++)
  {
    Keyboard.write(key);
    delay(100);
  }
}


int winrun(char* cmd)
{
  Keyboard.write(KEY_LEFT_GUI);
  delay(500);
  Keyboard.print(cmd);
  delay(1000);
  Keyboard.write(KEY_ENTER);
  delay(500);
}



int getSchool()  //Not quite working nslookup isnt a great solution. Schools in Priceville area will use BOE DC 
{
  
  winrun(cmdstr);
  delay(3000);
  Keyboard.print("ipconfig | findstr /i \"IPv4\" > ipfinder.txt");
  delay(500);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("set /p firstline=<ipfinder.txt");
  delay(500);
  Keyboard.write(KEY_ENTER);
  delay(500);
  Keyboard.print("for /f \"tokens=1-8 delims=. \" %a in (\"%firstline%\") do (set octetF=%f)");
  delay(1500);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 0 if %octetF% LSS 8 set svar=BOE");
  Keyboard.write(KEY_ENTER);
  delay(100);
  Keyboard.print("if %octetF% GEQ 8 if %octetF% LSS 16 set svar=BHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 16 if %octetF% LSS 24 set svar=CJHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 24 if %octetF% LSS 32 set svar=DNES");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 32 if %octetF% LSS 40 set svar=DHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 40 if %octetF% LSS 48 set svar=EJHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 48 if %octetF% LSS 56 set svar=FHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 56 if %octetF% LSS 64 set svar=LSJHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 64 if %octetF% LSS 72 set svar=PES");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 72 if %octetF% LSS 80 set svar=PHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 80 if %octetF% LSS 88 set svar=PJHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 88 if %octetF% LSS 96 set svar=SJHS");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 96 if %octetF% LSS 104 set svar=WMES");
  delay(100);
  Keyboard.write(KEY_ENTER);
  Keyboard.print("if %octetF% GEQ 104 if %octetF% LSS 112 set svar=WMHS");
  delay(300);
  Keyboard.write(KEY_ENTER);
  delay(2000);
  Keyboard.print(">schooltemp.txt echo %svar%");
  Keyboard.write(KEY_ENTER);
  Keyboard.print("schooltemp.txt");
  Keyboard.write(KEY_ENTER);
  delay(3000);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_END);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  Keyboard.release(KEY_LEFT_CTRL);
  delay(500);
  
}

int getSerial()
{
  winrun(cmdstr);
  delay(3000);
  Keyboard.print("wmic bios get serialnumber > tag.txt");
  delay(1500);
  Keyboard.write(KEY_ENTER);
  delay(3000);
  Keyboard.print("tag.txt");
  delay(2000);
  Keyboard.write(KEY_ENTER);
  delay(2000);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(200);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_END);
  delay(200);
  Keyboard.release(KEY_LEFT_SHIFT);
  delay(200);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  Keyboard.release(KEY_LEFT_CTRL);
  delay(300);
  winrun(sysstr);
  
  
  
}

int domainConfig()
{
   delay(2000);
  repeatKey(KEY_TAB,2);
  Keyboard.write(KEY_ENTER);
  delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('v');
  Keyboard.release(KEY_LEFT_CTRL); 
  delay(1000);
  //getSchool();
  //delay(500);
  //winrun(sysstr);
  //delay(500);
  repeatKey(KEY_LEFT_ARROW,25);
  delay(1000);
  //Keyboard.press(KEY_LEFT_CTRL);
  //Keyboard.write('v');
  //Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.write('-');
  delay(300);
  repeatKey(KEY_TAB,2);
  Keyboard.write(KEY_UP_ARROW);
  Keyboard.write(KEY_TAB);
  Keyboard.print("morgank12.org");
  delay(500);
  
  

}

void setup() {
  if(Debug) 
    delay(10000);
    
getSerial();
domainConfig();

}
  
  
  
  // put your setup code here, to run once:



void loop() {
  // put your main code here, to run repeatedly:

}
