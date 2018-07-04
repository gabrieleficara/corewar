# corewar
Corewar. Including VM, ASM and champion.

The ASM compile a .s file written in assembly language called champion into a .cor binary file.

Once compiled the VM will take the up to 4 .cor files and make them compete until the last one survive. 

Having worked personally on the vm, i will add some detail on the functionalities: 
-dump: interrupt the game after 'number' cycles and show the status of the game.
-n: assign a player number to the next player.
-v: shows all the actions in the game.

asm usage:
./asm [name].s

vm uasge:
./corewar [-n [number]] name1.cor ... [-n [number]] name[n].cor [-dump [number]] [-v] 

for the rule of the game:
https://en.wikipedia.org/wiki/Core_War
