#!/bin/bash

echo "== Test: command not found =="
echo "badcommand" | ./hsh > /dev/null
echo "Exit status: $?"

echo "== Test: ls command =="
echo "/bin/ls" | ./hsh > /dev/null
echo "Exit status: $?"

echo "== Test: multiple commands (ls then badcommand) =="
printf "/bin/ls\nbadcommand\n" | ./hsh > /dev/null
echo "Exit status (should be 127 from badcommand): $?"
