/**
 *  This File shpws how to use the SPI peripheral Library.
 *  SPI INIT, Configure, Transmit
 */


#include "SPI.h"

static void GPIO_ConfigForSPI(SPI_reg_t *SPIx)
{
    /* Configure SCK/MISO/MOSI pins to AF5/AF6 depending on instance
       - Mode: AF
       - Speed: very high
       - Pull: up/down as needed
       - AF: from datasheet
    */
}

int main(void)
{
    // Enable RCC for SPI
    // SPI config data structure
    SPI_config_t cfg = {
        .instance       = SPI1,
        .baud_prescaler = 2U,              
        .mode           = MODE_0,
        .bit_oder      = MSB_FIRST,
        .data_size      = 5U
    };

    uint8_t tx[5] = {0x9F, 0x00, 0x00, 0x14, 0x54};
    uint8_t rx[5] = {0};

    // INIT and Configuration  
    SPI_Init(&cfg);
    // Transfer and Receive SPI data
    SPI_Transfer(SPI1, tx, rx, 5);
    // Disabling after use 
    SPI_Disable(SPI1);

    return 0;
}
