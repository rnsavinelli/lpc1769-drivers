################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/pr/PR_Keyboard.c \
../src/pr/PR_LEDS.c \
../src/pr/PR_Timers.c \
../src/pr/PR_UART.c 

OBJS += \
./src/pr/PR_Keyboard.o \
./src/pr/PR_LEDS.o \
./src/pr/PR_Timers.o \
./src/pr/PR_UART.o 

C_DEPS += \
./src/pr/PR_Keyboard.d \
./src/pr/PR_LEDS.d \
./src/pr/PR_Timers.d \
./src/pr/PR_UART.d 


# Each subdirectory must supply rules for building sources it contributes
src/pr/%.o: ../src/pr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/sm" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/dr" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/pr" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


