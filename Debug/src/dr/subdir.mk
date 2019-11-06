################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dr/DR_ADC.c \
../src/dr/DR_GPIO.c \
../src/dr/DR_Keyboard.c \
../src/dr/DR_NVIC.c \
../src/dr/DR_PINSEL.c \
../src/dr/DR_PLL.c \
../src/dr/DR_SysTick.c \
../src/dr/DR_UART.c 

OBJS += \
./src/dr/DR_ADC.o \
./src/dr/DR_GPIO.o \
./src/dr/DR_Keyboard.o \
./src/dr/DR_NVIC.o \
./src/dr/DR_PINSEL.o \
./src/dr/DR_PLL.o \
./src/dr/DR_SysTick.o \
./src/dr/DR_UART.o 

C_DEPS += \
./src/dr/DR_ADC.d \
./src/dr/DR_GPIO.d \
./src/dr/DR_Keyboard.d \
./src/dr/DR_NVIC.d \
./src/dr/DR_PINSEL.d \
./src/dr/DR_PLL.d \
./src/dr/DR_SysTick.d \
./src/dr/DR_UART.d 


# Each subdirectory must supply rules for building sources it contributes
src/dr/%.o: ../src/dr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/sm" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/dr" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/pr" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


