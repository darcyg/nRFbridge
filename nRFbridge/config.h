/*
 * config.h
 *
 * Project: nRFbridge
 * Copyright (c) 2014 Shelby Merrick
 * http://www.forkineye.com
 *
 *  This program is provided free for you to use in any way that you wish,
 *  subject to the laws and regulations where you are using it.  Due diligence
 *  is strongly suggested before using this code.  Please give credit where due.
 *
 *  The Author makes no warranty of any kind, express or implied, with regard
 *  to this program or the documentation contained in this document.  The
 *  Author shall not be liable in any event for incidental or consequential
 *  damages in connection with, or arising out of, the furnishing, performance
 *  or use of these programs.
 *
 */ 

#ifndef CONFIG_H_
#define CONFIG_H_

/*************************************************/
/* USER Defined Defaults                         */
/*************************************************/
//TODO: Add error checking and status LED feedback for verification of these values
#define NRF_CHANNEL     100             /* default nRF channel */
#define NRF_RATE        XNRF_250KBPS    /* default nRF data rate */
#define RS485_BAUDRATE  115200          /* default RS485 baudrate for Renard and passthru */
#define CONFIG_BAUDRATE 57600           /* default RS485 baudrate for configuration mode - non-configurable at runtime */

/*************************************************/
/* SYSTEM Definitions - DO NOT CHANGE            */
/*************************************************/

/* Set our clock define so delay functions are happy */
#define F_CPU   32000000UL

/* XNRF24L01 Config */
#define NRF_CHANNEL 100             /* default nRF channel */
#define NRF_RATE    XNRF_250KBPS    /* default nRF data rate */
#define ADDR_P0     0xF0F0F0F0E1LL  /* default Pipe 0 address */
#define ADDR_P1     0xF0F0F0F0D2LL  /* default Pipe 1 address */
#define NRF_CBITS   0b00111100      /* default configuration bits - 2 byte CRC, RX_DR enabled */
/*                    ^^^^^^^^
 *                    ||||||||_____ PRIM_RX - RX/TX control
 *                    |||||||______ PWR_UP - Power control         
 *                    ||||||_______ CRCO - CRC encoding scheme; '0' - 1 byte, '1' - 2 bytes
 *                    |||||________ EN_CRC - Enable CRC
 *                    ||||_________ MASK_MAX_RT - Reflect max retry on IRQ pin - '0' to enable
 *                    |||__________ MASK_TX_DS - Reflect TX data sent on IRQ pin - '0' to enable
 *                    ||___________ MASK_RX_DR - Reflect RX data received on IRQ pin - '0' to enable
 *                    |____________ RESERVED - Only '0' allowed
 */

/* RingBuffer Config */
#define RINGBUFFER
#define BUFFER_SIZE     255

/* DMX */
#define DMX_BAUDRATE    250000

/* Bridge Modes */
typedef enum {
    MODE_CONFIG,
    MODE_RENARD,
    MODE_DMX,
    MODE_RS485
} bridge_mode_t;

/* RF Protocols */
typedef enum {
    RFPROTO_RFSCv03
} rf_proto_t;

/* RFShowControl v0.3 Protocol */
#define RFSC_FRAME  30  /* Offset for FRAME byte in RFSC Protocol */
#define RFSC_CMD    31  /* Offset for COMMAND byte - proposed */


#endif /* CONFIG_H_ */