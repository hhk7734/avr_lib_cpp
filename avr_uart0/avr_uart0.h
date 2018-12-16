/**
 * @file avr_uart0.h
 * @author Hyeon-ki, Hong (hhk7734@gmail.com)
 * @brief UART0 통신
 */

#ifndef _AVR_UART0_H_
#define _AVR_UART0_H_

#include <avr/io.h>

#include "avr_uart_basic.h"

#define LOT_UART_TX_BUF_SIZE 64
#define LOT_UART_RX_BUF_SIZE 64

class LOT_uart0 : public LOT_uart_basic
{
public:
    LOT_uart0() : LOT_uart_basic(UCSR0A,UCSR0B,UCSR0C,UBRR0H,UBRR0L,UDR0) {}
    
    virtual void rx_isr(void);
    virtual void udre_isr(void);

    virtual void setup(const uint32_t baud_rate);
    virtual uint8_t receive(uint8_t &one_byte);
    virtual void transmit(const uint8_t data);

    using LOT_uart_basic::receive;
    using LOT_uart_basic::transmit;

private:
    volatile uint8_t tx_buf[LOT_UART_TX_BUF_SIZE];
    volatile uint8_t rx_buf[LOT_UART_RX_BUF_SIZE];
};

extern LOT_uart0 uart0;

#endif // _AVR_UART0_H_