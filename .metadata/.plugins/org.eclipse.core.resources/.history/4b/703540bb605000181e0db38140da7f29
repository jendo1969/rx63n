################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/dcmotor/i_src/Interrupt_INTC.c \
..\src/dcmotor/i_src/Interrupt_MTU2.c \
..\src/dcmotor/i_src/Interrupt_MTU2_TPU.c \
..\src/dcmotor/i_src/Interrupt_SCI.c \
..\src/dcmotor/i_src/Interrupt_TMR.c 

C_DEPS += \
./src/dcmotor/i_src/Interrupt_INTC.d \
./src/dcmotor/i_src/Interrupt_MTU2.d \
./src/dcmotor/i_src/Interrupt_MTU2_TPU.d \
./src/dcmotor/i_src/Interrupt_SCI.d \
./src/dcmotor/i_src/Interrupt_TMR.d 

OBJS += \
./src/dcmotor/i_src/Interrupt_INTC.obj \
./src/dcmotor/i_src/Interrupt_MTU2.obj \
./src/dcmotor/i_src/Interrupt_MTU2_TPU.obj \
./src/dcmotor/i_src/Interrupt_SCI.obj \
./src/dcmotor/i_src/Interrupt_TMR.obj 


# Each subdirectory must supply rules for building sources it contributes
src/dcmotor/i_src/%.obj: ../src/dcmotor/i_src/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c99   -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c99 -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

