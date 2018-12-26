
## Project specific files
#SRC =

F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)

# Bootloader
#     This definition is optional, and if your keyboard supports multiple bootloaders of
#     different sizes, comment this out, and the correct address will be loaded 
#     automatically (+60). See bootloader.mk for all options.
ifeq ($(strip $(KEYBOARD)), ms_sculpt/8x8_arm)
  BOOTLOADER = atmel-dfu
endif
ifeq ($(strip $(KEYBOARD)), ms_sculpt/8x8_avr) 
  BOOTLOADER = 
  #define STM32_BOOTLOADER_ADDRESS 0x1FFFC800
endif



# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = yes        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.


USB = /dev/cu.usbmodem14141
#LAYOUTS=8x18
#DEFAULT_FOLDER= handwired/ms_sculpt_mobile/8x18_avr
