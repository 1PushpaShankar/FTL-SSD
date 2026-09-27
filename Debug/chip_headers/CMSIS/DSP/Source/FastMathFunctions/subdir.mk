################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.c \
../chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.o \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.d \
./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/CMSIS/DSP/Source/FastMathFunctions/%.o chip_headers/CMSIS/DSP/Source/FastMathFunctions/%.su chip_headers/CMSIS/DSP/Source/FastMathFunctions/%.cyclo: ../chip_headers/CMSIS/DSP/Source/FastMathFunctions/%.c chip_headers/CMSIS/DSP/Source/FastMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -DARM_MATH_CM4 -D__FPU_PRESENT -c -I../Inc -I"C:/Users/psesd/Documents/Projects/FTL_SSD//chip_headers/CMSIS/Include" -I"C:/Users/psesd/Documents/Projects/FTL_SSD//chip_headers/CMSIS/Device/ST/STM32F4xx/include" -I"../$(ProjDirPath)//Middlewares/Third_Party/FreeRTOS/Source/include" -I"${workspace_loc:/FreeRTOSIntegration/$(ProjDirPath)/Middlewares/Third_PartyFreeRTOS/Source/portable/GCC/ARM_CM4F}" -I/FreeRTOSIntegration/$(ProjDirPath)/chip_headers/CMSIS/DSP/Include/dsp -I"C:/Users/psesd/Documents/Projects/FTL_SSD/chip_headers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-FastMathFunctions

clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-FastMathFunctions:
	-$(RM) ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.su ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.cyclo ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.d ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.o ./chip_headers/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.su

.PHONY: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-FastMathFunctions

