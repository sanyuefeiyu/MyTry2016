if not defined NDK_ROOT (
    echo "NDK_ROOT is not defined"
    pause
    exit
)
if not exist "%NDK_ROOT%" (
    echo "NDK_ROOT is not exist"
    pause
    exit
)
echo NDK_ROOT="%NDK_ROOT%"

if exist "%NDK_ROOT%\prebuilt\windows-x86_64" (
    set PREBUILT_PATH=%NDK_ROOT%\prebuilt\windows-x86_64
)
if exist "%NDK_ROOT%\prebuilt\windows" (
    set PREBUILT_PATH=%NDK_ROOT%\prebuilt\windows
)
echo PREBUILT_PATH="%PREBUILT_PATH%"

set MAKE_PATH=%PREBUILT_PATH%\bin\make.exe
echo MAKE_PATH="%MAKE_PATH%"
