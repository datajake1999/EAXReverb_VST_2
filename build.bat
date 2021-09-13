@ECHO OFF
set path="C:\Program Files\7-Zip";"C:\Program Files\Inno Setup 5"
call "c:\program files\microsoft visual studio 8\vc\bin\vcvars32.bat"
call "C:\program files\Microsoft Platform SDK\SetEnv.Cmd" /SRV32 /RETAIL
cl -c /I ".\include" /I ".\VST2_SDK" src\*.cpp VST2_SDK\public.sdk\source\vst2.x\*.cpp
link *.obj bufferoverflowU.lib kernel32.lib user32.lib /dll /def:".\src\vstplug.def" /OUT:EAXReverb.dll
del *.obj
call "C:\program files\Microsoft Platform SDK\SetEnv.Cmd" /X64 /RETAIL
cl -c /I ".\include" /I ".\VST2_SDK" src\*.cpp VST2_SDK\public.sdk\source\vst2.x\*.cpp
link *.obj bufferoverflowU.lib kernel32.lib user32.lib /dll /def:".\src\vstplug.def" /OUT:EAXReverb_X64.dll
del *.obj
iscc "install.iss"
7z a -tzip output\EAXReverb.zip EAXReverb.dll EAXReverb_X64.dll license.txt readme.md
