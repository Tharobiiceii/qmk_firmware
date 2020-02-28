# Build Options

BOOTMAGIC_ENABLE = no # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes # Audio control and System control(+450)
CONSOLE_ENABLE = no # Console for debug(+400)
COMMAND_ENABLE = no # Commands for debug
SLEEP_LED_ENABLE = no # LED breathing
NKRO_ENABLE = yes # USB N-Key Rollover
BACKLIGHT_ENABLE = yes # Backlight
RGBLIGHT_ENABLE = yes # WS2812 RGB underlight
MIDI_ENABLE = no # MIDI controls
UNICODE_ENABLE = no # Unicode
UNICODEMAP_ENABLE = no # More Unicode
BLUETOOTH_ENABLE = no # Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no # Audio output
FAUXCLICKY_ENABLE = no # Buzzer to emulate clicky switches
API_SYSEX_ENABLE = no  # Quantum SYSEX API
KEY_LOCK_ENABLE = no # Key lock
TAP_DANCE_ENABLE = no # Tap Dance

ifndef QUANTUM_DIR
    include ../../../../Makefile
endif
