# TMK firmware
these are the minimal viable files for the tmk firmware to my best knowledge. attempted to be less horribly verbose in matrix.c implementation than most example boards, using only masks, avoiding needless extra functions etc.

## building/flashing
```
# if not already done, need this to get lufa repo inside tmk_core
git submodule update --init --recursive
# build and flash
make dfu
```
