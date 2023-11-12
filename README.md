# CF Notifications CPP
Receive a notification (Windows Only) whenever your friend submits a task to codeforces!

# Usage
- Download the latest release folder
- make a `friends.txt` in the same folder in CSV format (',' as delimeter)
- run `meow.exe` from the explorer or a shell (there are no logs, so it's the same from both)

# Build Instructions
- Install cmake, make and mingw-w64 (gcc 10 or higher) for windows
- `git clone --recursive https://github.com/theSoberSobber/CF-Notif-CPP.git`
- `cd CF-Notif-CPP`
- `cmake . -G "Unix Makefiles"`
- `make`
