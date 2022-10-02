# FS
Enhanced FS for speedup file listing. Tested with Arduino 2.0.5 (PlatformIO-package 5.2.0)

My test SD-card has 80 folders, 1300 files and fileld with 10 GB 
Loading one directory level with getNextFile() takes 2000ms
With this patch loading one directory level using getNextFileName() takes only 100ms

getNextFile() is slow because for even for listing a file object is created. A request for stats for the file/directory is created
getNextFile() only gets the filename/path

see https://github.com/espressif/arduino-esp32/pull/7229
