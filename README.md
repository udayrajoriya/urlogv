# UR Log Viewer
UR Log Viewer is a small command line tool for viewing log files.

## Features
1. View log files.
2. Search for text in your log files.
3. Flag lines that you want to make note of.

## Building from Source
1. Clone this repository.
2. Run "make".
3. Add to PATH.

## Usage
To open a log file
```
urlogv logfile.log
```

## Commands
While inside of URLogV, run the following user commands
### To flag a line:
```
:f <line_number> //Example: f 25
```
### To remove flag from a line:
```
:rf <line_number> //Example: rf 25
```
### To search for text in log file:
```
:s <string_to_search> //Example: s API
```
### To remove search filtering:
```
:sc //Example: sc
```
### To view lines only in a particular range of line numbers:
```
:vr <from_line_number> <to_line_number> //Example: vr 125 135
```
### To view all lines/clear the view range(vr) filter:
```
:va //Example: va
```
### To exit URLogV:
```
:q //Example: q
```