# EventwideDE

EventwideDE is a modern, feature-rich desktop environment designed specifically for the Eventwide Linux distribution. It is not recommended to run EventwideDE on any other Linux distribution, as it is tightly integrated with Eventwide Linux system components and user experience.

## Features
- Classy UI 
- Full window management (tiling, stacking, floating)
- Start menu, taskbar, and interactive desktop
- Application launcher, workspace switcher, and system tray
- notifications, clipboard, and settings
- modular and organized


## Build & Install

### Requirements
- GCC (or Clang)
- GTK+ 3 development libraries
- ALSA development libraries (for volume)
- pkg-config

### Build

```sh
make
```

### Install (manual example)

Copy the resulting binaries to your system's bin directory:

```sh
sudo cp eventwidede-* /usr/local/bin/
```

## License
See [LICENSE](LICENSE) for details.

## Authors
EventwideDE is developed and maintained by listedroot.

## Disclaimer
EventwideDE is intended for use only with Eventwide Linux. Running it on other distributions is not supported or recommended.
