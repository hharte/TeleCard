# TeleCard Reader


# ISO 7816-2 Pinout:


<table>
  <tr>
   <td>1 Vcc (5V)
   </td>
   <td>2 R/W
<p>
R
   </td>
   <td>3 CLOCK
   </td>
   <td>4 RESET
<p>
Not Used
   </td>
  </tr>
  <tr>
   <td>5 GND
   </td>
   <td>6 Vpp (21V)
<p>
Not Used
   </td>
   <td>7 I/O
   </td>
   <td>8 FUSE
<p>
Not Used
   </td>
  </tr>
</table>



## 2x7 Header - Nortel NPS50883-01L5 Card Reader


<table>
  <tr>
   <td>Pin
   </td>
   <td>Description
   </td>
   <td>Notes
   </td>
  </tr>
  <tr>
   <td>1
   </td>
   <td>CLOCK
   </td>
   <td>White
   </td>
  </tr>
  <tr>
   <td>2
   </td>
   <td>Card Switch Common
   </td>
   <td>Common to jam and card switch, tie to GND
   </td>
  </tr>
  <tr>
   <td>3
   </td>
   <td>FUSE
   </td>
   <td>Not used
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>?
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>RESET
   </td>
   <td>Not used
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>?
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>R
   </td>
   <td>Yellow
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>VPP
   </td>
   <td>Not used
   </td>
  </tr>
  <tr>
   <td>9
   </td>
   <td>?
   </td>
   <td>Middle of jam switch.
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>VCC
   </td>
   <td>5V
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>Pull Up
   </td>
   <td>Supply 5V for pull-up to Card Present switch.
   </td>
  </tr>
  <tr>
   <td>12
   </td>
   <td>Card Present
   </td>
   <td>Card Present (5V when card is inserted, 0 when not.)
   </td>
  </tr>
  <tr>
   <td>13
   </td>
   <td>GND
   </td>
   <td>Black
   </td>
  </tr>
  <tr>
   <td>14
   </td>
   <td>I/O
   </td>
   <td>Green
   </td>
  </tr>
</table>



# Building the Arduino ATmega32u4 Adapter

This project uses a [https://www.sparkfun.com/products/15795](https://www.sparkfun.com/products/15795).  Solder a 2x7 pin male header to SparkFun board, with pin 13 of the header connecting to GND on the board, and pin 1 of the header to GPIO7.  For the even numbered header pins, solder four wires.

**_Note:_** Pin numbering on the 2x7 header is with reference to the arrow on the IDC connector housing, not the red stripe on the ribbon cable.  Some card reader assemblies have the red stripe on the wrong side.


<table>
  <tr>
   <td>SparkFun Pro Micro C
   </td>
   <td>2x7 IDC Connector
   </td>
   <td>Description
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>1
   </td>
   <td>Clock
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>3
   </td>
   <td>FUSE (not used)
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>5
   </td>
   <td>RESET (not used)
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>7
   </td>
   <td>R
   </td>
  </tr>
  <tr>
   <td>3
   </td>
   <td>9
   </td>
   <td>Magnetic Stripe Switch (not used)
   </td>
  </tr>
  <tr>
   <td>2
   </td>
   <td>11
   </td>
   <td>Pull Up
   </td>
  </tr>
  <tr>
   <td>GND
   </td>
   <td>13
   </td>
   <td>Ground
   </td>
  </tr>
  <tr>
   <td>GND
   </td>
   <td>2
   </td>
   <td>Ground (for card detect)
   </td>
  </tr>
  <tr>
   <td>VCC
   </td>
   <td>10
   </td>
   <td>+5VDC
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>12
   </td>
   <td>Card Detect
   </td>
  </tr>
  <tr>
   <td>9
   </td>
   <td>14
   </td>
   <td>I/O
   </td>
  </tr>
</table>



## Items Needed


<table>
  <tr>
   <td><a href="https://www.amazon.com/SparkFun-Qwiic-Pro-Micro-microcontroller/dp/B084KPT7MH">SparkFun Pro Micro C</a>
   </td>
   <td>Available at Amazon and DigiKey.
   </td>
  </tr>
  <tr>
   <td><a href="https://www.amazon.com/14-Pin-Straight-Header-Connector-Sockets/dp/B01071U7EA">2x7 Male Header</a>
   </td>
   <td>Or use a break-away header, but be careful of the orientation when plugging in the card reader.
   </td>
  </tr>
  <tr>
   <td>Nortel NPS50883-01L5 Card Reader assembly
   </td>
   <td>Borrow from a Nortel Millennium payphone.
   </td>
  </tr>
</table>


See photos.  Note, I used a 2x10 shrouded header, removed six pins, and slightly enlarged the key, as I did not have a 2x7 shrouded header readily available.

![alt_text](https://raw.githubusercontent.com/hharte/TeleCard/main/images/Telecard_back.jpg "image_tooltip")

![alt_text](https://raw.githubusercontent.com/hharte/TeleCard/main/images/Telecard_front.jpg "image_tooltip")

Load the sketch in the Arduino IDE (tested with v1.8.19) and download to the ATmega 2560 board.  Use the Arduino IDE’s “serial monitor” function at 115200 baud to view the output.

Example run:


```
TeleCard Reader (c) 2022 - Howard M. Harte
https://github.com/hharte/TeleCard

00: 93 AB 6F 02 00 32 0D BA
08: 00 00 77 11 01 FF FF FF
10: FF FF FF FF FF FF FF FF
18: FF FF FF FF FF FF FF FF
20: 0A 00 0A 00 0A 00 8A 80
28: 00 00 00 00 00 00 00 00
30: 00 00 00 00 00 00 00 00
38: 00 00 00 00 00 00 00 00

    Card length: 512 bits
    Card number: 9111000217100012813
       Checksum: 0xBA
Units remaining: 105
  Present value: $5.25

Done reading TeleCard.  Remove and re-insert to read another.
```





# Decoding in Saleae Logic2

If using the Saleae Logic analyzer, the protocol can be decoded with the SPI decoder, decode as follows:


<table>
  <tr>
   <td>Decoder Signal
   </td>
   <td>TeleCard Signal
   </td>
  </tr>
  <tr>
   <td>Clock
   </td>
   <td>CLK
   </td>
  </tr>
  <tr>
   <td>MOSI
   </td>
   <td>(none)
   </td>
  </tr>
  <tr>
   <td>MISO
   </td>
   <td>I/O
   </td>
  </tr>
  <tr>
   <td>Enable
   </td>
   <td>R/W
   </td>
  </tr>
</table>


MSB First (Standard)

8 bits per transfer

Clock is low when inactive (CPOL=0)

Data is valid on clock leading edge (CPHA=0)

Enable line is active low (standard)




# Decoded Cards


<table>
  <tr>
   <td>Use
   </td>
   <td>Byte
   </td>
   <td>USW (full)
<p>
$5.25
   </td>
   <td>USW5 $1.20 left
   </td>
   <td>USW5
<p>
Minn
<p>
Full
   </td>
   <td>GTE
<p>
$10.00USD
   </td>
   <td>Bell
<p>
$10CDN
   </td>
   <td>PTT
<p>
10Nlg
<p>
Ned
   </td>
   <td>Dutch
<p>
2-1/2G
   </td>
  </tr>
  <tr>
   <td>Year
   </td>
   <td>
   </td>
   <td>1994
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>1
   </td>
   <td>0x93
   </td>
   <td>0x93
   </td>
   <td>0x98
   </td>
   <td>0x10
   </td>
   <td>0x99
   </td>
   <td>0xD8
   </td>
   <td>0xD8
   </td>
  </tr>
  <tr>
   <td>Country
   </td>
   <td>2
   </td>
   <td>0xAB
   </td>
   <td>0xAC
   </td>
   <td>0x35
   </td>
   <td>0x2B
   </td>
   <td>0x28
   </td>
   <td>0x37
   </td>
   <td>0x37
   </td>
  </tr>
  <tr>
   <td rowspan="6" >Issuer Area
   </td>
   <td>3
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0xE3
   </td>
   <td>0x1C
   </td>
   <td>0xFF
   </td>
   <td>0xFF
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x03
   </td>
   <td>0x03
   </td>
   <td>0x1A
   </td>
   <td>0x1A
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>0x00
   </td>
   <td>0x01
   </td>
   <td>0x06
   </td>
   <td>0x00
   </td>
   <td>0x01
   </td>
   <td>0x26
   </td>
   <td>0x86
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>0x32
   </td>
   <td>0xBC
   </td>
   <td>0xA9
   </td>
   <td>0x1F
   </td>
   <td>0x92
   </td>
   <td>0x91
   </td>
   <td>0x89
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>0x0D
   </td>
   <td>0xE1
   </td>
   <td>0x17
   </td>
   <td>0xFE
   </td>
   <td>0xE6
   </td>
   <td>0xCA
   </td>
   <td>0x0C
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>0xBA
   </td>
   <td>0xB7
   </td>
   <td>0xF0
   </td>
   <td>0xF1
   </td>
   <td>0xCA
   </td>
   <td>0x88
   </td>
   <td>0x60
   </td>
  </tr>
  <tr>
   <td rowspan="5" >Counter4096
<p>
512
<p>
64
<p>
8
<p>
1
   </td>
   <td>9
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x11
   </td>
   <td>0x11
   </td>
   <td>0x01
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>0x77
   </td>
   <td>0x00
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x7F
   </td>
   <td>0x07
   </td>
  </tr>
  <tr>
   <td>12
   </td>
   <td>0x11
   </td>
   <td>0x33
   </td>
   <td>0xFF
   </td>
   <td>0x11
   </td>
   <td>0x11
   </td>
   <td>0x1F
   </td>
   <td>0x7F
   </td>
  </tr>
  <tr>
   <td>13
   </td>
   <td>0x01
   </td>
   <td>0xFF
   </td>
   <td>0x0F
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x03
   </td>
  </tr>
  <tr>
   <td>Units remaining
   </td>
   <td>
   </td>
   <td>105
   </td>
   <td>24
   </td>
   <td>100
   </td>
   <td>200
   </td>
   <td>200
   </td>
   <td>1000
   </td>
   <td>250
   </td>
  </tr>
</table>



# 


# Decoded Cards: US West Minneapolis Skyline Series


<table>
  <tr>
   <td>Use
   </td>
   <td>Byte
   </td>
   <td>USW
<p>
Minn
<p>
$5-Full
<p>
USW11
<p>
1/3
   </td>
   <td>USW
<p>
Minn
<p>
$10-Full
<p>
USW11
<p>
2/3
   </td>
   <td>USW
<p>
Minn
<p>
$20-Full
<p>
USW11
<p>
1/3
   </td>
   <td>USW
<p>
AZ XXX
<p>
$1-Full
<p>
USW C
   </td>
   <td>USW
<p>
$20-Full
<p>
USW4
<p>
3/3
   </td>
   <td>USW
<p>
$20-Full
<p>
USW5
<p>
3/3
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Year
   </td>
   <td>
   </td>
   <td>1995
   </td>
   <td>1995
   </td>
   <td>1995
   </td>
   <td>1996
   </td>
   <td>1995
   </td>
   <td>1995
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>1
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x93
   </td>
   <td>0x93
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Country
   </td>
   <td>2
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0xAC
   </td>
   <td>0xAC
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td rowspan="6" >Issuer Area
   </td>
   <td>3
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>0x02
   </td>
   <td>0x03
   </td>
   <td>0x04
   </td>
   <td>0x00
   </td>
   <td>0x04
   </td>
   <td>0x04
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>0x06
   </td>
   <td>0x05
   </td>
   <td>0x04
   </td>
   <td>0x06
   </td>
   <td>0x00
   </td>
   <td>0x02
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>0xA9
   </td>
   <td>0xBA
   </td>
   <td>0xD6
   </td>
   <td>0xEF
   </td>
   <td>0x72
   </td>
   <td>0x53
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>0x17
   </td>
   <td>0xB7
   </td>
   <td>0x38
   </td>
   <td>0x05
   </td>
   <td>0xC0
   </td>
   <td>0xFF
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>0xF0
   </td>
   <td>0x37
   </td>
   <td>0x81
   </td>
   <td>0xB6
   </td>
   <td>0x55
   </td>
   <td>0x37
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td rowspan="5" >Counter4096
<p>
512
<p>
64
<p>
8
<p>
1
   </td>
   <td>9
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>0x00
   </td>
   <td>0x11
   </td>
   <td>0x33
   </td>
   <td>0x00
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0xFF
   </td>
   <td>0x00
   </td>
   <td>0xFF
   </td>
   <td>0xFF
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>12
   </td>
   <td>0xFF
   </td>
   <td>0x11
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>13
   </td>
   <td>0x0F
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x0F
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Units Remaining
   </td>
   <td>
   </td>
   <td>100
   </td>
   <td>200
   </td>
   <td>400
   </td>
   <td>20
   </td>
   <td>400
   </td>
   <td>400
   </td>
   <td>
   </td>
  </tr>
</table>



# 


# Subtracting Money from the TeleCard

Starting with a $5.00 card, and placing several calls, depleting the card to $0.00 balance.


<table>
  <tr>
   <td>Use
   </td>
   <td>Byte
   </td>
   <td>USW5
<p>
Minn
<p>
Full
   </td>
   <td>USW5
<p>
Minn
<p>
$4.50
   </td>
   <td>USW5
<p>
Minn
<p>
$4.00
   </td>
   <td>USW5
<p>
Minn
<p>
$3.00
   </td>
   <td>USW5
<p>
Minn
<p>
$2.00
   </td>
   <td>USW5
<p>
Minn
<p>
$1.00
   </td>
   <td>USW5
<p>
Minn
<p>
$0.00
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>1
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
   <td>0x98
   </td>
  </tr>
  <tr>
   <td>Country
   </td>
   <td>2
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
   <td>0x35
   </td>
  </tr>
  <tr>
   <td rowspan="6" >Issuer Area
   </td>
   <td>3
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
   <td>0x6F
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
   <td>0x02
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
   <td>0x06
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
   <td>0xA9
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
   <td>0x17
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
   <td>0xF0
   </td>
  </tr>
  <tr>
   <td rowspan="5" >Counter4096
<p>
512
<p>
64
<p>
8
<p>
1
   </td>
   <td>9
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x33
   </td>
   <td>0x11
   </td>
   <td>0x11
   </td>
   <td>0x00
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>12
   </td>
   <td>0xFF
   </td>
   <td>0x77
   </td>
   <td>0x11
   </td>
   <td>0x77
   </td>
   <td>0x00
   </td>
   <td>0x33
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>13
   </td>
   <td>0x0F
   </td>
   <td>0x03
   </td>
   <td>0xFF
   </td>
   <td>0x0F
   </td>
   <td>0xFF
   </td>
   <td>0x0F
   </td>
   <td>0x00
   </td>
  </tr>
  <tr>
   <td>Units Remaining
   </td>
   <td>
   </td>
   <td>100
   </td>
   <td>90
   </td>
   <td>80
   </td>
   <td>60
   </td>
   <td>40
   </td>
   <td>20
   </td>
   <td>0
   </td>
  </tr>
</table>



# 


# References

[Telecard FAQ](http://laurent.deschamps.free.fr/telecarte/phonecar.htm)

[SparkFun Pro Micro C](https://www.sparkfun.com/products/15795) details

