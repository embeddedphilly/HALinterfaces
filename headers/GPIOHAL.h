
/************************************************************************//**
 *
 * \file GPIOHAL.h
 *
 *
 * \brief
 *
 * \note
 *
 * \author gtrotter
 * \date Oct 25, 2015
 *
 ****************************************************************************/

#ifndef _GPIOHAL_H
#define _GPIOHAL_H

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/

/****************************************************************************
 *                     EXPORTED TYPES and DEFINITIONS                       *
 ****************************************************************************/
typedef enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,
} GPIO_PORT;

typedef enum
{
    GPIO_PIN0 = 0x0001,
    GPIO_PIN1 = 0x0002,
    GPIO_PIN2 = 0x0004,
    GPIO_PIN3 = 0x0008,
    GPIO_PIN4 = 0x0010,
    GPIO_PIN5 = 0x0020,
    GPIO_PIN6 = 0x0040,
    GPIO_PIN7 = 0x0080,
} GPIO_PIN;

typedef enum
{
    GPIO_STATUS_SUCCESS,
    GPIO_STATUS_FAILURE = !GPIO_STATUS_SUCCESS,
} GPIO_STATUS;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH = !GPIO_LOW,
} GPIO_VALUE;

typedef enum
{
    INTERRUPT_DISABLED,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_FALLING_EDGE,
    INTERRUPT_ANY_EDGE
} GPIO_INTERRUPT_CONFIG;

typedef enum
{
    INPUT,
    OUTPUT
} GPIO_DIRECTION;

typedef enum
{
    GPIO_INPUT_PULLUP,
    GPIO_INPUT_PULLDOWN,
    GPIO_INPUT_FLOAT,
} GPIO_INPUT_CONFIG;

typedef struct GPIO_HANDLE
{
    GPIO_PORT port;
    GPIO_PIN pin;
} GPIO_HANDLE;

typedef enum
{
    GPIO_OUTPUT_DEFAULT,
} GPIO_OUTPUT_CONFIG;

typedef void (*InterruptCallback)(void *param);

/****************************************************************************
 *                              EXPORTED DATA                               *
 ****************************************************************************/

/****************************************************************************
 *                     EXPORTED FUNCTION DECLARATIONS                       *
 ****************************************************************************/

GPIO_STATUS GPIO_InitInputPin(GPIO_INPUT_CONFIG, GPIO_HANDLE*);
GPIO_STATUS GPIO_InitOutputPin(GPIO_OUTPUT_CONFIG, GPIO_HANDLE*);
GPIO_STATUS GPIO_SetOutput(GPIO_VALUE, GPIO_HANDLE*);
GPIO_VALUE GPIO_GetValue(GPIO_HANDLE*);
GPIO_STATUS GPIO_ConfigureInterrupt(GPIO_INTERRUPT_CONFIG, InterruptCallback,
    void * params, GPIO_HANDLE *);


#endif /* _GPIOHAL_H */

/** \}*/
