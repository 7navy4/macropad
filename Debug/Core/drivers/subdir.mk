################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/drivers/fonts.c \
../Core/drivers/keyboard.c \
../Core/drivers/ssd1306.c 

OBJS += \
./Core/drivers/fonts.o \
./Core/drivers/keyboard.o \
./Core/drivers/ssd1306.o 

C_DEPS += \
./Core/drivers/fonts.d \
./Core/drivers/keyboard.d \
./Core/drivers/ssd1306.d 


# Each subdirectory must supply rules for building sources it contributes
Core/drivers/%.o Core/drivers/%.su: ../Core/drivers/%.c Core/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-drivers

clean-Core-2f-drivers:
	-$(RM) ./Core/drivers/fonts.d ./Core/drivers/fonts.o ./Core/drivers/fonts.su ./Core/drivers/keyboard.d ./Core/drivers/keyboard.o ./Core/drivers/keyboard.su ./Core/drivers/ssd1306.d ./Core/drivers/ssd1306.o ./Core/drivers/ssd1306.su

.PHONY: clean-Core-2f-drivers

