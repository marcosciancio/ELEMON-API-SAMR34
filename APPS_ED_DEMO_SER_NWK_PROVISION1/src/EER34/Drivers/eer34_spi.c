/*
 * Electronica Elemon SA
 *
 * EER43_spi.c
 *
 * Created: 03/12/2019 
 *  Author: mciancio
 */ 

#include "EER34_spi.h"

/** 
 *	@brief	
 *	@param	
 *	@param	
 *	@return	
 */
void EER34_configureSpiMaster(uint32_t baudrate, enum spi_data_order dataOrder , enum spi_transfer_mode ModeSpi)
{
	/* Configure and initialize software device instance of peripheral slave */
	spi_slave_inst_get_config_defaults(&slave_dev_config);

	slave_dev_config.ss_pin = SLAVE_SELECT_PIN;
	spi_attach_slave(&slave, &slave_dev_config);

	/* Configure, initialize and enable SERCOM SPI module */
	spi_get_config_defaults(&config_spi_master);

	/* Data order */
	config_spi_master.data_order = dataOrder;

	/* MODE 0 1 2 3 */
	config_spi_master.transfer_mode = ModeSpi;
	
	/* Baudrate */
	config_spi_master.mode_specific.master.baudrate = baudrate;

	config_spi_master.mux_setting = EXT1_SPI_SERCOM_MUX_SETTING;
	
	/* Configure pad 0 for data in */
	config_spi_master.pinmux_pad0 = EXT1_SPI_SERCOM_PINMUX_PAD0;
	
	/* Configure pad 1 as unused */
	config_spi_master.pinmux_pad1 = PINMUX_UNUSED;
	
	/* Configure pad 2 for data out */
	config_spi_master.pinmux_pad2 = EXT1_SPI_SERCOM_PINMUX_PAD2;
	
	/* Configure pad 3 for SCK */
	config_spi_master.pinmux_pad3 = EXT1_SPI_SERCOM_PINMUX_PAD3;
	
	spi_init(&spi_master_instance, EXT1_SPI_MODULE, &config_spi_master);
	spi_enable(&spi_master_instance);
}
 *	@brief	
 *	@param	
 *	@param	
 *	@return	
 */

	memcpy_ram2ram ( buffer, buffer_spi_rx, size ) ; // Compatibility with Arduino
}

/** 
 *	@brief	
 *	@param	
 *	@param	
 *	@return	
 */

	return buffer[1] ;
}
 *	@brief	
 *	@param	
 *	@param	
 *	@return	
 */

    // Leer desde el slave escribiendo un dato dummy
	//spi_read_buffer_wait ( &spi_master_instance,buffer, BUF_LENGTH, 97 );

	// Escribir y leer un dato
	//spi_transceive_wait  ( &spi_master_instance, 97, buffer_rx);
}*/