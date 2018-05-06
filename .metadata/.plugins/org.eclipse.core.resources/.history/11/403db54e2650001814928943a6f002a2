################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/dcmotor/IO/R_PG_IO_PORT.c \
..\src/dcmotor/IO/R_PG_IO_PORT_P5.c \
..\src/dcmotor/IO/R_PG_IO_PORT_PA.c 

C_DEPS += \
./src/dcmotor/IO/R_PG_IO_PORT.d \
./src/dcmotor/IO/R_PG_IO_PORT_P5.d \
./src/dcmotor/IO/R_PG_IO_PORT_PA.d 

OBJS += \
./src/dcmotor/IO/R_PG_IO_PORT.obj \
./src/dcmotor/IO/R_PG_IO_PORT_P5.obj \
./src/dcmotor/IO/R_PG_IO_PORT_PA.obj 


# Each subdirectory must supply rules for building sources it contributes
src/dcmotor/IO/%.obj: ../src/dcmotor/IO/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c99   -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c99 -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_6_0/include","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor","D:\Jiro\workspace\e2studio_5_4_0_015\rx63n\dcmotor\src\dcmotor\i_src"  -debug -nomessage -isa=rxv1 -dbl_size=8 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

