# APMTool
## What is this?
This tool allows you to obtain, enable and disable your hard disk drive APM configuration from a single cmd command on Windows. It also list all disk drives and shows their temperatures.

## How to use
You need to run it as administrator (it's the only way to retrieve hard disk information) You can run it with 0-2 integer parameters
* **APMTool.exe**: shows usage, and list all disk drives, their indexes, and temperatures.
* **APMTool.exe idx**: shows APM config for drive at index idx
* **APMTool.exe idx 0**: disables APM for drive at index idx
* **APMTool.exe idx 1-254**: enables APM for drive at index idx

You can run it from cmd, or create LNK shortcuts to execute your APM configurations.

## How it works?
This tool uses the core of [Crystal Disk Info](https://github.com/hiyohiyo/CrystalDiskInfo/tree/142956298060b0b71223384730947d9223d7db8a) (MIT License). Many people has Crystal Disk just for changing APM, and this tool simplifies the process.

## Requirements to run
* Windows 7 or later
* Intel 32/64bit processor
* Administrator rights
* A Hard Drive (that was obvious)

## Requirements to compile
* Visual Studio Version 16 (maybe you can make it work on previous versions)
* MFC and ATL for Visual Studio (Needed to compile Crystal Disk Info core)

## What else can be done with this project?
Crystal Disk Info core allows you to obtain a lot more of information about your hard drives. This project removed all UI related files from Crystal Disk Info Project, allowing you to use all its power from a simple command line project. You only need to modify *Main.cpp* to make your own disk drive management console app.
