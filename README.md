node-rcswitch-he
================

Node bindings for the [rcswitch RaspberryPi port](https://github.com/r10r/rcswitch-pi).

## Requirements

* Like the C++ version of rcswitch, [WiringPi must be installed](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) in order to compile.
* Both the data and the power Pins of the 315/433Mhz emitter must be connected to the RPi. Note the number of the WiringPi data Pin. (see http://wiringpi.com/pins/)
* The node command must be run with root access

## Usage

```javascript
var rcswitchhe = require('rc-switch-he'); // Might throw an error if wiring pi init failed (no root)

rcswitchhe.enableTransmit(0); // Use data Pin 0
rcswitchhe.setRemoteCode(12345678); //Set Remote Code you choose for Raspberry
rcswitchhe.switchOn(1); // Switch on the first unit of 10110 (code 1x23x) group
rcswitchhe.switchOff(2); // Switch off the second unit of 11000 (code 12xxx) group
```

## API

### Configuration

#### rcswitchhe.enableTransmit(`pin`)

Enable transmission on the given pin (make it an OUTPUT). Must be called before any other functions.

* `pin` - (Number) data Pin to use following [the WiringPi schema](http://wiringpi.com/pins/)

Return true if `pin` is an integer, false otherwise.

#### rcswitchhe.setRemoteCode(`remoteCode`)

* `remoteCode` - (Number) remote code using by Raspberry Pi to control devices

Return true.

#### rcswitchhe.switchOn(`switch`)

Switch a remote switch on

* `switch` - (Number) switch number

Return true.

#### rcswitchhe.switchOff(`switch`)

Switch a remote switch off

* `switch` - (Number) switch number

Return true.

## Release History

* 0.1.0 Initial release
* 0.1.1 Node cpp correction
* 0.1.2 Change documentation
* 0.1.4 New version using nan
* 0.1.5 Nan bindings
* 0.1.6 Enable transmit
* 0.1.7 SetRemoteCode
* 0.1.7 SetRemoteCode private