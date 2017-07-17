/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

// NRF52840 {PORT,PIN}
const PinDescription g_ADigitalPinMap[] = {
  // D0 - D7
  {1,1},
  {1,2},
  {1,3},
  {1,4},
  {1,5},
  {1,6},
  {1,7},
  {1,8},
  // D8 - D13
  {1,10},
  {1,11},
  {1,12},
  {1,13},
  {1,14},
  {1,15},
  // A0 - A5
  {0,3},
  {0,4},
  {0,28},
  {0,29},
  {0,30},
  {0,31},

  // SDA, SCL
  {0,26},
  {0,27},

  // RX, TX
  {0,8},
  {0,6},
  // AREF
  {0,2},
  //LED 1-4
  {0,13}, //25
  {0,14},
  {0,15},
  {0,16},
  //Buttons 1-4
  {0,11},//29
  {0,12},
  {0,24},
  {0,25}
};
