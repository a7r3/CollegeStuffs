#!/bin/bash

# Experiment 3
# Display the current logged in user and log name
echo "Username : $(whoami)"

# Experiment 4
# Display current shell, home directory, OS, current path
# current working directory
echo "Current Shell : $SHELL"

echo "Home Directory : $HOME"

echo "Operating System : $(lsb_release -is)"

# Experiment 5
# Display OS version, release number, and kernel version

echo "OS Version : $(lsb_release -rs)"

echo "Kernel Version : $(uname -r)"
