################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sm/SM_blinking.c \
../src/sm/SM_operating.c \
../src/sm/SM_standby.c \
../src/sm/SM_system.c 

OBJS += \
./src/sm/SM_blinking.o \
./src/sm/SM_operating.o \
./src/sm/SM_standby.o \
./src/sm/SM_system.o 

C_DEPS += \
./src/sm/SM_blinking.d \
./src/sm/SM_operating.d \
./src/sm/SM_standby.d \
./src/sm/SM_system.d 


# Each subdirectory must supply rules for building sources it contributes
src/sm/%.o: ../src/sm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/sm" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/dr" -I"/home/rnsavinelli/Documents/Dev/mcuxpresso/testing/inc/pr" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


