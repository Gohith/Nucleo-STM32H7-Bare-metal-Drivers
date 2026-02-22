/**
 *  This File shpws how to use the I2C peripheral Library.
 *  I2C INIT, WRITE, READ
 */

 #include<I2C.h>

    I2C_config_t i2c1_cfg = {
        .instance = I2C1,
        .Timing = 0x00C0216C,                   /* Replace with correct TIMINGR */
        .OwnAddress = 0x00,
        .EnableAnalogFilter_bit = 1,
        .ConfigureDigitalFilter = 0,
        .AddressSize_10_bit = 0
    };

int main(void)
{

    // Configure RCC for I2C
    // Configure GPIO Initialization

    I2C_Init(&i2c1_cfg);

    uint8_t ui8tx[] = {0x45, 0x32, 0x45, 034, 0x21};
     // 7 bit address
    uint8_t ui8SlaveAddress[] = {0x00, 0x01, 0x02, 0x1F, 0x0F};    

    // writing to 5 slaves, 5 databytes individually to the register address of 0x10
    for(uint8_t ui8temp = 0; ui8temp < sizeof(ui8tx); ui8temp++){
            I2C_write(&i2c1_cfg, ui8SlaveAddress[ui8temp], 0x10, ui8tx[ui8temp]);
    }

    // Reading from slave 0x50 at register 0x10 memory location
    uint8_t rx = I2C_read(&i2c1_cfg, 0x50, 0x10);

    while (1);
}
