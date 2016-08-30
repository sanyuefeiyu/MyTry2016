@echo off
CALL common.bat

echo.
echo start to build project
echo.

%MAKE_PATH%

echo.

set error=%errorlevel%
if %error%==0 (
    echo build project success
) else (
    cmd /cecho [1;31m
    echo build project fail and error code is %error%
    cmd /cecho [0;40m
)

echo.

pause
