################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include chip_headers/CMSIS/DSP/Source/TransformFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/SupportFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/StatisticsFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/MatrixFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/FilteringFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/FastMathFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/ControllerFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/ComplexMathFunctions/subdir.mk
-include chip_headers/CMSIS/DSP/Source/CommonTables/subdir.mk
-include chip_headers/CMSIS/DSP/Source/BasicMathFunctions/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FTL
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FTL.elf \

MAP_FILES += \
FTL.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FTL.list \


# All Target
all: main-build

# Main-build Target
main-build: FTL.elf secondary-outputs

# Tool invocations
FTL.elf FTL.map: $(OBJS) $(USER_OBJS) C:\Users\psesd\Documents\Projects\FTL_SSD\STM32F411RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "FTL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\psesd\Documents\Projects\FTL_SSD\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FTL.map" -Wl,--gc-sections -static -L"C:\Users\psesd\Documents\Projects\STM32_DSPAdv\workspace_1.19.0\FreeRTOSIntegration\chip_headers\CMSIS\Lib\GCC" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FTL.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FTL.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FTL.elf FTL.list FTL.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
