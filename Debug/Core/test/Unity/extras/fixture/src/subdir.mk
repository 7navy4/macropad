################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/test/Unity/extras/fixture/src/unity_fixture.c 

OBJS += \
./Core/test/Unity/extras/fixture/src/unity_fixture.o 

C_DEPS += \
./Core/test/Unity/extras/fixture/src/unity_fixture.d 


# Each subdirectory must supply rules for building sources it contributes
Core/test/Unity/extras/fixture/src/%.o Core/test/Unity/extras/fixture/src/%.su: ../Core/test/Unity/extras/fixture/src/%.c Core/test/Unity/extras/fixture/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/middleware" -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/test" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-test-2f-Unity-2f-extras-2f-fixture-2f-src

clean-Core-2f-test-2f-Unity-2f-extras-2f-fixture-2f-src:
	-$(RM) ./Core/test/Unity/extras/fixture/src/unity_fixture.d ./Core/test/Unity/extras/fixture/src/unity_fixture.o ./Core/test/Unity/extras/fixture/src/unity_fixture.su

.PHONY: clean-Core-2f-test-2f-Unity-2f-extras-2f-fixture-2f-src

