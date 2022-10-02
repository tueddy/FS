# FS
Enhanced FS for speedup file listing. Tested with Arduino 2.0.5 (PlatformIO-package 5.2.0)

My test SD-card has 80 folders, 1300 files and fileld with 10 GB 
Loading a directory with getNextFile() takes 2000ms
With this patch loading takes only 100ms

see https://github.com/espressif/arduino-esp32/pull/7229
