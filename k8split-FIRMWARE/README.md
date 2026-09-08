# TMK firmware
these are the minimal viable files for the tmk firmware to my best knowledge. attempted to be less horribly verbose in matrix.c implementation than most example boards, using only masks, avoiding needless extra functions etc.

## building/flashing
```
# if not already done, need this to get lufa repo inside tmk_core
git submodule update --init --recursive
# build and flash
sudo make dfu
```

## non stock/genuine chinese atmega32u4s (isp programmer required)
if you thought you'd save a couple bux by buying atmega32u4s from china directly and got some weird bootloader or wrong fuses (like I did). heres what you'll have to suffer through, since I didnt put on an isp header
- solder reset wire to reset button pin
- sclk/mosi/miso of atmega 9/10/11 can be found on left (左) vga port pin 8/9/10 respectively
- flash dfu and or set fuses to sane config, assuming scuffed uno with arduinoisp
```
# flash dfu bootloader, files findable everywhere, also QMK repo
avrdude -c stk500v1 -p m32u4 -P /dev/ttyACM0 -b 19200 -U flash:w:bootloader_atmega32u4_1.0.0.hex:i
# set fuses to 0xFF, 0xD9, 0xF3, this makes the reset button behave to get back into DFU
avrdude -c stk500v1 -p m32u4 -P /dev/ttyACM0 -b 19200 -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF3:m
```
