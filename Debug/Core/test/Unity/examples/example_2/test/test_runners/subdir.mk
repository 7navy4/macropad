################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.c \
../Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.c \
../Core/test/Unity/examples/example_2/test/test_runners/all_tests.c 

OBJS += \
./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.o \
./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.o \
./Core/test/Unity/examples/example_2/test/test_runners/all_tests.o 

C_DEPS += \
./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.d \
./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.d \
./Core/test/Unity/examples/example_2/test/test_runners/all_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Core/test/Unity/examples/example_2/test/test_runners/%.o Core/test/Unity/examples/example_2/test/test_runners/%.su: ../Core/test/Unity/examples/example_2/test/test_runners/%.c Core/test/Unity/examples/example_2/test/test_runners/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/middleware" -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/test" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-test-2f-Unity-2f-examples-2f-example_2-2f-test-2f-test_runners

clean-Core-2f-test-2f-Unity-2f-examples-2f-example_2-2f-test-2f-test_runners:
	-$(RM) ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.d ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.o ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode2_Runner.su ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.d ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.o ./Core/test/Unity/examples/example_2/test/test_runners/TestProductionCode_Runner.su ./Core/test/Unity/examples/example_2/test/test_runners/all_tests.d ./Core/test/Unity/examples/example_2/test/test_runners/all_tests.o ./Core/test/Unity/examples/example_2/test/test_runners/all_tests.su

.PHONY: clean-Core-2f-test-2f-Unity-2f-examples-2f-example_2-2f-test-2f-test_runners

