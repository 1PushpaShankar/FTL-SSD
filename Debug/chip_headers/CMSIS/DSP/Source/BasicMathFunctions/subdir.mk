################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.c \
../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.c 

OBJS += \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.o \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.o 

C_DEPS += \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.d \
./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/CMSIS/DSP/Source/BasicMathFunctions/%.o chip_headers/CMSIS/DSP/Source/BasicMathFunctions/%.su chip_headers/CMSIS/DSP/Source/BasicMathFunctions/%.cyclo: ../chip_headers/CMSIS/DSP/Source/BasicMathFunctions/%.c chip_headers/CMSIS/DSP/Source/BasicMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -DARM_MATH_CM4 -D__FPU_PRESENT -c -I../Inc -I"C:/Users/psesd/Documents/Projects/FTL_SSD//chip_headers/CMSIS/Include" -I"C:/Users/psesd/Documents/Projects/FTL_SSD//chip_headers/CMSIS/Device/ST/STM32F4xx/include" -I"../$(ProjDirPath)//Middlewares/Third_Party/FreeRTOS/Source/include" -I"${workspace_loc:/FreeRTOSIntegration/$(ProjDirPath)/Middlewares/Third_PartyFreeRTOS/Source/portable/GCC/ARM_CM4F}" -I/FreeRTOSIntegration/$(ProjDirPath)/chip_headers/CMSIS/DSP/Include/dsp -I"C:/Users/psesd/Documents/Projects/FTL_SSD/chip_headers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-BasicMathFunctions

clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-BasicMathFunctions:
	-$(RM) ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.su
	-$(RM) ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.su ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.cyclo ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.d ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.o ./chip_headers/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.su

.PHONY: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-BasicMathFunctions

