################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/Timer2/subdir.mk
-include MCAL/Timer/Timer1/subdir.mk
-include MCAL/Timer/Timer0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/EXT_INT/INT_2/subdir.mk
-include MCAL/EXT_INT/INT_1/subdir.mk
-include MCAL/EXT_INT/INT_0/subdir.mk
-include MCAL/DIO/subdir.mk
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
Timer_Project.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer_Project.elf secondary-outputs

# Tool invocations
Timer_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer_Project.map -mmcu=atmega32 -o "Timer_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer_Project.lss: Timer_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer_Project.elf  >"Timer_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
