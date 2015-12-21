################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/Arduino/arduino-1.5.6-r2/libraries/QUN/QUN.cpp 

CPP_DEPS += \
./Libraries/QUN/QUN.cpp.d 

LINK_OBJ += \
./Libraries/QUN/QUN.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/QUN/QUN.cpp.o: E:/Arduino/arduino-1.5.6-r2/libraries/QUN/QUN.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR    -I"E:\Arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\Arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\eightanaloginputs" -I"E:\Arduino\arduino-1.5.6-r2\libraries\TLC5615" -I"E:\Arduino\arduino-1.5.6-r2\libraries\QUN" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


