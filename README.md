![logo](logo.png)
shoddy split keyboard for personal use, after ruining my [chinese split keyboard](http://xahlee.info/kbd/ly092_mini_keyboard.html) I attempted to recreate what I wanted from that, minus all the annoyances.

## features
-  *normal* layout: 
	- no ortho
	- no lack of function row
	- no weird thumbclusters
	- plenty bonus keys to add what you miss
- no case or plate, only M3 holes
- halves are separate keyboards with their own MCU and USB, none of that link cable rubbish 
- regular FULL SIZED USB PORT
- powered by [QMK](https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/k8split)
- (nearly (woops)) identical matrix wiring on both halves, only keymaps differ

## pics
### keyboards
![left](k8split_left.png)
![right](k8split_right.png)
### pcb 
![board](k8split_board.jpg)

## mistakes in rev 0.1
- ground of programming header unconnected on right half \
header isnt needed because mcus come with the dfu usb bootloader
- matrix rows are wired reversed in the right half \
this can be fixed with a workaround in qmk's keymaps, not really a problem
- some component choices (4 pin crystal) and placement could be better for hand soldering

### will these be fixed?
probably not, it was a one off for myself anyway. it's still fully functional.

## ordering
theres an `ORDER` folder in the pcb project, which contains the component list I used. all the other generated files needed for ordering are in `gerber`.

### advice
keep in mind this is a personal board made just for myself, it's more up for reference/show than it is meant for people to actually use it. that said, some advice if you do think about making one:
- the pre mentioned component list is just what I happened to find cheap one night, what you pick shouldnt matter too much as long as the values are right.
- do yourself a favor and get all the smd parts soldered on with your order, they're all on the bottom side as this was originally my intention too. trust me it isnt great fun to do by hand especially the MCU circuitry.
- the tolerances are pretty tight in places so I cant guarentee every pcb manufacturer will put up with it, I personally used jlcpcb, with which they turned out perfect. 
- because this is a caseless/plateless board (unless you cad something up), make sure to get switches with alignment pins to make your life easier. the ttc silent switches I used did not.
- to keep things easy I recommend a flat profile keycap set like dsa
- the nearly fully smd usb connector is a china find, you can find them on the regular places as "smd usb a female", the right ones should only have one shield pad on either side.
- the 'case' hardware used is a standard M3 standoff set, anything works.
