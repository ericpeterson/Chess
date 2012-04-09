#!/bin/bash

# Installs the appropriate GUI libraries for the CS240 Chess program

set -e
set -u

LIB_GTKMM="libgtkmm-2.4-1c2a libgtkmm-2.4-dbg libgtkmm-2.4-dev libgtkmm-2.4-doc"
LIB_GLADEMM="libglademm-2.4-1c2a libglademm-2.4-dbg libglademm-2.4-dev libglademm-2.4-doc"

sudo apt-get install ${LIB_GTKMM} ${LIB_GLADEMM}
