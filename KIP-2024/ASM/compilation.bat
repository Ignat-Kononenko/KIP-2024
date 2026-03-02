cd /d C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build
call vcvarsall.bat x86
cd /d D:\KIP-2024\KIP-2024\ASM
ml /c /coff /Zi asm.asm
link /OPT:NOREF /DEBUG /SUBSYSTEM:CONSOLE asm.obj /NODEFAULTLIB:library user32.lib
cls
call asm.exe
pause
exit