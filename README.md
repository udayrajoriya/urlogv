# UR Log Viewer
UR Log Viewer is a small command line tool for viewing log files.

## Building from Source
1. Clone this repository.
2. Run "make"

## Installation
To be added

## Usage
To open a log file
```
urlogv logfile.log
```

## Options
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
### To exit URLogV:
```
:q //Example: q
```