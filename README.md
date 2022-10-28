# SPI-Library
This library allows you to communicate with SPI devices, with the PIC18F45K22 as the controller device.

## SPI_setting(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
Please find the usage of above constants below:
## Spi_Type
- SPI_MASTER_OSC_DIV4 : To configure MSSP module as SPI Master with a clock of (Oscillator Frequency / 4).
- SPI_MASTER_OSC_DIV16 : To configure MSSP module as SPI Master with a clock of (Oscillator Frequency / 16).
- SPI_MASTER_OSC_DIV64 : To configure MSSP module as SPI Master with a clock of (Oscillator Frequency / 64).
- SPI_MASTER_TMR2 : To configure MSSP module as SPI Master with a clock generated by Timer 2 module.
- SPI_SLAVE_SS_EN : To configure MSSP module as SPI Slave with Slave Select input.
- SPI_SLAVE_SS_DIS : To configure MSSP module as SPI Slave without Slave Select input.
## Spi_Data_Sample
- SPI_DATA_SAMPLE_MIDDLE : Input data is sampled at the middle of data output time.
- SPI_DATA_SAMPLE_END : Input data is sampled at the end of data output time
## Spi_Clock_Idle
- SPI_CLOCK_IDLE_HIGH : Idle clock level is HIGH (1).
- SPI_CLOCK_IDLE_LOW : Idle clock level is LOW (0).
## Spi_Transmit_Edge
- SPI_IDLE_2_ACTIVE : Transmission occurs during transition from Idle to Active clock state.
- SPI_ACTIVE_2_IDLE : Transmission occurs during transition from Active to Idle clock state.
