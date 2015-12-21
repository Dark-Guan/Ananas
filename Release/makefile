################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/TLC5615/subdir.mk
-include Libraries/QUN/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
D:/os_china/Ananas/Release/arduino.ar \

ELF += \
Ananas.elf \

EEP += \
Ananas.eep \

FLASH_IMAGE += \
Ananas.hex \


# All Target
all: Ananas

# Tool invocations
Ananas: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-size" -A "D:/os_china/Ananas/Release/Ananas.elf"
	@echo 'Finished building target: $@'
	@echo ' '

D:/os_china/Ananas/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-ar" rcs "D:/os_china/Ananas/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Ananas.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "D:/os_china/Ananas/Release/Ananas.elf"   $(LINK_OBJ) $(AR)  "D:/os_china/Ananas/Release/arduino.ar" "-LD:/os_china/Ananas/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Ananas.eep: $(ELF)
	@echo 'Create eeprom image'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "D:/os_china/Ananas/Release/Ananas.elf" "D:/os_china/Ananas/Release/Ananas.eep"
	@echo 'Finished building: $@'
	@echo ' '

Ananas.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"E:/Arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "D:/os_china/Ananas/Release/Ananas.elf" "D:/os_china/Ananas/Release/Ananas.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELF)$(C++_DEPS)$(AR)$(C_DEPS)$(CC_DEPS)$(FLASH_IMAGE)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(EEP)$(CXX_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Ananas
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
