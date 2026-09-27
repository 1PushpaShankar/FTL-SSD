################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.c 

OBJS += \
./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.o 

C_DEPS += \
./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/CMSIS/DSP/ComputeLibrary/Source/%.o chip_headers/CMSIS/DSP/ComputeLibrary/Source/%.su chip_headers/CMSIS/DSP/ComputeLibrary/Source/%.cyclo: ../chip_headers/CMSIS/DSP/ComputeLibrary/Source/%.c chip_headers/CMSIS/DSP/ComputeLibrary/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -DARM_MATH_CM4 -D__FPU_PRESENT -c -I../Inc -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Include" -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Device/ST/STM32F4xx/include" -I"../$(ProjDirPath)//Middlewares/Third_Party/FreeRTOS/Source/include" -I"${workspace_loc:/FreeRTOSIntegration/$(ProjDirPath)/Middlewares/Third_PartyFreeRTOS/Source/portable/GCC/ARM_CM4F}" -I/FreeRTOSIntegration/$(ProjDirPath)/chip_headers/CMSIS/DSP/Include/dsp -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration/chip_headers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-CMSIS-2f-DSP-2f-ComputeLibrary-2f-Source

clean-chip_headers-2f-CMSIS-2f-DSP-2f-ComputeLibrary-2f-Source:
	-$(RM) ./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.cyclo ./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.d ./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.o ./chip_headers/CMSIS/DSP/ComputeLibrary/Source/arm_cl_tables.su

.PHONY: clean-chip_headers-2f-CMSIS-2f-DSP-2f-ComputeLibrary-2f-Source

