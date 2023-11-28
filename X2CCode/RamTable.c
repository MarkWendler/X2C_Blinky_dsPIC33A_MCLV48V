/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Date:  2023-11-27 22:30                                                                                            */

/* X2C-Version: 6.4.2980                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#include "RamTable.h"

int16 RamTable_int16[3];

static const int16 RamTable_int16_init[3] = {0,0,0}; 

void initRamTables()
{
    uint16 i;

    for (i = 0; i < 3; i++)
    {
        RamTable_int16[i] = RamTable_int16_init[i];
    }
}
