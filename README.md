# python-mini-smart-lamp
This is a small project that integrates with an Arduino Pro Micro and Python through serial communication, user can choose any color that he/she wants to turn on the mini smart lamp on. There is a small protocol on Arduino:
- `C` - to set the color and turn it off (just to animate it): `CR:G:B`.
- `1` - to set the color and leave it on: `1R:G:B`.


## Example
See in action [here](https://raw.githubusercontent.com/thiagosanches/python-mini-smart-lamp/main/example.mp4).

![image](https://user-images.githubusercontent.com/5191469/141776322-d5124d6a-f18c-41d6-a5f5-0626e53bb9f3.png)

![image](https://user-images.githubusercontent.com/5191469/141775096-93e85965-4124-4048-867e-dc412129a2c4.png)

## Hardware
- Arduino Pro Micro.
- Addressable LED (WS2811 type).

## Software
- [arduino-mini-smart-lamp.ino](arduino-mini-smart-lamp.ino), it uses the [FastLED](https://github.com/thiagosanches/FastLED) library, you have to install it on your Arduino IDE.
- [python-mini-smart-lamp.py](python-mini-smart-lamp.py)

## Installation
```
git clone https://github.com/thiagosanches/python-mini-smart-lamp.git
```

- Deploy the [arduino-mini-smart-lamp.ino](arduino-mini-smart-lamp.ino) into your Arduino Pro Micro board. Please, pay attention on the `LED_PIN`, you must change it if you choose a different PIN.
- Execute the [python-mini-smart-lamp.py](python-mini-smart-lamp.py), `python python-mini-smart-lamp.py`. The COM port may vary on your computer.
