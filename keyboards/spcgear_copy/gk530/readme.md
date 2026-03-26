# Krom Kernel TKL

![GK530 Tournament](https://i.imgur.com/LTxOTMZ.png)

Like the SPCGear GK530 Tournament but with ISO layout. SPCGear's original firmware works too.  
If you change the product name to Kernel it will failed either building or once flashed. That's why it is like this.  

* Keyboard Maintainer: [Linx](https://github.com/Linx-ESP)
* Hardware Supported: SN32F248F


Make example for this keyboard (after setting up your build environment):

    make spcgear_copy/gk530:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Reset by wire**: Using a wire, 1 head to GND hole and other one to Boot pin on MCU
* **Keycode in layout**: Press the key mapped to RESET if it is available
