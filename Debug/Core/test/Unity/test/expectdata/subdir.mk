################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/test/Unity/test/expectdata/testsample_cmd.c \
../Core/test/Unity/test/expectdata/testsample_def.c \
../Core/test/Unity/test/expectdata/testsample_head1.c \
../Core/test/Unity/test/expectdata/testsample_mock_cmd.c \
../Core/test/Unity/test/expectdata/testsample_mock_def.c \
../Core/test/Unity/test/expectdata/testsample_mock_head1.c \
../Core/test/Unity/test/expectdata/testsample_mock_new1.c \
../Core/test/Unity/test/expectdata/testsample_mock_new2.c \
../Core/test/Unity/test/expectdata/testsample_mock_param.c \
../Core/test/Unity/test/expectdata/testsample_mock_run1.c \
../Core/test/Unity/test/expectdata/testsample_mock_run2.c \
../Core/test/Unity/test/expectdata/testsample_mock_yaml.c \
../Core/test/Unity/test/expectdata/testsample_new1.c \
../Core/test/Unity/test/expectdata/testsample_new2.c \
../Core/test/Unity/test/expectdata/testsample_param.c \
../Core/test/Unity/test/expectdata/testsample_run1.c \
../Core/test/Unity/test/expectdata/testsample_run2.c \
../Core/test/Unity/test/expectdata/testsample_yaml.c 

OBJS += \
./Core/test/Unity/test/expectdata/testsample_cmd.o \
./Core/test/Unity/test/expectdata/testsample_def.o \
./Core/test/Unity/test/expectdata/testsample_head1.o \
./Core/test/Unity/test/expectdata/testsample_mock_cmd.o \
./Core/test/Unity/test/expectdata/testsample_mock_def.o \
./Core/test/Unity/test/expectdata/testsample_mock_head1.o \
./Core/test/Unity/test/expectdata/testsample_mock_new1.o \
./Core/test/Unity/test/expectdata/testsample_mock_new2.o \
./Core/test/Unity/test/expectdata/testsample_mock_param.o \
./Core/test/Unity/test/expectdata/testsample_mock_run1.o \
./Core/test/Unity/test/expectdata/testsample_mock_run2.o \
./Core/test/Unity/test/expectdata/testsample_mock_yaml.o \
./Core/test/Unity/test/expectdata/testsample_new1.o \
./Core/test/Unity/test/expectdata/testsample_new2.o \
./Core/test/Unity/test/expectdata/testsample_param.o \
./Core/test/Unity/test/expectdata/testsample_run1.o \
./Core/test/Unity/test/expectdata/testsample_run2.o \
./Core/test/Unity/test/expectdata/testsample_yaml.o 

C_DEPS += \
./Core/test/Unity/test/expectdata/testsample_cmd.d \
./Core/test/Unity/test/expectdata/testsample_def.d \
./Core/test/Unity/test/expectdata/testsample_head1.d \
./Core/test/Unity/test/expectdata/testsample_mock_cmd.d \
./Core/test/Unity/test/expectdata/testsample_mock_def.d \
./Core/test/Unity/test/expectdata/testsample_mock_head1.d \
./Core/test/Unity/test/expectdata/testsample_mock_new1.d \
./Core/test/Unity/test/expectdata/testsample_mock_new2.d \
./Core/test/Unity/test/expectdata/testsample_mock_param.d \
./Core/test/Unity/test/expectdata/testsample_mock_run1.d \
./Core/test/Unity/test/expectdata/testsample_mock_run2.d \
./Core/test/Unity/test/expectdata/testsample_mock_yaml.d \
./Core/test/Unity/test/expectdata/testsample_new1.d \
./Core/test/Unity/test/expectdata/testsample_new2.d \
./Core/test/Unity/test/expectdata/testsample_param.d \
./Core/test/Unity/test/expectdata/testsample_run1.d \
./Core/test/Unity/test/expectdata/testsample_run2.d \
./Core/test/Unity/test/expectdata/testsample_yaml.d 


# Each subdirectory must supply rules for building sources it contributes
Core/test/Unity/test/expectdata/%.o Core/test/Unity/test/expectdata/%.su: ../Core/test/Unity/test/expectdata/%.c Core/test/Unity/test/expectdata/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/middleware" -I"C:/Users/Furkan/STM32CubeIDE/workspace_1.10.1/macropad/Core/test" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-test-2f-Unity-2f-test-2f-expectdata

clean-Core-2f-test-2f-Unity-2f-test-2f-expectdata:
	-$(RM) ./Core/test/Unity/test/expectdata/testsample_cmd.d ./Core/test/Unity/test/expectdata/testsample_cmd.o ./Core/test/Unity/test/expectdata/testsample_cmd.su ./Core/test/Unity/test/expectdata/testsample_def.d ./Core/test/Unity/test/expectdata/testsample_def.o ./Core/test/Unity/test/expectdata/testsample_def.su ./Core/test/Unity/test/expectdata/testsample_head1.d ./Core/test/Unity/test/expectdata/testsample_head1.o ./Core/test/Unity/test/expectdata/testsample_head1.su ./Core/test/Unity/test/expectdata/testsample_mock_cmd.d ./Core/test/Unity/test/expectdata/testsample_mock_cmd.o ./Core/test/Unity/test/expectdata/testsample_mock_cmd.su ./Core/test/Unity/test/expectdata/testsample_mock_def.d ./Core/test/Unity/test/expectdata/testsample_mock_def.o ./Core/test/Unity/test/expectdata/testsample_mock_def.su ./Core/test/Unity/test/expectdata/testsample_mock_head1.d ./Core/test/Unity/test/expectdata/testsample_mock_head1.o ./Core/test/Unity/test/expectdata/testsample_mock_head1.su ./Core/test/Unity/test/expectdata/testsample_mock_new1.d ./Core/test/Unity/test/expectdata/testsample_mock_new1.o ./Core/test/Unity/test/expectdata/testsample_mock_new1.su ./Core/test/Unity/test/expectdata/testsample_mock_new2.d ./Core/test/Unity/test/expectdata/testsample_mock_new2.o ./Core/test/Unity/test/expectdata/testsample_mock_new2.su ./Core/test/Unity/test/expectdata/testsample_mock_param.d ./Core/test/Unity/test/expectdata/testsample_mock_param.o ./Core/test/Unity/test/expectdata/testsample_mock_param.su ./Core/test/Unity/test/expectdata/testsample_mock_run1.d ./Core/test/Unity/test/expectdata/testsample_mock_run1.o ./Core/test/Unity/test/expectdata/testsample_mock_run1.su ./Core/test/Unity/test/expectdata/testsample_mock_run2.d ./Core/test/Unity/test/expectdata/testsample_mock_run2.o ./Core/test/Unity/test/expectdata/testsample_mock_run2.su ./Core/test/Unity/test/expectdata/testsample_mock_yaml.d ./Core/test/Unity/test/expectdata/testsample_mock_yaml.o ./Core/test/Unity/test/expectdata/testsample_mock_yaml.su ./Core/test/Unity/test/expectdata/testsample_new1.d ./Core/test/Unity/test/expectdata/testsample_new1.o ./Core/test/Unity/test/expectdata/testsample_new1.su ./Core/test/Unity/test/expectdata/testsample_new2.d ./Core/test/Unity/test/expectdata/testsample_new2.o ./Core/test/Unity/test/expectdata/testsample_new2.su ./Core/test/Unity/test/expectdata/testsample_param.d ./Core/test/Unity/test/expectdata/testsample_param.o ./Core/test/Unity/test/expectdata/testsample_param.su ./Core/test/Unity/test/expectdata/testsample_run1.d ./Core/test/Unity/test/expectdata/testsample_run1.o ./Core/test/Unity/test/expectdata/testsample_run1.su ./Core/test/Unity/test/expectdata/testsample_run2.d ./Core/test/Unity/test/expectdata/testsample_run2.o ./Core/test/Unity/test/expectdata/testsample_run2.su ./Core/test/Unity/test/expectdata/testsample_yaml.d ./Core/test/Unity/test/expectdata/testsample_yaml.o ./Core/test/Unity/test/expectdata/testsample_yaml.su

.PHONY: clean-Core-2f-test-2f-Unity-2f-test-2f-expectdata

