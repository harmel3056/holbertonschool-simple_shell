#!/bin/bash

echo "/bin/ls /nonexistent_path
exit" | ./hsh
echo "Shell exited with status: $?"

