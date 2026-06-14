@echo off
echo 4:

gcc text4.c -o text4.exe
echo input.txt | text4.exe
echo.

echo 16:

gcc text16.c -o text16.exe
echo input.txt | text16.exe
echo.

echo 24:

gcc text24.c -o text24.exe
echo input.txt | text24.exe
echo.

echo 34:

gcc text34.c -o text34.exe
echo input.txt | text34.exe
echo.
pause
