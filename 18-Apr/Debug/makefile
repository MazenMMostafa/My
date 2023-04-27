################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS_Stack/_RTOS/subdir.mk
-include RTOS_Stack/Timer0/subdir.mk
-include RTOS_Stack/GIE/subdir.mk
-include MCAL/Timer/Watchdog/subdir.mk
-include MCAL/Timer/Timer2/T2_FASTPWM/subdir.mk
-include MCAL/Timer/Timer2/T2_CTC/subdir.mk
-include MCAL/Timer/Timer1/subdir.mk
-include MCAL/EXT_INT/INT_2/subdir.mk
-include MCAL/EXT_INT/INT_1/subdir.mk
-include MCAL/EXT_INT/INT_0/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/Communication/UART/subdir.mk
-include MCAL/Communication/SPI/subdir.mk
-include MCAL/ADC/subdir.mk
-include MCAL/subdir.mk
-include HAL/Switch/subdir.mk
-include HAL/SevSegment/subdir.mk
-include HAL/LED_Driver/subdir.mk
-include HAL/LCD_Driver/subdir.mk
-include HAL/Keypad_Driver/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Mar_29.lss \

FLASH_IMAGE += \
Mar_29.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mar_29.elf secondary-outputs

# Tool invocations
Mar_29.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mar_29.map -mmcu=atmega32 -o "Mar_29.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mar_29.lss: Mar_29.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mar_29.elf  >"Mar_29.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mar_29.hex: Mar_29.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mar_29.elf  "Mar_29.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mar_29.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Mar_29.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mar_29.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
