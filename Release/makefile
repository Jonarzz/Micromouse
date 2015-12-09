################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
miganie_dioda.lss \

FLASH_IMAGE += \
miganie_dioda.hex \

EEPROM_IMAGE += \
miganie_dioda.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: miganie_dioda.elf secondary-outputs

# Tool invocations
miganie_dioda.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,miganie_dioda.map -mmcu=atmega128 -o "miganie_dioda.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

miganie_dioda.lss: miganie_dioda.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S miganie_dioda.elf  >"miganie_dioda.lss"
	@echo 'Finished building: $@'
	@echo ' '

miganie_dioda.hex: miganie_dioda.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex miganie_dioda.elf  "miganie_dioda.hex"
	@echo 'Finished building: $@'
	@echo ' '

miganie_dioda.eep: miganie_dioda.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex miganie_dioda.elf  "miganie_dioda.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: miganie_dioda.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 miganie_dioda.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) miganie_dioda.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
