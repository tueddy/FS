#include "FS.h"
#include "SD.h"

void setup() {
  const char *root_path = "/";
  Serial.begin(115200);
  while(!Serial){delay(100);}
  Serial.println("getNextFileName() test");

  Serial.println("Initializing SD card");
    Serial.begin(115200);
    //  start SD-card (SPI mode)
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    digitalWrite(12, HIGH);
    digitalWrite(14, HIGH);
    delay(50);

    while (!SD.begin(4)) {   
        Serial.println("Card Mount Failed");
        return;
    }
    Serial.println("SD mounted");

  Serial.print("opening root: \"");
  Serial.print(root_path);
  Serial.println("\"");
  File root = SD.open(root_path);
  if(root == NULL){
    Serial.println("Failed to open SD; Halt!");
    while(1) delay(1000);
  }

  Serial.println("Test reading speed with new getNextFileName");
  String filename;
  //Return true if have next file, false if not
  unsigned long startTime = millis();
  int folderCnt = 0;
  filename = root.getNextFileName();
  while (filename != "") {
    //Serial.println(filename);
    ++folderCnt;
   filename = root.getNextFileName();
  }
  unsigned long endTime = millis();
  Serial.print("getNextFileName(), done reading root-directory ");
  Serial.print(folderCnt);
  Serial.print(" elemts in ");
  Serial.print(endTime - startTime);
  Serial.print(" ms = ");
  Serial.print((float)(endTime - startTime)/folderCnt);
  Serial.println(" ms/folder");

//////////////////////////////////////////////////
  Serial.println("Test reading speed with old openNextFile");
  folderCnt = 0;
  root = SD.open(root_path);
  if(root == NULL){
    Serial.println("Failed to open SD; Halt!");
    while(1) delay(1000);
  }

  File file = root.openNextFile();
  startTime = millis();
  while(file){
    if(file.isDirectory()){
     }
    ++folderCnt;
    //Serial.println(file.path());
    file = root.openNextFile();
  }
  endTime = millis();
  Serial.print("openNextFile(), done reading root-directory ");
  Serial.print(folderCnt);
  Serial.print(" elements in ");
  Serial.print(endTime - startTime);
  Serial.print(" ms = ");
  Serial.print((float)(endTime - startTime)/folderCnt);
  Serial.println(" ms/elements");

  while(1) delay(1000);
}

void loop() {
}