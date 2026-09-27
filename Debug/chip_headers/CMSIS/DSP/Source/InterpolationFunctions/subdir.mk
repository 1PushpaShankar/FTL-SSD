################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.c \
../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.c 

OBJS += \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.o \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.o 

C_DEPS += \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.d \
./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/CMSIS/DSP/Source/InterpolationFunctions/%.o chip_headers/CMSIS/DSP/Source/InterpolationFunctions/%.su chip_headers/CMSIS/DSP/Source/InterpolationFunctions/%.cyclo: ../chip_headers/CMSIS/DSP/Source/InterpolationFunctions/%.c chip_headers/CMSIS/DSP/Source/InterpolationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -DARM_MATH_CM4 -D__FPU_PRESENT -c -I../Inc -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Include" -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration//chip_headers/CMSIS/Device/ST/STM32F4xx/include" -I"../$(ProjDirPath)//Middlewares/Third_Party/FreeRTOS/Source/include" -I"${workspace_loc:/FreeRTOSIntegration/$(ProjDirPath)/Middlewares/Third_PartyFreeRTOS/Source/portable/GCC/ARM_CM4F}" -I/FreeRTOSIntegration/$(ProjDirPath)/chip_headers/CMSIS/DSP/Include/dsp -I"C:/Users/psesd/Documents/Projects/STM32_DSPAdv/workspace_1.19.0/FreeRTOSIntegration/chip_headers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-InterpolationFunctions

clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-InterpolationFunctions:
	-$(RM) ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctions.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/InterpolationFunctionsF16.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.su ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.cyclo ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.d ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.o ./chip_headers/CMSIS/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.su

.PHONY: clean-chip_headers-2f-CMSIS-2f-DSP-2f-Source-2f-InterpolationFunctions

