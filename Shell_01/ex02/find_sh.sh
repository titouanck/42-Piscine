#!bin/sh
find . -iname '*.sh' -type f -printf "%f\n" | sed "s/\.sh//"  
