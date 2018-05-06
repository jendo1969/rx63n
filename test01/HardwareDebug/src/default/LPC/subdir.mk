################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/default/LPC/R_PG_LPC.c 

C_DEPS += \
./src/default/LPC/R_PG_LPC.d 

OBJS += \
./src/default/LPC/R_PG_LPC.obj 


# Each subdirectory must supply rules for building sources it contributes
src/default/LPC/%.obj: ../src/default/LPC/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c99   -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\test01\src\default","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\test01\src\default\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c99 -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\test01\src\default","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\test01\src\default\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

