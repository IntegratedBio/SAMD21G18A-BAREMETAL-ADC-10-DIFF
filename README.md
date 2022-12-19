# SAMD21G18A-BAREMETAL-ADC-10-DIFF
Arduino Nano 33 IoT [SAMD21G18A] Baremetal ADC 10 Setup, Differential, 16 Bit


Board: Arduino Nano 33 IoT Compatibility: Nano 33's / Zero / MKR1000 / Seeed Studio XIAO or most [SAMD21G18A] mcu's Program: Baremetal ADC Chanel 10 Setup Debugging Hardware: Atmel ICE via soldered SWD pins Sensor Hardwarer: DC Signal Generator Generic CLock 0: 8 MHZ Generic Clock 2: 32 Khz (High Accuracy) Resolution: 16 Bit w/ 32 sample averaging.

ADC SETUP. This code demonstrates how to configure "ADC 10" in differential mode on Pin [D15|A1|PB02] for (+) positive signal and [D14|A0|PA02] for (-) negative signal pin.

The value can be watched and ADC values vary betwen ~340 - 32,700 as dialed with a signal generator from 0 - 2.23 VDC] between A0 and A1.

Variable watch on the buffer and ADC_10_Val
