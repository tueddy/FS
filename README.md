# FS
Enhanced FS for speedup file listing. Tested with Arduino 2.0.5 (PlatformIO-package 5.2.0)

My test SD-card has 80 folders, 1300 files and fileid with more than 10 GB of mp3 files.
- Loading one directory level with <code>getNextFile()</code> takes 2000ms
- With this patch loading one directory level using <code>getNextFileName()</code> takes only 100ms

<code>getNextFile()</code> is slow because for even for listing a file object is created. A request for stats for the file/directory is created
<code>getNextFile()</code> only gets the filename/path

see https://github.com/espressif/arduino-esp32/pull/7229
