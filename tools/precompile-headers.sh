#!/usr/bin/env bash
exec g++ -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/c++/$(g++ -dumpversion)/x86_64-pc-linux-gnu/bits/stdc++.h 
