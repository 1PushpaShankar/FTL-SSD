################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.c \
../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.c 

OBJS += \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.o \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.o 

C_DEPS += \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.d \
./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/%.o chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/%.su chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/%.cyclo: ../chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/%.c chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -DARM_MATH_CM4 -D__FPU_PRESENT -c -I../Inc -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Include" -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Device/ST/STM32F4xx/include" -I"../$(ProjDirPath)//Middlewares/Third_Party/FreeRTOS/Source/include" -I"${workspace_loc:/FreeRTOSIntegration/$(ProjDirPath)/Middlewares/Third_PartyFreeRTOS/Source/portable/GCC/ARM_CM4F}" -I/FreeRTOSIntegration/$(ProjDirPath)/chip_headers/CMSIS/DSP/Include/dsp -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration/chip_headers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-QuaternionMathFunctions

clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-QuaternionMathFunctions:
	-$(RM) ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/QuaternionMathFunctions.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.su ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.cyclo ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.d ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.o ./chip_headers/CMSIS/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.su

.PHONY: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-QuaternionMathFunctions

