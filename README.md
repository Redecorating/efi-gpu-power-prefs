# efi-gpu-power-prefs

Set the boot gpu on dual gpu macbooks to the iGPU. I'm assuming you are using grub, and have installed `gnu-efi`.

1. [Spoof apple-set-os](https://wiki.t2linux.org/guides/hybrid-graphics/#enabling-the-igpu), you do not need to do the nvram thing (this repo does it for you)
2.  Clone the repo and run this:
	```
	make
	make install
	sudo grub-mkconfig -o /boot/grub/grub.cfg
	```
3. In the grub menu, select the "Enable iGPU" option, it will power down and then you can boot again with the igpu.
4. If you boot macOS, you will need to repeat step 3 as it gets reset.


This tool was created by adapting https://github.com/barrykn/big-sur-micropatcher/tree/main/setvars
